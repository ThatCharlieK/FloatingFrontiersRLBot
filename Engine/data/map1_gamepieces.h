// GENERATED FILE, do not edit by hand.
// Map 1 (Waldsburg) gamepiece ground truth, exported from Floating Frontiers
//
// MAP1_GAMEPIECE_ROTS[gp_id][rot] is the gamepiece_rot for gamepiece gp_id rotated rot * 90 degrees
// clockwise (from above) around Y. A block's grid index is origin + delta, where the origin is the
// gamepiece's pivot cell.
#ifndef FF_MAP1_GAMEPIECES_H
#define FF_MAP1_GAMEPIECES_H

#include "../src/gamepiece_data.h"

#define MAP1_NUM_GAMEPIECES 51
#define MAP1_INITIAL_GAMEPIECE_ID 1 // 1x1GroundWithHouse
#define MAP1_MAX_CUBES 8 // most blocks in any gamepiece
#define MAP1_MAX_OUTER 26 // most outward buildable faces in any gamepiece_rot

// make sure the data fits in gamepiece_rot
_Static_assert(MAP1_MAX_CUBES <= MAX_PLACE_BLOCK_DATA, "MAX_PLACE_BLOCK_DATA too small for map 1");
_Static_assert(MAP1_MAX_OUTER <= MAX_OUTER_FACE_REQUIREMENT, "MAX_OUTER_FACE_REQUIREMENT too small for map 1");

static const char* MAP1_GAMEPIECE_NAMES[MAP1_NUM_GAMEPIECES] = {
    "1x1Ground", // 0
    "1x1GroundWithHouse", // 1
    "2x1Ground", // 2
    "2x1TowerBareGround", // 3
    "2x1TowerHouse", // 4
    "2x2Ground", // 5
    "2x2Lakehouse", // 6
    "DoubleFarm", // 7
    "DoubleHouse", // 8
    "DoubleWater", // 9
    "DoubleWindmill", // 10
    "DoubleWindmillWater", // 11
    "Farm", // 12
    "FarmOnGround", // 13
    "GroundRow", // 14
    "House", // 15
    "HouseOnGround", // 16
    "HouseRow", // 17
    "HouseRowMissing", // 18
    "LakeHouse", // 19
    "LFarm", // 20
    "LGround", // 21
    "LHouse", // 22
    "LStepWater", // 23
    "LWater", // 24
    "LWaterFarm", // 25
    "LWindmill", // 26
    "LWindMillWater", // 27
    "OffsetHouseRow", // 28
    "SingleStepFarm", // 29
    "SingleStepHouse", // 30
    "SingleStepLFarm", // 31
    "SingleStepTowerHouse", // 32
    "SingleStepWater", // 33
    "StepFarm", // 34
    "StepHouses", // 35
    "StepHouseWater", // 36
    "StepHouseWater2", // 37
    "StepWater", // 38
    "TallHouseWater", // 39
    "TallL", // 40
    "Tower", // 41
    "TowerOnGround", // 42
    "WaterOnGround", // 43
    "Windmill", // 44
    "WindmillOnGround", // 45
    "WindmillRow", // 46
    "WindmillRowMissing", // 47
    "zigzagFarm", // 48
    "ZigZagStepFarmWindmill", // 49
    "zigZagyStep", // 50
};

static gamepiece_rot MAP1_GAMEPIECE_ROTS[MAP1_NUM_GAMEPIECES][4] = {
    // 0: 1x1Ground
    {
        { // rot 0
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0000, 3 }, // Ground at (0, 0, 0)
            },
            .n_out = 6,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0000, 3 }, // Ground at (0, 0, 0)
            },
            .n_out = 6,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0000, 3 }, // Ground at (0, 0, 0)
            },
            .n_out = 6,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0000, 3 }, // Ground at (0, 0, 0)
            },
            .n_out = 6,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 1: 1x1GroundWithHouse
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 2: 2x1Ground
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0002, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0008, 3 }, // Ground at (1, 0, 0)
            },
            .n_out = 10,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0800, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0200, 3 }, // Ground at (0, 0, -1)
            },
            .n_out = 10,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0008, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0002, 3 }, // Ground at (-1, 0, 0)
            },
            .n_out = 10,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0200, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0800, 3 }, // Ground at (0, 0, 1)
            },
            .n_out = 10,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 3: 2x1TowerBareGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 4: 2x1TowerHouse
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 5: 2x2Ground
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0202, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0208, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0802, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 0, 1), 0x0808, 3 }, // Ground at (1, 0, 1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0802, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0202, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0808, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, -1), 0x0208, 3 }, // Ground at (1, 0, -1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0808, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0802, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0208, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 0, -1), 0x0202, 3 }, // Ground at (-1, 0, -1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0208, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0808, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0202, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, 1), 0x0802, 3 }, // Ground at (-1, 0, 1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 6: 2x2Lakehouse
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0222, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0228, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0802, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 0, 1), 0x0828, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x0aaa, 1 }, // House at (1, 1, 1)
            },
            .n_out = 13,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0822, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0222, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0808, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, -1), 0x0228, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
                { GRID_DELTA(1, 1, -1), 0x0aaa, 1 }, // House at (1, 1, -1)
            },
            .n_out = 13,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0828, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0822, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0208, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 0, -1), 0x0222, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x0aaa, 1 }, // House at (-1, 1, -1)
            },
            .n_out = 13,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0228, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0828, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0202, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, 1), 0x0822, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
                { GRID_DELTA(-1, 1, 1), 0x0aaa, 1 }, // House at (-1, 1, 1)
            },
            .n_out = 13,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 7: DoubleFarm
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 0 }, // Farm at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 0 }, // Farm at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 0 }, // Farm at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 0 }, // Farm at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 8: DoubleHouse
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 9: DoubleWater
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 10: DoubleWindmill
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 4 }, // Windmill at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 4 }, // Windmill at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 4 }, // Windmill at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 4 }, // Windmill at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 11: DoubleWindmillWater
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, -2, 0), 0x0220, 3 }, // Ground at (0, -2, 0)
                { GRID_DELTA(0, -2, 1), 0x0820, 3 }, // Ground at (0, -2, 1)
                { GRID_DELTA(-1, -1, 0), 0x0022, 3 }, // Ground at (-1, -1, 0)
                { GRID_DELTA(0, -1, 0), 0x02a8, 3 }, // Ground at (0, -1, 0)
                { GRID_DELTA(0, -1, 1), 0x0aaa, 2 }, // Water at (0, -1, 1)
                { GRID_DELTA(-1, 0, 0), 0x0aaa, 4 }, // Windmill at (-1, 0, 0)
                { GRID_DELTA(0, 0, 0), 0x0aaa, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, -2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, -2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -2, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, -2, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -3, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, -1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -2, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, -1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, -1, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, -2, 0), 0x0022, 3 }, // Ground at (0, -2, 0)
                { GRID_DELTA(1, -2, 0), 0x0028, 3 }, // Ground at (1, -2, 0)
                { GRID_DELTA(0, -1, 1), 0x0820, 3 }, // Ground at (0, -1, 1)
                { GRID_DELTA(0, -1, 0), 0x02a2, 3 }, // Ground at (0, -1, 0)
                { GRID_DELTA(1, -1, 0), 0x0aaa, 2 }, // Water at (1, -1, 0)
                { GRID_DELTA(0, 0, 1), 0x0aaa, 4 }, // Windmill at (0, 0, 1)
                { GRID_DELTA(0, 0, 0), 0x0aaa, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, -2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, -2, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, -2, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, -2, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, -2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, -1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -2, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, -1, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, -1, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, -2, 0), 0x0820, 3 }, // Ground at (0, -2, 0)
                { GRID_DELTA(0, -2, -1), 0x0220, 3 }, // Ground at (0, -2, -1)
                { GRID_DELTA(1, -1, 0), 0x0028, 3 }, // Ground at (1, -1, 0)
                { GRID_DELTA(0, -1, 0), 0x08a2, 3 }, // Ground at (0, -1, 0)
                { GRID_DELTA(0, -1, -1), 0x0aaa, 2 }, // Water at (0, -1, -1)
                { GRID_DELTA(1, 0, 0), 0x0aaa, 4 }, // Windmill at (1, 0, 0)
                { GRID_DELTA(0, 0, 0), 0x0aaa, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, -2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, -2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, -2, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, -2, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -3, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, -1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -2, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, -1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, -1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, -1, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 4 }, // +Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, -2, 0), 0x0028, 3 }, // Ground at (0, -2, 0)
                { GRID_DELTA(-1, -2, 0), 0x0022, 3 }, // Ground at (-1, -2, 0)
                { GRID_DELTA(0, -1, -1), 0x0220, 3 }, // Ground at (0, -1, -1)
                { GRID_DELTA(0, -1, 0), 0x08a8, 3 }, // Ground at (0, -1, 0)
                { GRID_DELTA(-1, -1, 0), 0x0aaa, 2 }, // Water at (-1, -1, 0)
                { GRID_DELTA(0, 0, -1), 0x0aaa, 4 }, // Windmill at (0, 0, -1)
                { GRID_DELTA(0, 0, 0), 0x0aaa, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, -2, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, -2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, -2, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, -2, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -3, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, -2, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, -2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, -1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -2, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, -1, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 1), 0, 4 }, // +Z
            },
        },
    },
    // 12: Farm
    {
        { // rot 0
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 0 }, // Farm at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 1
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 0 }, // Farm at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 2
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 0 }, // Farm at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 3
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 0 }, // Farm at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
    },
    // 13: FarmOnGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 14: GroundRow
    {
        { // rot 0
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0002, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x000a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0008, 3 }, // Ground at (2, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0800, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a00, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0200, 3 }, // Ground at (0, 0, -2)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0008, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x000a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0002, 3 }, // Ground at (-2, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0200, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a00, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0800, 3 }, // Ground at (0, 0, 2)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
    },
    // 15: House
    {
        { // rot 0
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 1 }, // House at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 1
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 1 }, // House at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 2
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 1 }, // House at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 3
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 1 }, // House at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
    },
    // 16: HouseOnGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 17: HouseRow
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x002a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0028, 3 }, // Ground at (2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0aaa, 1 }, // House at (2, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a20, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0220, 3 }, // Ground at (0, 0, -2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0aaa, 1 }, // House at (0, 1, -2)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x002a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0022, 3 }, // Ground at (-2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0aaa, 1 }, // House at (-2, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a20, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0820, 3 }, // Ground at (0, 0, 2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0aaa, 1 }, // House at (0, 1, 2)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
    },
    // 18: HouseRowMissing
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x000a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0028, 3 }, // Ground at (2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0aaa, 1 }, // House at (2, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a00, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0220, 3 }, // Ground at (0, 0, -2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -2), 0x0aaa, 1 }, // House at (0, 1, -2)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x000a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0022, 3 }, // Ground at (-2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0aaa, 1 }, // House at (-2, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a00, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0820, 3 }, // Ground at (0, 0, 2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 2), 0x0aaa, 1 }, // House at (0, 1, 2)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
    },
    // 19: LakeHouse
    {
        { // rot 0
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 4,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
            },
            .n_out = 8,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
    },
    // 20: LFarm
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0228, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, 1), 0x0820, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 0 }, // Farm at (1, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x0aaa, 0 }, // Farm at (1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0222, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, -1), 0x0028, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 0 }, // Farm at (0, 1, -1)
                { GRID_DELTA(1, 1, -1), 0x0aaa, 0 }, // Farm at (1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0822, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, -1), 0x0220, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 0 }, // Farm at (-1, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x0aaa, 0 }, // Farm at (-1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0828, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 1), 0x0022, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 0 }, // Farm at (0, 1, 1)
                { GRID_DELTA(-1, 1, 1), 0x0aaa, 0 }, // Farm at (-1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, 0), 0, 5 }, // -Z
            },
        },
    },
    // 21: LGround
    {
        { // rot 0
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0202, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0008, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0800, 3 }, // Ground at (0, 0, 1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0802, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0200, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0008, 3 }, // Ground at (1, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0808, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0002, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0200, 3 }, // Ground at (0, 0, -1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 3,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0208, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0800, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0002, 3 }, // Ground at (-1, 0, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 22: LHouse
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0228, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, 1), 0x0820, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x0aaa, 1 }, // House at (1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0222, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, -1), 0x0028, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
                { GRID_DELTA(1, 1, -1), 0x0aaa, 1 }, // House at (1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0822, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, -1), 0x0220, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x0aaa, 1 }, // House at (-1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0828, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 1), 0x0022, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
                { GRID_DELTA(-1, 1, 1), 0x0aaa, 1 }, // House at (-1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, 0), 0, 5 }, // -Z
            },
        },
    },
    // 23: LStepWater
    {
        { // rot 0
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0222, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0208, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0822, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 0, 1), 0x0828, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
                { GRID_DELTA(1, 1, 1), 0x00a8, 3 }, // Ground at (1, 1, 1)
                { GRID_DELTA(1, 2, 1), 0x0aaa, 2 }, // Water at (1, 2, 1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 0), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0822, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0202, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0828, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, -1), 0x0228, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
                { GRID_DELTA(1, 1, -1), 0x02a0, 3 }, // Ground at (1, 1, -1)
                { GRID_DELTA(1, 2, -1), 0x0aaa, 2 }, // Water at (1, 2, -1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0828, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0802, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0228, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 0, -1), 0x0222, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
                { GRID_DELTA(-1, 1, -1), 0x00a2, 3 }, // Ground at (-1, 1, -1)
                { GRID_DELTA(-1, 2, -1), 0x0aaa, 2 }, // Water at (-1, 2, -1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0228, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0808, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0222, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, 1), 0x0822, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
                { GRID_DELTA(-1, 1, 1), 0x08a0, 3 }, // Ground at (-1, 1, 1)
                { GRID_DELTA(-1, 2, 1), 0x0aaa, 2 }, // Water at (-1, 2, 1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 2), 0, 4 }, // +Z
            },
        },
    },
    // 24: LWater
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0202, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0802, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0808, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0208, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 25: LWaterFarm
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0202, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 0 }, // Farm at (1, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0802, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 0 }, // Farm at (0, 1, -1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0808, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 0 }, // Farm at (-1, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0208, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 0 }, // Farm at (0, 1, 1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 26: LWindmill
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0228, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, 1), 0x0820, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 4 }, // Windmill at (1, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x0aaa, 4 }, // Windmill at (1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0222, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, -1), 0x0028, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 4 }, // Windmill at (0, 1, -1)
                { GRID_DELTA(1, 1, -1), 0x0aaa, 4 }, // Windmill at (1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0822, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, -1), 0x0220, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 4 }, // Windmill at (-1, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x0aaa, 4 }, // Windmill at (-1, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0828, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 1), 0x0022, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 4 }, // Windmill at (0, 1, 1)
                { GRID_DELTA(-1, 1, 1), 0x0aaa, 4 }, // Windmill at (-1, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, 0), 0, 5 }, // -Z
            },
        },
    },
    // 27: LWindMillWater
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0222, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 2 }, // Water at (1, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 4 }, // Windmill at (0, 1, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0822, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 2 }, // Water at (0, 1, -1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 4 }, // Windmill at (1, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0828, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 2 }, // Water at (-1, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 4 }, // Windmill at (0, 1, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0228, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 2 }, // Water at (0, 1, 1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 4 }, // Windmill at (-1, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 28: OffsetHouseRow
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, 0), 0x020a, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 0), 0x0a02, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 0), 0x080a, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 1 }, // House at (1, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, 0), 0x0a08, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 1 }, // House at (0, 1, -1)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 1 }, // House at (0, 1, 1)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 1 }, // House at (-1, 1, 0)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 29: SingleStepFarm
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00a8, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 0 }, // Farm at (1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x02a0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 0 }, // Farm at (0, 2, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00a2, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 0 }, // Farm at (-1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x08a0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 0 }, // Farm at (0, 2, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
            },
        },
    },
    // 30: SingleStepHouse
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00a8, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 1 }, // House at (1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x02a0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 1 }, // House at (0, 2, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00a2, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 1 }, // House at (-1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x08a0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 1 }, // House at (0, 2, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
            },
        },
    },
    // 31: SingleStepLFarm
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x02a8, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x0820, 3 }, // Ground at (1, 1, 1)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 0 }, // Farm at (1, 2, 0)
                { GRID_DELTA(1, 2, 1), 0x0aaa, 0 }, // Farm at (1, 2, 1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(1, 0, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 1, 2), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x02a2, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(1, 1, -1), 0x0028, 3 }, // Ground at (1, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 0 }, // Farm at (0, 2, -1)
                { GRID_DELTA(1, 2, -1), 0x0aaa, 0 }, // Farm at (1, 2, -1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(1, 0, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x08a2, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x0220, 3 }, // Ground at (-1, 1, -1)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 0 }, // Farm at (-1, 2, 0)
                { GRID_DELTA(-1, 2, -1), 0x0aaa, 0 }, // Farm at (-1, 2, -1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, 0, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x08a8, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(-1, 1, 1), 0x0022, 3 }, // Ground at (-1, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 0 }, // Farm at (0, 2, 1)
                { GRID_DELTA(-1, 2, 1), 0x0aaa, 0 }, // Farm at (-1, 2, 1)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, 0, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 0), 0, 5 }, // -Z
            },
        },
    },
    // 32: SingleStepTowerHouse
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00a8, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 5 }, // Tower at (1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x02a0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 5 }, // Tower at (0, 2, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00a2, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 5 }, // Tower at (-1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x08a0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 5 }, // Tower at (0, 2, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
            },
        },
    },
    // 33: SingleStepWater
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00a8, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 2 }, // Water at (1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x02a0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 2 }, // Water at (0, 2, -1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00a2, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 2 }, // Water at (-1, 2, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x08a0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 2 }, // Water at (0, 2, 1)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
            },
        },
    },
    // 34: StepFarm
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0002, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 1, 0), 0x00a2, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0028, 3 }, // Ground at (2, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 0 }, // Farm at (1, 2, 0)
                { GRID_DELTA(2, 2, 0), 0x00a8, 3 }, // Ground at (2, 2, 0)
                { GRID_DELTA(2, 3, 0), 0x0aaa, 0 }, // Farm at (2, 3, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0800, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, -1), 0x08a0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0220, 3 }, // Ground at (0, 1, -2)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 0 }, // Farm at (0, 2, -1)
                { GRID_DELTA(0, 2, -2), 0x02a0, 3 }, // Ground at (0, 2, -2)
                { GRID_DELTA(0, 3, -2), 0x0aaa, 0 }, // Farm at (0, 3, -2)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, -3), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0008, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 1, 0), 0x00a8, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0022, 3 }, // Ground at (-2, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 0 }, // Farm at (-1, 2, 0)
                { GRID_DELTA(-2, 2, 0), 0x00a2, 3 }, // Ground at (-2, 2, 0)
                { GRID_DELTA(-2, 3, 0), 0x0aaa, 0 }, // Farm at (-2, 3, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0200, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 1), 0x02a0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0820, 3 }, // Ground at (0, 1, 2)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 0 }, // Farm at (0, 2, 1)
                { GRID_DELTA(0, 2, 2), 0x08a0, 3 }, // Ground at (0, 2, 2)
                { GRID_DELTA(0, 3, 2), 0x0aaa, 0 }, // Farm at (0, 3, 2)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 3), 0, 4 }, // +Z
                { GRID_DELTA(1, 2, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 3), 0, 4 }, // +Z
            },
        },
    },
    // 35: StepHouses
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0a80, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0820, 3 }, // Ground at (0, 1, 2)
                { GRID_DELTA(0, 2, 2), 0x0aaa, 1 }, // House at (0, 2, 2)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 3), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x008a, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0028, 3 }, // Ground at (2, 1, 0)
                { GRID_DELTA(2, 2, 0), 0x0aaa, 1 }, // House at (2, 2, 0)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0a80, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0220, 3 }, // Ground at (0, 1, -2)
                { GRID_DELTA(0, 2, -2), 0x0aaa, 1 }, // House at (0, 2, -2)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 2, -1), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, -3), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x008a, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0022, 3 }, // Ground at (-2, 1, 0)
                { GRID_DELTA(-2, 2, 0), 0x0aaa, 1 }, // House at (-2, 2, 0)
            },
            .n_out = 15,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 2, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -1), 0, 5 }, // -Z
            },
        },
    },
    // 36: StepHouseWater
    {
        { // rot 0
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00aa, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0028, 3 }, // Ground at (2, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 2 }, // Water at (1, 2, 0)
                { GRID_DELTA(2, 2, 0), 0x00a8, 3 }, // Ground at (2, 2, 0)
                { GRID_DELTA(2, 3, 0), 0x0aaa, 1 }, // House at (2, 3, 0)
            },
            .n_out = 17,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aa0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0220, 3 }, // Ground at (0, 1, -2)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 2 }, // Water at (0, 2, -1)
                { GRID_DELTA(0, 2, -2), 0x02a0, 3 }, // Ground at (0, 2, -2)
                { GRID_DELTA(0, 3, -2), 0x0aaa, 1 }, // House at (0, 3, -2)
            },
            .n_out = 17,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, -3), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00aa, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0022, 3 }, // Ground at (-2, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 2 }, // Water at (-1, 2, 0)
                { GRID_DELTA(-2, 2, 0), 0x00a2, 3 }, // Ground at (-2, 2, 0)
                { GRID_DELTA(-2, 3, 0), 0x0aaa, 1 }, // House at (-2, 3, 0)
            },
            .n_out = 17,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aa0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0820, 3 }, // Ground at (0, 1, 2)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 2 }, // Water at (0, 2, 1)
                { GRID_DELTA(0, 2, 2), 0x08a0, 3 }, // Ground at (0, 2, 2)
                { GRID_DELTA(0, 3, 2), 0x0aaa, 1 }, // House at (0, 3, 2)
            },
            .n_out = 17,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 3), 0, 4 }, // +Z
                { GRID_DELTA(1, 2, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 3), 0, 4 }, // +Z
            },
        },
    },
    // 37: StepHouseWater2
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x00aa, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0028, 3 }, // Ground at (2, 1, 0)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 2 }, // Water at (1, 2, 0)
                { GRID_DELTA(2, 2, 0), 0x0aaa, 1 }, // House at (2, 2, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aa0, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0220, 3 }, // Ground at (0, 1, -2)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 2 }, // Water at (0, 2, -1)
                { GRID_DELTA(0, 2, -2), 0x0aaa, 1 }, // House at (0, 2, -2)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x00aa, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0022, 3 }, // Ground at (-2, 1, 0)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 2 }, // Water at (-1, 2, 0)
                { GRID_DELTA(-2, 2, 0), 0x0aaa, 1 }, // House at (-2, 2, 0)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 1 }, // House at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aa0, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0820, 3 }, // Ground at (0, 1, 2)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 2 }, // Water at (0, 2, 1)
                { GRID_DELTA(0, 2, 2), 0x0aaa, 1 }, // House at (0, 2, 2)
            },
            .n_out = 14,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 3), 0, 4 }, // +Z
            },
        },
    },
    // 38: StepWater
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x008a, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0028, 3 }, // Ground at (2, 1, 0)
                { GRID_DELTA(2, 2, 0), 0x00a0, 3 }, // Ground at (2, 2, 0)
                { GRID_DELTA(2, 3, 0), 0x0aaa, 2 }, // Water at (2, 3, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0a80, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0220, 3 }, // Ground at (0, 1, -2)
                { GRID_DELTA(0, 2, -2), 0x00a0, 3 }, // Ground at (0, 2, -2)
                { GRID_DELTA(0, 3, -2), 0x0aaa, 2 }, // Water at (0, 3, -2)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 2, -1), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, -3), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, -1), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x008a, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0022, 3 }, // Ground at (-2, 1, 0)
                { GRID_DELTA(-2, 2, 0), 0x00a0, 3 }, // Ground at (-2, 2, 0)
                { GRID_DELTA(-2, 3, 0), 0x0aaa, 2 }, // Water at (-2, 3, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 2, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(-3, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 2, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0a80, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0820, 3 }, // Ground at (0, 1, 2)
                { GRID_DELTA(0, 2, 2), 0x00a0, 3 }, // Ground at (0, 2, 2)
                { GRID_DELTA(0, 3, 2), 0x0aaa, 2 }, // Water at (0, 3, 2)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 2 }, // +Y
                { GRID_DELTA(1, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 3), 0, 4 }, // +Z
                { GRID_DELTA(1, 2, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 3), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, 1), 0, 5 }, // -Z
            },
        },
    },
    // 39: TallHouseWater
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x00a2, 3 }, // Ground at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 0 }, // Farm at (1, 1, 0)
                { GRID_DELTA(0, 2, 0), 0x00a0, 3 }, // Ground at (0, 2, 0)
                { GRID_DELTA(0, 3, 0), 0x00a0, 3 }, // Ground at (0, 3, 0)
                { GRID_DELTA(0, 4, 0), 0x0aaa, 2 }, // Water at (0, 4, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 3, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 3, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 3, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 3, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x08a0, 3 }, // Ground at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 0 }, // Farm at (0, 1, -1)
                { GRID_DELTA(0, 2, 0), 0x00a0, 3 }, // Ground at (0, 2, 0)
                { GRID_DELTA(0, 3, 0), 0x00a0, 3 }, // Ground at (0, 3, 0)
                { GRID_DELTA(0, 4, 0), 0x0aaa, 2 }, // Water at (0, 4, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 3, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 3, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 3, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 3, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x00a8, 3 }, // Ground at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 0 }, // Farm at (-1, 1, 0)
                { GRID_DELTA(0, 2, 0), 0x00a0, 3 }, // Ground at (0, 2, 0)
                { GRID_DELTA(0, 3, 0), 0x00a0, 3 }, // Ground at (0, 3, 0)
                { GRID_DELTA(0, 4, 0), 0x0aaa, 2 }, // Water at (0, 4, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 3, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 3, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 3, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 3, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x02a0, 3 }, // Ground at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 0 }, // Farm at (0, 1, 1)
                { GRID_DELTA(0, 2, 0), 0x00a0, 3 }, // Ground at (0, 2, 0)
                { GRID_DELTA(0, 3, 0), 0x00a0, 3 }, // Ground at (0, 3, 0)
                { GRID_DELTA(0, 4, 0), 0x0aaa, 2 }, // Water at (0, 4, 0)
            },
            .n_out = 19,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 2, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 2, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 3, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 3, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 3, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 3, -1), 0, 5 }, // -Z
            },
        },
    },
    // 40: TallL
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0202, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x000a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x000a, 3 }, // Ground at (2, 0, 0)
                { GRID_DELTA(3, 0, 0), 0x0008, 3 }, // Ground at (3, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a00, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0800, 3 }, // Ground at (0, 0, 2)
            },
            .n_out = 26,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(4, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(3, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(3, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(3, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(3, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0802, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a00, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0a00, 3 }, // Ground at (0, 0, -2)
                { GRID_DELTA(0, 0, -3), 0x0200, 3 }, // Ground at (0, 0, -3)
                { GRID_DELTA(1, 0, 0), 0x000a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0008, 3 }, // Ground at (2, 0, 0)
            },
            .n_out = 26,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -3), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -3), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -3), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -3), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -4), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0808, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x000a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x000a, 3 }, // Ground at (-2, 0, 0)
                { GRID_DELTA(-3, 0, 0), 0x0002, 3 }, // Ground at (-3, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a00, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0200, 3 }, // Ground at (0, 0, -2)
            },
            .n_out = 26,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-4, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-3, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-3, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-3, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-3, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0208, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a00, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0a00, 3 }, // Ground at (0, 0, 2)
                { GRID_DELTA(0, 0, 3), 0x0800, 3 }, // Ground at (0, 0, 3)
                { GRID_DELTA(-1, 0, 0), 0x000a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0002, 3 }, // Ground at (-2, 0, 0)
            },
            .n_out = 26,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 3), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 3), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 3), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 3), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 4), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 41: Tower
    {
        { // rot 0
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 5 }, // Tower at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 1
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 5 }, // Tower at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 2
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 5 }, // Tower at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 3
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 5 }, // Tower at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
    },
    // 42: TowerOnGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 5 }, // Tower at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 43: WaterOnGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 44: Windmill
    {
        { // rot 0
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 1
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 2
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
        { // rot 3
            .n_cubes = 1,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0a2a, 4 }, // Windmill at (0, 0, 0)
            },
            .n_out = 1,
            .outer = {
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
            },
        },
    },
    // 45: WindmillOnGround
    {
        { // rot 0
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 2,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0020, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
            },
            .n_out = 5,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 46: WindmillRow
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a20, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0820, 3 }, // Ground at (0, 0, 2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, 1), 0x0aaa, 4 }, // Windmill at (0, 1, 1)
                { GRID_DELTA(0, 1, 2), 0x0aaa, 4 }, // Windmill at (0, 1, 2)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x002a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0028, 3 }, // Ground at (2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(1, 1, 0), 0x0aaa, 4 }, // Windmill at (1, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0aaa, 4 }, // Windmill at (2, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a20, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0220, 3 }, // Ground at (0, 0, -2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, -1), 0x0aaa, 4 }, // Windmill at (0, 1, -1)
                { GRID_DELTA(0, 1, -2), 0x0aaa, 4 }, // Windmill at (0, 1, -2)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x002a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0022, 3 }, // Ground at (-2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(-1, 1, 0), 0x0aaa, 4 }, // Windmill at (-1, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0aaa, 4 }, // Windmill at (-2, 1, 0)
            },
            .n_out = 11,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 47: WindmillRowMissing
    {
        { // rot 0
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0a00, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 0, 2), 0x0820, 3 }, // Ground at (0, 0, 2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, 2), 0x0aaa, 4 }, // Windmill at (0, 1, 2)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 3), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x000a, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(2, 0, 0), 0x0028, 3 }, // Ground at (2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(2, 1, 0), 0x0aaa, 4 }, // Windmill at (2, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0a00, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 0, -2), 0x0220, 3 }, // Ground at (0, 0, -2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(0, 1, -2), 0x0aaa, 4 }, // Windmill at (0, 1, -2)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 5,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x000a, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-2, 0, 0), 0x0022, 3 }, // Ground at (-2, 0, 0)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 4 }, // Windmill at (0, 1, 0)
                { GRID_DELTA(-2, 1, 0), 0x0aaa, 4 }, // Windmill at (-2, 1, 0)
            },
            .n_out = 12,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-2, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, -1), 0, 5 }, // -Z
            },
        },
    },
    // 48: zigzagFarm
    {
        { // rot 0
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0022, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0208, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, 1), 0x0a00, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(1, 0, 2), 0x0820, 3 }, // Ground at (1, 0, 2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(1, 1, 2), 0x0aaa, 2 }, // Water at (1, 1, 2)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 2), 0, 0 }, // +X
                { GRID_DELTA(0, 0, 2), 0, 1 }, // -X
                { GRID_DELTA(1, -1, 2), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 3), 0, 4 }, // +Z
            },
        },
        { // rot 1
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0820, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0202, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, -1), 0x000a, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(2, 0, -1), 0x0028, 3 }, // Ground at (2, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(2, 1, -1), 0x0aaa, 2 }, // Water at (2, 1, -1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(3, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(2, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(2, 0, 0), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0028, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0802, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, -1), 0x0a00, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(-1, 0, -2), 0x0220, 3 }, // Ground at (-1, 0, -2)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-1, 1, -2), 0x0aaa, 2 }, // Water at (-1, 1, -2)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 0 }, // +X
                { GRID_DELTA(-2, 0, -2), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -2), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -3), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 6,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0220, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0808, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 1), 0x000a, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(-2, 0, 1), 0x0022, 3 }, // Ground at (-2, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 0 }, // Farm at (0, 1, 0)
                { GRID_DELTA(-2, 1, 1), 0x0aaa, 2 }, // Water at (-2, 1, 1)
            },
            .n_out = 16,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, 0), 0, 5 }, // -Z
                { GRID_DELTA(-3, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-2, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-2, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 5 }, // -Z
            },
        },
    },
    // 49: ZigZagStepFarmWindmill
    {
        { // rot 0
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0222, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0208, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0802, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(1, 0, 1), 0x0828, 3 }, // Ground at (1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, 1), 0x00a0, 3 }, // Ground at (1, 1, 1)
                { GRID_DELTA(1, 2, 1), 0x0aaa, 4 }, // Windmill at (1, 2, 1)
            },
            .n_out = 18,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 0), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0822, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0202, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(1, 0, 0), 0x0808, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 0, -1), 0x0228, 3 }, // Ground at (1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(1, 1, -1), 0x00a0, 3 }, // Ground at (1, 1, -1)
                { GRID_DELTA(1, 2, -1), 0x0aaa, 4 }, // Windmill at (1, 2, -1)
            },
            .n_out = 18,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0828, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0802, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0208, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(-1, 0, -1), 0x0222, 3 }, // Ground at (-1, 0, -1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, -1), 0x00a0, 3 }, // Ground at (-1, 1, -1)
                { GRID_DELTA(-1, 2, -1), 0x0aaa, 4 }, // Windmill at (-1, 2, -1)
            },
            .n_out = 18,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 7,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0228, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0808, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(-1, 0, 0), 0x0202, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 0, 1), 0x0822, 3 }, // Ground at (-1, 0, 1)
                { GRID_DELTA(0, 1, 0), 0x0aaa, 2 }, // Water at (0, 1, 0)
                { GRID_DELTA(-1, 1, 1), 0x00a0, 3 }, // Ground at (-1, 1, 1)
                { GRID_DELTA(-1, 2, 1), 0x0aaa, 4 }, // Windmill at (-1, 2, 1)
            },
            .n_out = 18,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 1), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 0), 0, 5 }, // -Z
            },
        },
    },
    // 50: zigZagyStep
    {
        { // rot 0
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0200, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, 1), 0x0820, 3 }, // Ground at (0, 0, 1)
                { GRID_DELTA(0, 1, 1), 0x00a2, 3 }, // Ground at (0, 1, 1)
                { GRID_DELTA(1, 1, 1), 0x000a, 3 }, // Ground at (1, 1, 1)
                { GRID_DELTA(2, 1, 1), 0x0028, 3 }, // Ground at (2, 1, 1)
                { GRID_DELTA(0, 2, 1), 0x0aaa, 2 }, // Water at (0, 2, 1)
                { GRID_DELTA(2, 2, 1), 0x00a0, 3 }, // Ground at (2, 2, 1)
                { GRID_DELTA(2, 3, 1), 0x0aaa, 1 }, // House at (2, 3, 1)
            },
            .n_out = 24,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(1, 0, 1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 2), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, 0), 0, 5 }, // -Z
                { GRID_DELTA(1, 2, 1), 0, 2 }, // +Y
                { GRID_DELTA(1, 0, 1), 0, 3 }, // -Y
                { GRID_DELTA(1, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(1, 1, 0), 0, 5 }, // -Z
                { GRID_DELTA(3, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(2, 0, 1), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, 0), 0, 5 }, // -Z
                { GRID_DELTA(3, 2, 1), 0, 0 }, // +X
                { GRID_DELTA(1, 2, 1), 0, 1 }, // -X
                { GRID_DELTA(2, 2, 2), 0, 4 }, // +Z
                { GRID_DELTA(2, 2, 0), 0, 5 }, // -Z
            },
        },
        { // rot 1
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0002, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(1, 0, 0), 0x0028, 3 }, // Ground at (1, 0, 0)
                { GRID_DELTA(1, 1, 0), 0x08a0, 3 }, // Ground at (1, 1, 0)
                { GRID_DELTA(1, 1, -1), 0x0a00, 3 }, // Ground at (1, 1, -1)
                { GRID_DELTA(1, 1, -2), 0x0220, 3 }, // Ground at (1, 1, -2)
                { GRID_DELTA(1, 2, 0), 0x0aaa, 2 }, // Water at (1, 2, 0)
                { GRID_DELTA(1, 2, -2), 0x00a0, 3 }, // Ground at (1, 2, -2)
                { GRID_DELTA(1, 3, -2), 0x0aaa, 1 }, // House at (1, 3, -2)
            },
            .n_out = 24,
            .outer = {
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(2, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(1, 1, 1), 0, 4 }, // +Z
                { GRID_DELTA(2, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(1, 2, -1), 0, 2 }, // +Y
                { GRID_DELTA(1, 0, -1), 0, 3 }, // -Y
                { GRID_DELTA(2, 1, -2), 0, 0 }, // +X
                { GRID_DELTA(0, 1, -2), 0, 1 }, // -X
                { GRID_DELTA(1, 0, -2), 0, 3 }, // -Y
                { GRID_DELTA(1, 1, -3), 0, 5 }, // -Z
                { GRID_DELTA(2, 2, -2), 0, 0 }, // +X
                { GRID_DELTA(0, 2, -2), 0, 1 }, // -X
                { GRID_DELTA(1, 2, -1), 0, 4 }, // +Z
                { GRID_DELTA(1, 2, -3), 0, 5 }, // -Z
            },
        },
        { // rot 2
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0800, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(0, 0, -1), 0x0220, 3 }, // Ground at (0, 0, -1)
                { GRID_DELTA(0, 1, -1), 0x00a8, 3 }, // Ground at (0, 1, -1)
                { GRID_DELTA(-1, 1, -1), 0x000a, 3 }, // Ground at (-1, 1, -1)
                { GRID_DELTA(-2, 1, -1), 0x0022, 3 }, // Ground at (-2, 1, -1)
                { GRID_DELTA(0, 2, -1), 0x0aaa, 2 }, // Water at (0, 2, -1)
                { GRID_DELTA(-2, 2, -1), 0x00a0, 3 }, // Ground at (-2, 2, -1)
                { GRID_DELTA(-2, 3, -1), 0x0aaa, 1 }, // House at (-2, 3, -1)
            },
            .n_out = 24,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(1, 0, -1), 0, 0 }, // +X
                { GRID_DELTA(-1, 0, -1), 0, 1 }, // -X
                { GRID_DELTA(0, -1, -1), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, -2), 0, 5 }, // -Z
                { GRID_DELTA(1, 1, -1), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(0, 1, -2), 0, 5 }, // -Z
                { GRID_DELTA(-1, 2, -1), 0, 2 }, // +Y
                { GRID_DELTA(-1, 0, -1), 0, 3 }, // -Y
                { GRID_DELTA(-1, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(-1, 1, -2), 0, 5 }, // -Z
                { GRID_DELTA(-3, 1, -1), 0, 1 }, // -X
                { GRID_DELTA(-2, 0, -1), 0, 3 }, // -Y
                { GRID_DELTA(-2, 1, 0), 0, 4 }, // +Z
                { GRID_DELTA(-2, 1, -2), 0, 5 }, // -Z
                { GRID_DELTA(-1, 2, -1), 0, 0 }, // +X
                { GRID_DELTA(-3, 2, -1), 0, 1 }, // -X
                { GRID_DELTA(-2, 2, 0), 0, 4 }, // +Z
                { GRID_DELTA(-2, 2, -2), 0, 5 }, // -Z
            },
        },
        { // rot 3
            .n_cubes = 8,
            .place_blocks = {
                { GRID_DELTA(0, 0, 0), 0x0008, 3 }, // Ground at (0, 0, 0)
                { GRID_DELTA(-1, 0, 0), 0x0022, 3 }, // Ground at (-1, 0, 0)
                { GRID_DELTA(-1, 1, 0), 0x02a0, 3 }, // Ground at (-1, 1, 0)
                { GRID_DELTA(-1, 1, 1), 0x0a00, 3 }, // Ground at (-1, 1, 1)
                { GRID_DELTA(-1, 1, 2), 0x0820, 3 }, // Ground at (-1, 1, 2)
                { GRID_DELTA(-1, 2, 0), 0x0aaa, 2 }, // Water at (-1, 2, 0)
                { GRID_DELTA(-1, 2, 2), 0x00a0, 3 }, // Ground at (-1, 2, 2)
                { GRID_DELTA(-1, 3, 2), 0x0aaa, 1 }, // House at (-1, 3, 2)
            },
            .n_out = 24,
            .outer = {
                { GRID_DELTA(1, 0, 0), 0, 0 }, // +X
                { GRID_DELTA(0, 1, 0), 0, 2 }, // +Y
                { GRID_DELTA(0, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(0, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(0, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(-2, 0, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, -1, 0), 0, 3 }, // -Y
                { GRID_DELTA(-1, 0, 1), 0, 4 }, // +Z
                { GRID_DELTA(-1, 0, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 0), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, 0), 0, 1 }, // -X
                { GRID_DELTA(-1, 1, -1), 0, 5 }, // -Z
                { GRID_DELTA(0, 1, 1), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, 1), 0, 1 }, // -X
                { GRID_DELTA(-1, 2, 1), 0, 2 }, // +Y
                { GRID_DELTA(-1, 0, 1), 0, 3 }, // -Y
                { GRID_DELTA(0, 1, 2), 0, 0 }, // +X
                { GRID_DELTA(-2, 1, 2), 0, 1 }, // -X
                { GRID_DELTA(-1, 0, 2), 0, 3 }, // -Y
                { GRID_DELTA(-1, 1, 3), 0, 4 }, // +Z
                { GRID_DELTA(0, 2, 2), 0, 0 }, // +X
                { GRID_DELTA(-2, 2, 2), 0, 1 }, // -X
                { GRID_DELTA(-1, 2, 3), 0, 4 }, // +Z
                { GRID_DELTA(-1, 2, 1), 0, 5 }, // -Z
            },
        },
    },
};

#endif
