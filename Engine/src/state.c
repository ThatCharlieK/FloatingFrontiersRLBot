#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "gamepiece_data.h"

/*
The main performance object is, from the current gamestate,
quickly extra all valid [GamepieceID, x, y, z, rot] placement actions.
This requires:
1) Take all gamepieces in hand
2) For each gamepiece, and each of its 4 rotations:
    - Loop through every block on the 'frontier'. The frontier is all empty blocks
      that touch a buildable face of a placed block
        - Loop through every sub block in the current gamepiece, placing it at the empty block.
          This gives a candidate origin for the gamepiece (skip it if already tried)
            - Check that there are no intersections
            - If no intersections, check that every outer RequiredToBuildOn face touches a buildable face,
              and that there's at least one buildable connection to the city

Thus the engine needs:
- Fast access to any place on the grid
- Fast access to the face type for any given face
*/

uint32_t START_GRID_SIZE = GX * GY * GZ;
uint32_t START_FRONTIER_SIZE = UINT16_MAX - 1; // max that fits frontier_pos, which stores slot + 1 in a uint16_t
uint32_t MAX_VALID_GP_ROT = 100000; // generous upper bound for total max valid actions
const uint16_t EMPTY_BLOCK = 0; // convention for empty blocks: all zero, so a calloc'd grid starts empty. filled blocks always have bit 0 set

// face types, as stored in the grid and in Outer_data.face
#define FACE_CAN_BE_BUILT_ON 0      // 00
#define FACE_CANT_BE_BUILT_ON 1     // 01
#define FACE_REQUIRED_TO_BUILD_ON 2 // 10

// frontier_pos value for a cell that isn't in the frontier.
// 0 so a calloc'd frontier_pos starts with every cell not in the frontier, which means
// frontier_pos stores (frontier slot + 1)
#define NOT_IN_FRONTIER 0

// dedup hash set size for get_all_valid_gamepiece_rot (16k slots, ~128KB per GameState).
// must stay well above (frontier size * n_cubes), or probing slows down (and loops forever if full).
#define TRIED_BITS 14
#define TRIED_SIZE (1 << TRIED_BITS)

const uint16_t num_gamepiece = 50; // TODO fill in with true number

typedef struct{
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

    // For each of the ~50 gamepiece
    // gamepiece_data[id][rot (0-3)] holds a gamepiece_rot (see gamepiece_data.h):
    //      - type of each block
    //      - delta offsets for each block
    //      - delta offsets for each outer buildable face, used for validity and new frontier blocks
    // the 3d indexing formula is setup so that:
    //      idx(x + dx, y + dy, z + dz) = idx(x, y, z) + precomputed constant,
    //      based based on grid size and width
    // Thus adding a piece to the grid of checking overlaps is just checking:
    //      grid[base_game_piece + per_block_delta]
    // where per_block_delta is precomputed
    uint16_t* gamepiece_data;

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

} GameState;

// frontier helpers, defined at the bottom
void add_to_frontier(GameState* gstate, uint32_t grid_idx);
void remove_from_frontier(GameState* gstate, uint32_t grid_idx);

// game state helpers

GameState* init_GameState(){
    // initilize a game state with the starter list lengths
    // calloc zeroes everything, so the dedup table (tried_stamp, tried_pass) starts empty
    GameState* game_state = (GameState*) calloc(1, sizeof(GameState));

    // initilize large starter grid
    // calloc'd memory reads as all zeros, and the OS only gives a page real RAM once it's written to,
    // so these huge arrays start out as EMPTY_BLOCK / NOT_IN_FRONTIER with no init loop,
    // and only cost memory around where the city is actually built
    game_state -> grid = calloc(START_GRID_SIZE, sizeof(uint16_t));
    game_state -> frontier_pos = calloc(START_GRID_SIZE, sizeof(uint16_t)); // same dims as grid

    // initilize
    game_state -> frontier = malloc(sizeof(uint32_t) * START_FRONTIER_SIZE);
    game_state -> frontier_len = 0;

    return game_state;
}

uint32_t cell_index(uint16_t x_pos3d, uint16_t y_pos3d, uint16_t z_pos3d){
    // cell_index(x, y, z) = x + GX * y + GX*GY * z
    // for GX, GY constants that are the grid's width in x and y
    // cell_index(x + dx, y + dy, z + dz) = cell_index(x, y, z) + dx + GX*dy + GX*GY*dz
    return x_pos3d + GX * y_pos3d + GX * GY * z_pos3d;
}

uint8_t get_face(uint16_t block_in_grid, uint8_t dir){
    // extract the face type from a block in the grid
    // that the Outer_data's dir wanted.
    // dir follows the grid's bit layout: 0 = +X, 1 = -X, 2 = +Y, 3 = -Y, 4 = +Z, 5 = -Z,
    // so each face lives at bits 1+2*dir and 2+2*dir (bit 0 is the filled flag). Shifting replaces the switch.
    return (block_in_grid >> (1 + 2 * dir)) & 0x3;
}

uint8_t is_valid_gp_rot_placement(GameState* gstate, gamepiece_rot* gp_rot, int32_t gp_base_idx){
    // check if the gamepiece and its rotation is valid to be placed
    // with the origin being at gp_base_pos

    // check if the piece's blocks overlap with any placed blocks
    for(int i = 0; i < gp_rot->n_cubes; i++){
        int32_t block_delta = gp_rot->place_blocks[i].delta;
        int32_t grid_pos = gp_base_idx + block_delta;
        if(gstate-> grid[grid_pos] != EMPTY_BLOCK){
            return 0; // invalid
        }
    }

    // check that all outer requirements are satisfied
    int8_t has_buildable_face = 0;
    for(int j = 0; j < gp_rot->n_out; j++){
        Outer_data outer_data = gp_rot->outer[j];
        int32_t grid_pos = gp_base_idx + outer_data.delta;
        uint16_t neighbor = gstate->grid[grid_pos];

        // a connection is our (buildable) face touching a buildable face of a placed block.
        // the neighbor's touching face is on the opposite side: dir ^ 1 (+X <-> -X, etc.)
        if(neighbor != EMPTY_BLOCK && get_face(neighbor, outer_data.dir ^ 1) != FACE_CANT_BE_BUILT_ON){
            has_buildable_face = 1;
        }
        // if a required face has no connection, return invalid
        else if(outer_data.face == FACE_REQUIRED_TO_BUILD_ON){
            return 0;
        }
    }

    // need at least one connection to the city
    return has_buildable_face;
}

valid_action convert_to_valid_action(uint8_t gp_id, uint8_t rot, int32_t gp_base_pos){
    // convert a gamepiece id, a rotation, and position
    // return a valid_action
    // gp_base_pos is a grid index, so undo cell_index to get back (x, y, z)
    valid_action action;
    action.gp_id = gp_id;
    action.rot = rot;
    action.x = gp_base_pos % GX;
    action.y = (gp_base_pos / GX) % GY;
    action.z = gp_base_pos / (GX * GY);
    return action;
}

uint8_t already_tried(GameState* gstate, int32_t origin){
    // returns 1 if origin was already tried this pass, otherwise marks it as tried and returns 0
    uint32_t slot = ((uint32_t)origin * 2654435761u) >> (32 - TRIED_BITS); // multiplicative hash
    while(gstate->tried_stamp[slot] == gstate->tried_pass){
        if(gstate->tried_key[slot] == origin) return 1;
        slot = (slot + 1) & (TRIED_SIZE - 1); // linear probe
    }
    gstate->tried_stamp[slot] = gstate->tried_pass;
    gstate->tried_key[slot] = origin;
    return 0;
}

void get_all_valid_gamepiece_rot(GameState* gstate, valid_action* valid_actions, uint32_t* n_valid_actions){
    // the most perf. intensive function
    // Gets all valid gamepiec_rot combinations and the position of their origin block
    // valid_actions: out param, caller owned buffer with room for MAX_VALID_GP_ROT actions.
    //      caller owns it so it can be reused every step (and later be a numpy buffer from python)
    // n_valid_actions: out param, number of actions written into valid_actions

    uint32_t valid_actions_idx = 0;

    // loop order is gamepiece -> rotation -> frontier -> place block, so that within one
    // gamepiece_rot every duplicate is just a repeated origin
    for(uint8_t gp_id = 0; gp_id < num_gamepiece; gp_id++){ // TODO: only gamepieces in hand
        for(uint8_t rot = 0; rot < 4; rot++){
            gamepiece_rot* cur_gp_rot = NULL; // TODO: lookup gamepiece_data[gp_id][rot]
            gstate->tried_pass++; // new pass: forget the origins tried for the previous gamepiece_rot

            // loop over frontier
            for(uint32_t i = 0; i < gstate->frontier_len; i++){
                // try all combinations;
                // loop through all place blocks of gamepiece_rot,
                // try placing them all in the current frontier block
                uint32_t frontier_cell = gstate->frontier[i];

                for(int b = 0; b < cur_gp_rot->n_cubes; b++){
                    // put place_blocks[b] on the frontier cell. Its grid idx is base + delta,
                    // so the gamepiece origin is the frontier cell minus that block's delta
                    int32_t cur_gp_rot_pos = frontier_cell - cur_gp_rot->place_blocks[b].delta;

                    // skip origins this gamepiece_rot already tried from another frontier cell or place block
                    if(already_tried(gstate, cur_gp_rot_pos)) continue;

                    // check if cur_gp_rot is valid
                    if(is_valid_gp_rot_placement(gstate, cur_gp_rot, cur_gp_rot_pos)){
                        // buffer is full; stop instead of writing past it. MAX_VALID_GP_ROT should be far above any real count
                        if(valid_actions_idx >= MAX_VALID_GP_ROT){
                            *n_valid_actions = valid_actions_idx;
                            return;
                        }
                        valid_actions[valid_actions_idx] = convert_to_valid_action(gp_id, rot, cur_gp_rot_pos);
                        valid_actions_idx++;
                    }
                }
            }
        }
    }
    *n_valid_actions = valid_actions_idx;
}

void place_gamepiece_rot(GameState* gstate, gamepiece_rot* gp_rot, int32_t gp_base_block_idx){
    // gstate: game state
    // gp_rot: the precomputed data for the gamepiece to place, wrt to its cur rotation
    // gp_base_block_idx: the index into grid that the current gamepiece is at

    // Place a gamepiece with a set rotation. Assume gamepiece is valid
    // Pulls from precompute data, does fast checks against current grid state

    // loop through all blocks in the gamepiece
    for(uint16_t i = 0; i < gp_rot -> n_cubes; i++){
        PlaceBlockData pbd = gp_rot->place_blocks[i];
        // from the grid indexing convention, we compute each
        // blocks grid position as a one off delta offset from the base
        // this pbd.delta offset is precomputed
        uint32_t pbd_grid_idx = gp_base_block_idx + pbd.delta; // position in grid of the new block

        // fill it in in the grid. FILLED_BIT marks it as filled, even if all its faces are 00
        gstate->grid[pbd_grid_idx] = pbd.cell | FILLED_BIT;
        remove_from_frontier(gstate, pbd_grid_idx);
    }

    // Loop through all blocks that are on the outside of the current gamepiece
    // If they don't overlap with any block in grid, then add add it to the frontier
    for(uint32_t i = 0; i < gp_rot->n_out; i++){
        uint32_t outer_grid_idx = gp_base_block_idx + gp_rot->outer[i].delta;
        if(gstate->grid[outer_grid_idx] != EMPTY_BLOCK) continue; // skip if filled
        // skip if already in frontier (e.g. the inner corner of an L touches two outer faces)
        if(gstate->frontier_pos[outer_grid_idx] != NOT_IN_FRONTIER) continue;
        add_to_frontier(gstate, outer_grid_idx);
    }
}

void add_to_frontier(GameState* gstate, uint32_t grid_idx){
    // add the block at grid_idx to the frontier
    // doesn't handle duplicates; caller must ensure grid_idx not in froniter
    gstate->frontier[gstate->frontier_len] = grid_idx;
    gstate->frontier_pos[grid_idx] = gstate->frontier_len + 1; // +1 since 0 is NOT_IN_FRONTIER
    gstate->frontier_len++;
}

void remove_from_frontier(GameState* gstate, uint32_t grid_idx){
    // if grid_idx was on frontier, remove it from the frontier

    // get the index in frontier that the empty block lived in
    if (gstate -> frontier_pos[grid_idx] == NOT_IN_FRONTIER) return; // cubes can land on cells that were never on the frontier
    uint16_t frontier_idx = gstate -> frontier_pos[grid_idx] - 1; // frontier_pos stores slot + 1

    // remove the block from the frontier:
    // swap its position in frontier with the last entry in frontier, to keep frontier contiugous

    // f_last = grid index of last element in frontier
    gstate -> frontier_len--;
    uint32_t f_last = gstate -> frontier[gstate -> frontier_len];
    gstate -> frontier[frontier_idx] = f_last;
    gstate -> frontier_pos[f_last] = frontier_idx + 1;

    // must come after updating f_last, since f_last == grid_idx when it was the last entry
    gstate -> frontier_pos[grid_idx] = NOT_IN_FRONTIER;
}
