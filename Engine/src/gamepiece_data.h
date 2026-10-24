#ifndef FF_GAMEPIECE_DATA_H
#define FF_GAMEPIECE_DATA_H

#include <stdint.h>

#define MAX_PLACE_BLOCK_DATA 100 // TODO update to real value
#define MAX_OUTER_FACE_REQUIREMENT 300 // TODO update to real value

typedef struct{
    // grid offset from gamepiece origin
    // NOT a (x, y, z) interpretable 3d position; Its an offset in the
    // grid array convention
    int32_t delta;
    uint16_t cell; // value written into grid: bit packed block type and faces
} PlaceBlockData;

typedef struct{
    // A single buildable face of this gamepiece_rot that points out of the gamepiece,
    // i.e. the cell it touches is not one of the gamepiece's own place_blocks.
    // Non-buildable faces (01) are left out, since they can't affect validity.
    // Required faces that point into the gamepiece are satisfied by its own blocks, so they're left out too.
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

    uint8_t n_out; // number of outward buildable faces
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
