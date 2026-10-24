#ifndef FF_GAMEPIECE_DATA_H
#define FF_GAMEPIECE_DATA_H

#include <stdint.h>

// sized to map 1's largest gamepiece. data/map1_gamepieces.h static asserts that its data fits
#define MAX_PLACE_BLOCK_DATA 8 // most blocks in any gamepiece
#define MAX_OUTER_FACE_REQUIREMENT 26 // most outward buildable faces in any gamepiece_rot

// grid width in x, y and z. lives here so the grid (cell_index) and the precomputed deltas
// always use the same dims
#define GX 1000
#define GY 1000
#define GZ 1000

// bit 0 of a grid cell: 1 = filled. empty cells are all 0 (EMPTY_BLOCK)
#define FILLED_BIT 1

// grid offset for a (dx, dy, dz) offset, since
// cell_index(x + dx, y + dy, z + dz) = cell_index(x, y, z) + dx + GX*dy + GX*GY*dz
// a macro (not a function) so the generated gamepiece data can use it in static initializers,
// which keeps every delta matched to the grid's dims
#define GRID_DELTA(dx, dy, dz) ((dx) + GX * (dy) + GX * GY * (dz))

static inline int32_t grid_delta(int32_t dx, int32_t dy, int32_t dz){
    return GRID_DELTA(dx, dy, dz);
}

typedef struct{
    // grid offset from gamepiece origin
    // NOT a (x, y, z) interpretable 3d position; Its an offset in the
    // grid array convention. built with GRID_DELTA
    int32_t delta;
    // value written into grid: bit packed faces (bits 1-12).
    // FILLED_BIT is OR'd in when placed, so the precompute doesn't need to set it
    uint16_t cell;
    // BlockData.BlockType: Farm=0, House=1, Water=2, Ground=3, Windmill=4, Tower=5, Blank=6. for scoring.
    // fits in the struct's padding, so it costs no memory
    uint8_t block_type;
} PlaceBlockData;

typedef struct{
    // A single buildable face of this gamepiece_rot that points out of the gamepiece,
    // i.e. the cell it touches is not one of the gamepiece's own place_blocks.
    // Non-buildable faces (01) are left out, since they can't affect validity.
    // Required faces that point into the gamepiece are satisfied by its own blocks, so they're left out too.
    // BUT only if the own block's touching face is buildable (same rule as Unity). The precompute must check
    // this; a gamepiece_rot with an unsatisfied inward required face can never be placed.
    //
    // Used twice:
    //  - validity: the neighbor at delta must have a buildable opposite face for a connection.
    //    At least one connection is needed, and every RequiredToBuildOn (10) face must have one.
    //  - placement: once placed, the empty cell at delta becomes a frontier cell
    int32_t delta; // delta offset to neighboring cell this face touches
    uint8_t face; // our face type: 00 (FaceCanBeBuiltOn) or 10 (RequiredToBuildOn)
    uint8_t dir; // which side (+X, -X, ...) this face is on, to read the neighbor's opposite face
} Outer_data;

typedef struct{
    uint8_t n_cubes; // number cubes in a gamepiece_rot
    PlaceBlockData place_blocks[MAX_PLACE_BLOCK_DATA];

    uint16_t n_out; // number of outward buildable faces
    // every outward buildable face of the gamepiece_rot. Checked for validity,
    // and used to add new frontier cells after placing
    Outer_data outer[MAX_OUTER_FACE_REQUIREMENT];
} gamepiece_rot;


// end state valid action returned to the model
typedef struct{
    uint8_t gp_id;
    uint8_t rot;
    uint16_t x;
    uint16_t y;
    uint16_t z;
} valid_action;

#endif
