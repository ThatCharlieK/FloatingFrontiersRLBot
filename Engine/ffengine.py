"""
Python wrapper around the C engine (build/libffengine.dylib, see src/ffapi.h).

Runs a batch of B games. Every call works on all B games at once.

    env = FFEngine(n_games=64, seed=0)
    obs = env.observe()                  # board, hand, legal actions of every game
    rewards, dones, final_scores = env.step(action_idx)   # one action index per game
    obs = env.observe()                  # next observation
    ...

Each game's real rows are the first n_* rows of its slice, e.g. game i's legal actions are
obs.actions[i, :obs.n_actions[i]]. Everything past the count is junk.

The arrays are reused: every observe() overwrites them. Copy what you want to keep
(e.g. obs.actions[i, :n].copy()) before calling observe() again.

A game that ends during step() is restarted right away (dones[i] is True and
final_scores[i] is the ended game's score), so the next observe() shows a fresh game in that slot.

Rebuild the library after changing the C code: `make` in Engine/.
"""

import ctypes
from dataclasses import dataclass
from pathlib import Path

import numpy as np

_LIB_PATH = Path(__file__).resolve().parent / "build" / "libffengine.dylib"

PLACED_FEATURES = 18  # x, y, z, then grid cell bits 1-15 (6 faces x 2 bits, 3 block type bits)
HAND_FEATURES = 1     # gp_id
ACTION_FEATURES = 5   # gp_id, x, y, z, rot
GRID_CENTER = 500     # grid coord where the city starts (GX/2 = GY/2 = GZ/2 in src/gamepiece_data.h)


def _ptr(ctype):
    return np.ctypeslib.ndpointer(dtype=ctype, flags="C_CONTIGUOUS")


def _load_lib():
    lib = ctypes.CDLL(str(_LIB_PATH))
    lib.ff_create.argtypes = [ctypes.c_uint32, ctypes.c_uint64]
    lib.ff_create.restype = ctypes.c_void_p
    lib.ff_destroy.argtypes = [ctypes.c_void_p]
    lib.ff_destroy.restype = None
    lib.ff_reset.argtypes = [ctypes.c_void_p]
    lib.ff_reset.restype = None
    lib.ff_observe.argtypes = [
        ctypes.c_void_p,
        _ptr(np.float32), ctypes.c_uint32, _ptr(np.uint32),
        _ptr(np.float32), ctypes.c_uint32, _ptr(np.uint32),
        _ptr(np.float32), ctypes.c_uint32, _ptr(np.uint32),
        _ptr(np.int32),
    ]
    lib.ff_observe.restype = ctypes.c_int32
    lib.ff_step.argtypes = [ctypes.c_void_p, _ptr(np.int32), _ptr(np.int32), _ptr(np.uint8), _ptr(np.int32)]
    lib.ff_step.restype = ctypes.c_int32
    lib.ff_load_game.argtypes = [ctypes.c_void_p, ctypes.c_uint32, _ptr(np.int32), ctypes.c_uint32, _ptr(np.int32), ctypes.c_uint32]
    lib.ff_load_game.restype = ctypes.c_int32
    for name in ("ff_max_actions", "ff_max_hand", "ff_num_gamepieces"):
        getattr(lib, name).argtypes = []
        getattr(lib, name).restype = ctypes.c_uint32
    return lib


_lib = _load_lib()
MAX_ACTIONS = _lib.ff_max_actions()
MAX_HAND = _lib.ff_max_hand()
NUM_GAMEPIECES = _lib.ff_num_gamepieces()


@dataclass
class Observation:
    placed: np.ndarray     # (B, max_placed, 18) float32
    n_placed: np.ndarray   # (B,) uint32
    hand: np.ndarray       # (B, max_hand, 1) float32
    n_hand: np.ndarray     # (B,) uint32
    actions: np.ndarray    # (B, max_actions, 5) float32
    n_actions: np.ndarray  # (B,) uint32
    scores: np.ndarray     # (B,) int32, current score of each game

    def game(self, i: int):
        """
        Read game i out of the last observe(), cut down to its real rows (no junk padding).

        Only reads the arrays, it never asks C for anything new. So after a step() you must
        call env.observe() first, or this still shows the board from before that move.

        :param i: which game in the batch, 0 to B - 1
        :type i: int

        :return: (placed, hand, actions)
            placed: every cube on game i's board, one row per cube:
                [x, y, z, bit1, bit2, ..., bit15]
                x, y, z are raw grid coords (the city starts at 500, 500, 500).
                bits 1-15 are the grid cell's bits as 0/1: 6 faces x 2 bits (+X, -X, +Y, -Y, +Z, -Z),
                then 3 block type bits. The filled bit is left out
            hand: game i's cards, one row per card: [gp_id]. Duplicate cards are separate rows
            actions: game i's legal moves, one row per move: [gp_id, x, y, z, rot].
                x, y, z is the gamepiece origin in raw grid coords, rot is 0-3.
                The row number is the action index you pass to step()
        :rtype: tuple[
            Float[ndarray, "n_placed 18"],
            Float[ndarray, "n_hand 1"],
            Float[ndarray, "n_actions 5"],
        ]
            All float32. These are views into the shared arrays, not copies: the next observe()
            overwrites them, so .copy() anything you want to keep
        """
        return (
            self.placed[i, : self.n_placed[i]],
            self.hand[i, : self.n_hand[i]],
            self.actions[i, : self.n_actions[i]],
        )


class FFEngine:
    def __init__(self, n_games: int, seed: int = 0, max_placed: int = 20000, max_actions: int = MAX_ACTIONS):
        """
        n_games: number of games run side by side (B)
        seed: game i starts with seed + i; restarted games keep counting up from seed + B
        max_placed / max_actions: rows reserved per game. observe() raises if a game outgrows them
        """
        self.n_games = n_games
        self._batch = _lib.ff_create(n_games, seed)

        B = n_games
        self.obs = Observation(
            placed=np.zeros((B, max_placed, PLACED_FEATURES), dtype=np.float32),
            n_placed=np.zeros(B, dtype=np.uint32),
            hand=np.zeros((B, MAX_HAND, HAND_FEATURES), dtype=np.float32),
            n_hand=np.zeros(B, dtype=np.uint32),
            actions=np.zeros((B, max_actions, ACTION_FEATURES), dtype=np.float32),
            n_actions=np.zeros(B, dtype=np.uint32),
            scores=np.zeros(B, dtype=np.int32),
        )
        self._rewards = np.zeros(B, dtype=np.int32)
        self._dones = np.zeros(B, dtype=np.uint8)
        self._final_scores = np.zeros(B, dtype=np.int32)

    def reset(self) -> Observation:
        """Restart every game with fresh seeds and return the new observation."""
        _lib.ff_reset(self._batch)
        return self.observe()

    def observe(self) -> Observation:
        """
        Ask C for the current state of every game and write it into the shared arrays.

        Call it once at the start, and once after every step(). step() changes the games
        but not these arrays.

        :return: the Observation holding all B games. It's the same object every call (self.obs),
            refilled in place, so anything you kept from an earlier call gets overwritten.
            Use obs.game(i) to get one game cut down to its real rows. Its fields are:
                placed:    (B, max_placed, 18) float32. Each game's board cubes; see Observation.game
                n_placed:  (B,) uint32. How many rows of placed[i] are real
                hand:      (B, max_hand, 1) float32. Each game's cards as [gp_id]
                n_hand:    (B,) uint32. How many rows of hand[i] are real
                actions:   (B, max_actions, 5) float32. Each game's legal moves as [gp_id, x, y, z, rot]
                n_actions: (B,) uint32. How many rows of actions[i] are real. Always >= 1
                scores:    (B,) int32. Each game's current score
            Rows past the n_* counts are junk.
        :rtype: Observation

        :raises RuntimeError: a game has more cubes or actions than max_placed / max_actions
        """
        o = self.obs
        truncated = _lib.ff_observe(
            self._batch,
            o.placed, o.placed.shape[1], o.n_placed,
            o.hand, o.hand.shape[1], o.n_hand,
            o.actions, o.actions.shape[1], o.n_actions,
            o.scores,
        )
        if truncated:
            raise RuntimeError("observation buffer too small; raise max_placed / max_actions")
        return o

    def step(self, action_idx):
        """
        Make one move in each of the B games.

        Example: with 3 games, step([4, 0, 12]) plays move 4 of game 0's legal moves,
        move 0 of game 1's, and move 12 of game 2's.

        To see the boards after the move, call observe() again.

        :param action_idx: one number per game: which of that game's legal moves to play.
            The number is a row in the game's actions list from the last observe()
            (the actions returned by obs.game(i)).
        :type action_idx: list, ndarray or tensor of B ints

        :return: (rewards, dones, final_scores), three arrays with one entry per game
            rewards[i]: points game i scored with this move
            dones[i]: True if game i ended with this move. A new game automatically starts
                in its place, so the next observe() shows that new game
            final_scores[i]: game i's total score. If the game just ended, this is its final score
        :rtype: tuple[Int[ndarray, "B"], Bool[ndarray, "B"], Int[ndarray, "B"]]

        :raises ValueError: action_idx doesn't have exactly one number per game
        :raises IndexError: a number in action_idx isn't a valid move for its game (no game moves)
        """
        idx = np.ascontiguousarray(action_idx, dtype=np.int32)
        if idx.shape != (self.n_games,):
            raise ValueError(f"expected {self.n_games} action indices, got shape {idx.shape}")
        if _lib.ff_step(self._batch, idx, self._rewards, self._dones, self._final_scores) != 0:
            raise IndexError("an action index is out of range of that game's legal actions")
        return self._rewards.copy(), self._dones.astype(bool), self._final_scores.copy()

    def load_game(self, game: int, pieces, hand) -> int:
        """
        Put an exact position into game slot `game`, e.g. to mirror a game being played in Unity.
        Call observe() afterwards to see it.

        :param game: which slot, 0 to B - 1
        :param pieces: every piece placed so far, in order, as rows of [gp_id, rot, x, y, z] (raw grid
            coords). Leave out the map's initial gamepiece: every game already starts with it
        :param hand: the gp_ids in hand. These replace whatever hand the engine dealt itself
        :return: the score the engine gives those placements

        :raises ValueError: a piece is out of range, or isn't a legal placement where it is
        """
        p = np.ascontiguousarray(pieces, dtype=np.int32).reshape(-1, 5)
        h = np.ascontiguousarray(hand, dtype=np.int32).reshape(-1)
        result = _lib.ff_load_game(self._batch, game, p, len(p), h, len(h))
        errors = {-1: "game slot out of range", -2: "a piece's gp_id, rot or position is out of range",
                  -3: "a piece isn't a legal placement in the engine (the position doesn't match its rules)"}
        if result < 0:
            raise ValueError(errors.get(result, f"load_game error {result}"))
        return result

    def close(self):
        if self._batch:
            _lib.ff_destroy(self._batch)
            self._batch = None

    def __del__(self):
        self.close()
