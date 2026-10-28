// GENERATED FILE, do not edit by hand.
// Map 1 (Waldsburg) progression ground truth, exported from Floating Frontiers
// gamepieces are gp_ids, the same ids as map1_gamepieces.h
#ifndef FF_MAP1_PROGRESSION_H
#define FF_MAP1_PROGRESSION_H

#include "../src/progression.h"

#define MAP1_NUM_LEVELS 15
#define MAP1_NUM_STAGES 9
#define MAP1_INFINITE_LEVEL_INCREASE 5 // past the last level, each level is this much longer than the one before

// make sure the data fits in the progression structs
_Static_assert(5 <= MAX_SPAWN_BUCKETS, "MAX_SPAWN_BUCKETS too small for map 1");
_Static_assert(8 <= MAX_SPAWNS_PER_BUCKET, "MAX_SPAWNS_PER_BUCKET too small for map 1");
_Static_assert(5 <= MAX_PRESET_HANDS, "MAX_PRESET_HANDS too small for map 1");
_Static_assert(5 <= MAX_PRESET_HAND_SIZE, "MAX_PRESET_HAND_SIZE too small for map 1");

// MAP1_BLOCK_POINTS[block_type][neighbor_type]: points a placed block of block_type gets for each
// block of neighbor_type in its 26 neighborhood (from a different gamepiece)
// block types: 0 = Farm, 1 = House, 2 = Water, 3 = Ground, 4 = Windmill, 5 = Tower, 6 = Blank
static const int8_t MAP1_BLOCK_POINTS[7][7] = {
    { 0, 0, 2, 0, 0, 0, 0 }, // Farm
    { 3, 0, 0, 0, 0, 0, 0 }, // House
    { 0, 0, 0, 0, 0, 0, 0 }, // Water
    { 0, 0, 0, 0, 0, 0, 0 }, // Ground
    { 2, 3, 0, 0, 0, 0, 0 }, // Windmill
    { 0, 4, 0, 0, 0, 0, 0 }, // Tower
    { 0, 0, 0, 0, 0, 0, 0 }, // Blank
};

static const DifficultyStage MAP1_STAGES[MAP1_NUM_STAGES] = {
    { // 0: FirstHand
        .use_preset_hand = 1,
        .n_buckets = 0,
        .n_preset_hands = 1,
        .preset_hands = {
            { .n = 5, .gp_ids = { 12, 43, 43, 2, 13 } },
        },
    },
    { // 1: WaterFarmIntro
        .use_preset_hand = 1,
        .n_buckets = 0,
        .n_preset_hands = 2,
        .preset_hands = {
            { .n = 4, .gp_ids = { 12, 43, 43, 2 } },
            { .n = 4, .gp_ids = { 13, 43, 43, 13 } },
        },
    },
    { // 2: HouseIntro
        .use_preset_hand = 1,
        .n_buckets = 0,
        .n_preset_hands = 5,
        .preset_hands = {
            { .n = 4, .gp_ids = { 13, 2, 16, 13 } },
            { .n = 4, .gp_ids = { 2, 43, 13, 15 } },
            { .n = 4, .gp_ids = { 2, 43, 13, 16 } },
            { .n = 4, .gp_ids = { 2, 43, 13, 16 } },
            { .n = 4, .gp_ids = { 2, 13, 15, 15 } },
        },
    },
    { // 3: WindmillIntro
        .use_preset_hand = 0,
        .n_buckets = 4,
        .buckets = {
            { .n_spawns = 3, .total_weight = 6, .spawns = { { 24, 2 }, { 43, 2 }, { 43, 2 } } }, // Water
            { .n_spawns = 2, .total_weight = 2, .spawns = { { 13, 1 }, { 12, 1 } } }, // Farms
            { .n_spawns = 2, .total_weight = 2, .spawns = { { 45, 1 }, { 44, 1 } } }, // Windmill
            { .n_spawns = 3, .total_weight = 4, .spawns = { { 2, 2 }, { 43, 1 }, { 13, 1 } } }, // GroundOrWaterOrFarm
        },
        .n_preset_hands = 0,
    },
    { // 4: TowerIntro
        .use_preset_hand = 0,
        .n_buckets = 3,
        .buckets = {
            { .n_spawns = 2, .total_weight = 2, .spawns = { { 43, 1 }, { 43, 1 } } }, // Water
            { .n_spawns = 2, .total_weight = 2, .spawns = { { 15, 1 }, { 16, 1 } } }, // House
            { .n_spawns = 2, .total_weight = 2, .spawns = { { 41, 1 }, { 42, 1 } } }, // Tower
        },
        .n_preset_hands = 0,
    },
    { // 5: FlatBlockMultiplesIntro
        .use_preset_hand = 0,
        .n_buckets = 4,
        .buckets = {
            { .n_spawns = 5, .total_weight = 5, .spawns = { { 8, 1 }, { 22, 1 }, { 4, 1 }, { 28, 1 }, { 18, 1 } } }, // HouseMultiple
            { .n_spawns = 3, .total_weight = 5, .spawns = { { 24, 2 }, { 9, 1 }, { 25, 2 } } }, // WaterMultiple
            { .n_spawns = 3, .total_weight = 6, .spawns = { { 20, 2 }, { 7, 2 }, { 29, 2 } } }, // FarmMultiple
            { .n_spawns = 2, .total_weight = 3, .spawns = { { 2, 1 }, { 12, 2 } } }, // GroundOrFarm
        },
        .n_preset_hands = 0,
    },
    { // 6: SingleStepIntro
        .use_preset_hand = 0,
        .n_buckets = 4,
        .buckets = {
            { .n_spawns = 2, .total_weight = 4, .spawns = { { 30, 3 }, { 32, 1 } } }, // HouseStep
            { .n_spawns = 2, .total_weight = 4, .spawns = { { 24, 2 }, { 33, 2 } } }, // WaterMultiple
            { .n_spawns = 3, .total_weight = 6, .spawns = { { 29, 2 }, { 20, 2 }, { 31, 2 } } }, // FarmMultiple
            { .n_spawns = 2, .total_weight = 4, .spawns = { { 44, 2 }, { 2, 2 } } }, // GroundOrWindmill
        },
        .n_preset_hands = 0,
    },
    { // 7: StepBlockIntro
        .use_preset_hand = 0,
        .n_buckets = 4,
        .buckets = {
            { .n_spawns = 2, .total_weight = 3, .spawns = { { 34, 2 }, { 29, 1 } } }, // Farm
            { .n_spawns = 4, .total_weight = 4, .spawns = { { 23, 1 }, { 38, 1 }, { 33, 1 }, { 9, 1 } } }, // Water
            { .n_spawns = 6, .total_weight = 10, .spawns = { { 36, 1 }, { 37, 1 }, { 39, 2 }, { 35, 2 }, { 30, 2 }, { 47, 2 } } }, // HousesOrWindmill
            { .n_spawns = 4, .total_weight = 11, .spawns = { { 3, 3 }, { 2, 6 }, { 42, 1 }, { 41, 1 } } }, // SimpleOrTower
        },
        .n_preset_hands = 0,
    },
    { // 8: FinalStage
        .use_preset_hand = 0,
        .n_buckets = 5,
        .buckets = {
            { .n_spawns = 6, .total_weight = 12, .spawns = { { 9, 2 }, { 23, 2 }, { 33, 2 }, { 36, 2 }, { 38, 2 }, { 25, 2 } } }, // Water
            { .n_spawns = 6, .total_weight = 15, .spawns = { { 7, 2 }, { 20, 2 }, { 29, 2 }, { 48, 2 }, { 31, 2 }, { 34, 5 } } }, // Farms
            { .n_spawns = 8, .total_weight = 23, .spawns = { { 8, 2 }, { 6, 2 }, { 36, 2 }, { 35, 5 }, { 35, 2 }, { 17, 2 }, { 30, 4 }, { 18, 4 } } }, // Houses
            { .n_spawns = 8, .total_weight = 11, .spawns = { { 46, 2 }, { 10, 2 }, { 27, 2 }, { 41, 1 }, { 42, 1 }, { 4, 1 }, { 11, 1 }, { 47, 1 } } }, // WindmillOrTower
            { .n_spawns = 5, .total_weight = 5, .spawns = { { 12, 1 }, { 16, 1 }, { 2, 1 }, { 21, 1 }, { 45, 1 } } }, // SimpleBlocks(NoTower)
        },
        .n_preset_hands = 0,
    },
};

// the score threshold that passes each level
// stage_id is the stage hands are dealt from while the score is below this level's threshold
// (and at or above the previous level's)
static const LevelData MAP1_LEVELS[MAP1_NUM_LEVELS] = {
    { 4, 0 }, // +4, FirstHand
    { 8, 1 }, // +4, WaterFarmIntro
    { 13, 1 }, // +5, WaterFarmIntro
    { 19, 2 }, // +6, HouseIntro
    { 28, 2 }, // +9, HouseIntro
    { 43, 3 }, // +15, WindmillIntro
    { 58, 4 }, // +15, TowerIntro
    { 73, 3 }, // +15, WindmillIntro
    { 93, 5 }, // +20, FlatBlockMultiplesIntro
    { 115, 6 }, // +22, SingleStepIntro
    { 139, 5 }, // +24, FlatBlockMultiplesIntro
    { 169, 6 }, // +30, SingleStepIntro
    { 201, 7 }, // +32, StepBlockIntro
    { 236, 7 }, // +35, StepBlockIntro
    { 274, 8 }, // +38, FinalStage
};

#endif
