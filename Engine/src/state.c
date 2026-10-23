#include <stdio.h>
/*
The main performance object is, from the current gamestate,
quickly extra all valid [GamepieceID, x, y, z, rot] placement actions.
This requires:
1) Take all gamepieces in hand
2) For each gamepiece:
    - Loop through every block on the 'frontier'. The frontier is all empty blocks
      that border a FaceCanBeBuiltOn and don't border a FaceCannotTouch
        - Loop through every sub block in the current gamepiece, and try all 4 rotations,
          placing it at the empty block.
            - For a given rotation, loop through each sub block and check:
                - Check that there are no intersections
                - If no intersections, check if all the blocks of the current gamepiece that are
                  RequiredToBuildOn, and FaceCannotTouch are satisfied
                - Check that all the blocks it borders with have their own FaceCannotTouch satisfied

Thus the engine needs:
- Fast access to any place on the grid
- Fast access to the face type for any given face
*/

uint32_t start_grid_size = 100;
uint32_t start_frontier_size = 100000

typedef struct{
    /*
    grid[x, y, z] is an array of all placed blocks.

    Each spot in the grid is a uint16_t int that represents the block at that spot (inclusive):
    bytes 0-1: +X face
    bytes 2-3: -X face
    bytes 4-5: +Y face
    bytes 6-7: -Y face
    bytes 8-9: +Z face
    bytes 10-11: -Z face 

    Each face gets 2 bytes, because the face is one of the four face types:
    00: FaceCanBeBuiltOn - for when face has full validity to be used as anything
    01: FaceCannotTouch:                     for when no faces can touch - e.g for the top of a house
    10: FaceCanTouchButCantBeBuiltOn:        for when two faces can touch but can't be used to build on
    11: RequiredToBuildOn                    for when this face MUST be used to build on (e.g. the bottom of a house).

    The real game also has FaceIsInsideGamepiece, but since I only track the frontier, and never undo, this is unneccessary

    grid starts at a fixed size and grows if it overlaps
    */
    uint16_t grid*;

    /*
    the "frontier" is the list of the indexes in grid
    that are empty blocks that have a connection to FaceCanBeBuiltOn face, ie all
    the empty blocks that you might be able to place a new gamepiece at
    The coordinates of each frontier is laid out as:
    bytes 0-9:   x coord
    bytes 10-19: y coord
    bytes 20-29: z coord
    bytes 30-32: empty
    */
    uint32_t frontier[start_frontier_size];
    uint16_t last;

    /*
    I loop over frontier frequently so I need a way to remove from frontier:
    1) If I were to add an block at grid pos (x, y, z) to position n in frontier, I set:
        frontier_pos[x * y * z] = n
    2) To remove a block from the frontier, get the index of the block in frontier, then swap
        it with the end of the frontier, so theres no gaping holes. Then make the subtract the counter to the end:
            f_idx = fronter_pos[x * y * z]
            frontier[f_idx] = frontier[last]
            last--;
    */
    uint16_t* frontier_pos;
    uint16_t last;
    

} GameState 