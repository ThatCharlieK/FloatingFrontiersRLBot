#ifndef FF_STATE_H
#define FF_STATE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "gamepiece_data.h"
#include "progression.h"

#define START_GRID_SIZE (GX * GY * GZ)
#define START_FRONTIER_SIZE (UINT16_MAX - 1) // max that fits frontier_pos, which stores slot + 1 in a uint16_t
#define MAX_VALID_GP_ROT 100000 // generous upper bound for total max valid actions
#define EMPTY_BLOCK 0 // convention for empty blocks: all zero, so a calloc'd grid starts empty. filled blocks always have bit 0 set
#define MAX_HAND_SIZE 200 // hands are added to on every level pass, so this is far above any real hand
#define START_PLACED_CAP 4096 // starting capacity of GameState.placed. doubles when full

// face types, as stored in the grid and in Outer_data.face
#define FACE_CAN_BE_BUILT_ON 0      // 00
#define FACE_CANT_BE_BUILT_ON 1     // 01
#define FACE_REQUIRED_TO_BUILD_ON 2 // 10

// grid cell bits 13-15: the block's type (see PlaceBlockData.block_type), for scoring
#define BLOCK_TYPE_SHIFT 13

// frontier_pos value for a cell that isn't in the frontier.
// 0 so a calloc'd frontier_pos starts with every cell not in the frontier, which means
// frontier_pos stores (frontier slot + 1)
#define NOT_IN_FRONTIER 0

// dedup hash set size for get_all_valid_gamepiece_rot (16k slots, ~128KB per GameState).
// must stay well above (frontier size * n_cubes), or probing slows down (and loops forever if full).
#define TRIED_BITS 14
#define TRIED_SIZE (1 << TRIED_BITS)


typedef struct GameState{
    /*
    grid[x, y, z] is an array of all placed blocks.
    Each element is a uint16_t that represents the different face types of the block at that spot (inclusive):
    bit 0: filled flag (FILLED_BIT). 1 = filled, 0 = empty (the whole cell is EMPTY_BLOCK = 0)
    bits 1-2: +X face
    bits 3-4: -X face
    bits 5-6: +Y face
    bits 7-8: -Y face
    bits 9-10: +Z face
    bits 11-12: -Z face
    bits 13-15: block type (BLOCK_TYPE_SHIFT), used for scoring

    Each face gets 2 bits, because the face is one of the three face types:
    00: FaceCanBeBuiltOn - for when face has full validity to be used as anything
    01: FaceCanTouchButCantBeBuiltOn:        for when two faces can touch but can't be used to build on
    10: RequiredToBuildOn                    for when this face MUST be used to build on (e.g. the bottom of a house).

    The real game also has FaceIsInsideGamepiece, but since I only track the frontier, and never undo, this is unneccessary.
    FaceCannotTouch is unused by every block in the game, so it's left out too.

    grid is a fixed GX * GY * GZ size, and calloc'd so it only costs memory where the city is built.
    TODO: grow it if the city ever reaches the edge
    */
    uint16_t* grid;

    /*
    frontier:
        Contiguous arr of indexes in grid of grid spots that are on the frontier.
        Records all empty indexes in grid that could be built on
    frontier_pos:
        Same size as grid. frontier_pos[cell_index(pos)] gives (the index of *frontier*
        where that grid would live) + 1. For most cells this is NOT_IN_FRONTIER (0).

    */
    uint32_t* frontier;
    uint16_t frontier_len; // number of elements in frontier, which is also the next free slot
    uint16_t* frontier_pos;

    /*
    placed:
        grid index of every placed cube, in placement order (the initial gamepiece included).
        Lets the observation export walk only the city instead of scanning the whole grid.
        Grows (doubles) when full, since the city has no size limit
    */
    uint32_t* placed;
    uint32_t placed_len;
    uint32_t placed_cap;

    /*
    Dedup for get_all_valid_gamepiece_rot.
    The same origin gets reached from several (frontier cell, place block) pairs, so for each
    gamepiece_rot we track the origins already tried in a small open addressing hash set.
    Each slot stores the origin itself, so two different origins hashing to the same slot don't collide.
    A slot only counts as occupied if its stamp == tried_pass, so starting a new gamepiece_rot is
    just tried_pass++ instead of clearing the whole table.
    Lives in GameState (not as a global) so each instance has its own and they can run in parallel.
    */
    int32_t tried_key[TRIED_SIZE];
    uint32_t tried_stamp[TRIED_SIZE]; // must start zeroed
    uint32_t tried_pass; // incremented before each use, so the first pass is 1 and the zeroed stamps read as empty

    /*
    Progression (see progression.h)
    hand: gp_ids of the cards in hand, contiguous from 0 to hand_len. order doesn't matter,
        and duplicates are separate cards
    */
    uint8_t hand[MAX_HAND_SIZE];
    uint16_t hand_len;
    int32_t score; // current points
    int32_t level_idx; // the last level whose threshold was passed
    uint8_t game_over; // hand is empty

    // rng for dealing hands. each GameState has its own, so a game is reproducible from rng_seed
    uint64_t rng_seed;
    uint64_t rng_state;

} GameState;

// game state helpers

// new game: empty grid, the map's initial gamepiece placed at the grid's center, and the first hand dealt
GameState* init_GameState(uint64_t seed);
// start a new game in an existing GameState. Same result as init_GameState(seed), but only clears the cells
// the last game touched instead of reallocating the grid
void reset_GameState(GameState* gstate, uint64_t seed);
void free_GameState(GameState* gstate);

uint32_t cell_index(uint16_t x_pos3d, uint16_t y_pos3d, uint16_t z_pos3d);

// every valid (gp_id, rot, origin) placement for the gamepieces in hand
void get_all_valid_gamepiece_rot(GameState* gstate, valid_action* valid_actions, uint32_t* n_valid_actions);

// play a card: place gamepiece gp_id from the hand, add its points, and deal hands for any level passed.
// Assumes the placement is valid
void place_gamepiece(GameState* gstate, uint8_t gp_id, uint8_t rot, int32_t gp_base_block_idx);

// points placing gp_rot at gp_base_block_idx would earn
int32_t score_gamepiece_rot(GameState* gstate, gamepiece_rot* gp_rot, int32_t gp_base_block_idx);

// only updates the grid and frontier (no score or hand). place_gamepiece uses this
void place_gamepiece_rot(GameState* gstate, gamepiece_rot* gp_rot, int32_t gp_base_block_idx);

#endif
