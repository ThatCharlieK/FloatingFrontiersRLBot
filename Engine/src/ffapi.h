#ifndef FF_API_H
#define FF_API_H

#include <stdint.h>

/*
Batched API for Python (Engine/ffengine.py loads it with ctypes).

A batch is B independent games. Each call works on all B games at once, so Python
makes one C call per step instead of one per game.

Python allocates every output buffer (NumPy arrays) once and passes pointers in;
C only writes into them, so nothing gets copied back and forth.

Flow:
    ff_create  -> B new games (each with legal actions already enumerated)
    ff_observe -> write every game's board, hand and legal actions into the buffers
    ff_step    -> play one legal action (by index into the last observation) in every game
    ...repeat observe/step...
    ff_destroy

A game that ends during ff_step is restarted right away with a new seed, so every slot always
holds a live game. ff_step flags it in dones and reports its final score.
*/

#define FF_PLACED_FEATURES 18 // x, y, z, then grid cell bits 1-15 (faces and block type) as 0/1. the filled bit is left out
#define FF_HAND_FEATURES 1    // gp_id
#define FF_ACTION_FEATURES 5  // gp_id, x, y, z, rot

typedef struct FFBatch FFBatch;

// B new games, seeded base_seed, base_seed + 1, ...; later restarts keep counting up from there
FFBatch* ff_create(uint32_t n_games, uint64_t base_seed);
void ff_destroy(FFBatch* batch);

// restart every game with fresh seeds (continuing the seed counter)
void ff_reset(FFBatch* batch);

/*
Write the current observation of every game. Game i's rows start at i * max_<buffer>:
    placed:  (B, max_placed, FF_PLACED_FEATURES)   n_placed:  (B,)
    hand:    (B, max_hand, FF_HAND_FEATURES)        n_hand:    (B,)
    actions: (B, max_actions, FF_ACTION_FEATURES)   n_actions: (B,)
    scores:  (B,) current score
Rows past the count are left untouched (junk).
Coordinates are raw grid coordinates (the city starts at the grid center, GX/2, GY/2, GZ/2).
Returns 0, or 1 if some buffer was too small (that game's rows were cut off at max_*).
*/
int32_t ff_observe(FFBatch* batch,
                   float* placed, uint32_t max_placed, uint32_t* n_placed,
                   float* hand, uint32_t max_hand, uint32_t* n_hand,
                   float* actions, uint32_t max_actions, uint32_t* n_actions,
                   int32_t* scores);

/*
Play action_idx[i] (an index into game i's legal actions from the last ff_observe) in every game.
    rewards:      (B,) points that move earned (r_t)
    dones:        (B,) 1 if that game ended with this move. it has already been restarted
    final_scores: (B,) the ended game's final score where dones is 1, otherwise its current score
A game ends when its hand is empty, or when no card in its hand has a legal placement.
Returns 0, or -1 (and steps no game) if any index is out of range.
*/
int32_t ff_step(FFBatch* batch, const int32_t* action_idx,
                int32_t* rewards, uint8_t* dones, int32_t* final_scores);

/*
Load an exact position into game slot `game`, for mirroring a game played somewhere else (the Unity viewer).
    pieces: (n_pieces, 5) int32 rows of [gp_id, rot, x, y, z], in placement order, NOT including the
            map's initial gamepiece (every game starts with it at the grid center)
    hand:   (n_hand,) gp_ids, which replace the engine's own hand after the replay
The pieces are replayed with the normal placement rules and scoring, so the slot's score is what the
engine would have scored for those moves. Legal actions are re-enumerated, so ff_observe sees the position.
Returns the replayed score (>= 0), or:
    -1  game out of range       -2  a gp_id, rot or position is out of range
    -3  a piece isn't a legal placement where it is (the position differs from the engine's rules)
On an error the slot holds the pieces replayed so far.
*/
int32_t ff_load_game(FFBatch* batch, uint32_t game,
                     const int32_t* pieces, uint32_t n_pieces,
                     const int32_t* hand, uint32_t n_hand);

// constants, so Python doesn't hardcode them
uint32_t ff_max_actions(void);
uint32_t ff_max_hand(void);
uint32_t ff_num_gamepieces(void);

#endif
