#include "progression.h"
#include "state.h"

// the generated ground truth data. only included here, so the tables exist once
#include "../data/map1_progression.h"

// RNG: generate random number between 0 and n, seeded by each env state

static uint64_t rng_next(GameState* gstate){
    // produce the next random number for this state

    // splitmix64: tiny state (one uint64_t) and good enough statistics for dealing cards

    // move the rng state value by a large odd number, ensuring state loops and visits each number
    uint64_t z = (gstate->rng_state += 0x9E3779B97F4A7C15ull);

    // rng state increments in a predictable way, looping through all the uint64_t values
    // we take it current value and apply some arbitrary scrambling to it to make it look random
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ull;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBull;
    return z ^ (z >> 31);
}

uint32_t rng_range(GameState* gstate, uint32_t n){
    // Return random number from 0 to n
    // top 32 bits * n >> 32 maps uniformly onto [0, n) without a modulo
    return (uint32_t)(((rng_next(gstate) >> 32) * (uint64_t)n) >> 32);
}

// LEVELS: get level data from floating frontiers ground truth data

int32_t get_level_threshold(int32_t level_idx){
    // level 0 is the start of the game, so level i's threshold is MAP1_LEVELS[i - 1]
    if(level_idx <= 0) return 0;
    if(level_idx <= MAP1_NUM_LEVELS) return MAP1_LEVELS[level_idx - 1].threshold;

    // beyond the preset levels: fake levels, growing by the last level's size plus m more every level
    int32_t last = MAP1_LEVELS[MAP1_NUM_LEVELS - 1].threshold;
    int32_t level_diff = last - MAP1_LEVELS[MAP1_NUM_LEVELS - 2].threshold;
    int32_t n = level_idx - MAP1_NUM_LEVELS; // levels beyond the limit
    return last + level_diff * n + MAP1_INFINITE_LEVEL_INCREASE * ((n * (n + 1)) / 2);
}

uint8_t get_stage_id_for_score(int32_t score){
    // get the stage id that the score is in. Ie if score is 20 and level is 18-25, return that level
    
    for(int i = 0; i < MAP1_NUM_LEVELS; i++){
        // if the next threshold (end end of the current level) is above cur score,
        if(MAP1_LEVELS[i].threshold > score) return MAP1_LEVELS[i].stage_id;
    }
    return MAP1_LEVELS[MAP1_NUM_LEVELS - 1].stage_id; // beyond all the levels, use the last level
}

const DifficultyStage* get_stage(uint8_t stage_id){
    return &MAP1_STAGES[stage_id];
}

uint8_t get_num_stages(void){
    return MAP1_NUM_STAGES;
}

int8_t get_block_points(uint8_t block_type, uint8_t neighbor_type){
    return MAP1_BLOCK_POINTS[block_type][neighbor_type];
}

// ---------- hand ----------

void add_to_hand(GameState* gstate, uint8_t gp_id){
    if(gstate->hand_len >= MAX_HAND_SIZE) return; // never happens in a real game; drop instead of overflowing
    gstate->hand[gstate->hand_len] = gp_id;
    gstate->hand_len++;
}

uint8_t remove_from_hand(GameState* gstate, uint8_t gp_id){
    // remove a gamepiece, by id, from the current state's hand
    // hand order doesn't matter, so swap the last card into the hole to keep hand contiguous
    for(uint16_t i = 0; i < gstate->hand_len; i++){
        if(gstate->hand[i] != gp_id) continue;
        gstate->hand_len--;
        gstate->hand[i] = gstate->hand[gstate->hand_len];
        return 1;
    }
    return 0;
}

static uint8_t pick_from_bucket(GameState* gstate, const SpawnBucket* bucket){
    // Pull a signle random card from a bucket, weighted by each card's weight/total weight

    // random weight in [0, total), then walk the cumulative weights
    uint32_t random_weight = rng_range(gstate, bucket->total_weight);
    uint32_t weight_sum = 0;
    for(uint8_t i = 0; i < bucket->n_spawns; i++){
        weight_sum += bucket->spawns[i].weight;
        if(random_weight < weight_sum) return bucket->spawns[i].gp_id;
    }
    return bucket->spawns[bucket->n_spawns - 1].gp_id; // unreachable, since random_weight < total_weight
}

void deal_hand(GameState* gstate, int32_t score){
    // deal the hand that score most recenlty passed
    // ie if score is 20 then deal the most recent level hand, such as cards
    // you would have gained when passing score 18

    const DifficultyStage* stage = get_stage(get_stage_id_for_score(score));
    if(stage->use_preset_hand){
        const PresetHand* preset = &stage->preset_hands[rng_range(gstate, stage->n_preset_hands)];
        for(uint8_t i = 0; i < preset->n; i++) add_to_hand(gstate, preset->gp_ids[i]);
        return;
    }
    for(uint8_t i = 0; i < stage->n_buckets; i++){
        add_to_hand(gstate, pick_from_bucket(gstate, &stage->buckets[i]));
    }
}

// ---------- game flow ----------

void start_progression(GameState* gstate, uint64_t seed){
    gstate->rng_seed = seed;
    gstate->rng_state = seed;
    gstate->score = 0;
    gstate->level_idx = 0;
    gstate->hand_len = 0;
    deal_hand(gstate, 0);
    gstate->game_over = gstate->hand_len == 0;
}

void check_level_passes(GameState* gstate){
    // pass thresholds one at a time, dealing deal_hand(threshold + 1) for each
    int32_t next_threshold = get_level_threshold(gstate->level_idx + 1);
    while(gstate->score >= next_threshold){
        deal_hand(gstate, next_threshold + 1);
        gstate->level_idx++;
        next_threshold = get_level_threshold(gstate->level_idx + 1);
    }
    // lose once every threshold is dealt and the hand is still empty
    gstate->game_over = gstate->hand_len == 0;
}
