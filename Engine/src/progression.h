#ifndef FF_PROGRESSION_H
#define FF_PROGRESSION_H

#include <stdint.h>

/*
Leveling and hand logic, ported directly from the unity game

How a game progresses:
- start: deal_hand(0)
- every time the score reaches the next threshold, deal_hand(threshold + 1) and ADD it to the hand.
  One placement can pass several thresholds, and each one deals a hand
- deal_hand(score) deals from the difficulty stage of the level the score is in
- the game is lost when the hand is empty after all thresholds are dealt
*/

// sized to map 1. data/map1_progression.h static asserts that its data fits
#define MAX_SPAWN_BUCKETS 5
#define MAX_SPAWNS_PER_BUCKET 8
#define MAX_PRESET_HANDS 5
#define MAX_PRESET_HAND_SIZE 5


/*
Aside from a preset hand, for a new level, each card in the hand is drawn from a spawn bucket. Ex:

Bucket1: water, waterOnGround, 2xWaterOnGround
bucket2: farm, farm on ground, 2xfarmOnGround
bucket3: house, houseOnGround, 2xHouse

For each bucket a single gamepiece (by gp_id) is selected selected, with weighted probailities.
So for bucket1, for ex:
water: 3
waterOnGround: 4
2xWaterOnGround: 1

So the change of drawing water is 3/(3+4+1) = 3/8
*/

typedef struct{
    uint8_t gp_id;
    uint16_t weight; // chance of this gamepiece is weight / total_weight of its bucket
} SpawnWeight;

typedef struct{
    // one card of a dealt hand. Picks one gamepiece, weighted
    uint8_t n_spawns;
    uint32_t total_weight; // sum of every spawn's weight
    SpawnWeight spawns[MAX_SPAWNS_PER_BUCKET];
} SpawnBucket;

// level generation

typedef struct{
    uint8_t n;
    uint8_t gp_ids[MAX_PRESET_HAND_SIZE];
} PresetHand;

typedef struct{
    // the hand drawing odds for a level.
    // use_preset_hand: deal one of preset_hands, picked uniformly at random
    // otherwise: deal one card per bucket, in bucket order
    uint8_t use_preset_hand;
    uint8_t n_buckets;
    SpawnBucket buckets[MAX_SPAWN_BUCKETS];
    uint8_t n_preset_hands;
    PresetHand preset_hands[MAX_PRESET_HANDS];
} DifficultyStage;

typedef struct{
    int32_t threshold; // score needed to pass this level
    uint8_t stage_id; // index into the map's stages: what hands are dealt from while in this level
} LevelData;

// GameState is in state.h, which includes this file
struct GameState;

// ---------- rng ----------
// every GameState has its own rng, so a game is reproducible from its seed

// uniform in [0, n)
uint32_t rng_range(struct GameState* gstate, uint32_t n);

// ---------- levels ----------

// score needed to pass level_idx. level 0 is 0
int32_t get_level_threshold(int32_t level_idx);
// the stage that deal_hand(score) deals from
uint8_t get_stage_id_for_score(int32_t score);
const DifficultyStage* get_stage(uint8_t stage_id);
uint8_t get_num_stages(void);
// points a block of block_type gets for each neighbor of neighbor_type
int8_t get_block_points(uint8_t block_type, uint8_t neighbor_type);

// ---------- hand ----------

void add_to_hand(struct GameState* gstate, uint8_t gp_id);
// removes one copy of gp_id. returns 0 if it wasn't in the hand
uint8_t remove_from_hand(struct GameState* gstate, uint8_t gp_id);
// deal a hand from score's stage and add it to the hand
void deal_hand(struct GameState* gstate, int32_t score);

// ---------- game flow ----------

// seed the rng, reset score/level/hand and deal the first hand
void start_progression(struct GameState* gstate, uint64_t seed);
// call after a placement has added its points to the score: deals a hand for every
// threshold passed, then sets game_over if the hand is empty
void check_level_passes(struct GameState* gstate);

#endif
