#include <stdlib.h>

#include "ffapi.h"
#include "state.h"
#include "gamepiece_lookup.h"

struct FFBatch{
    uint32_t n_games;
    uint64_t next_seed; // seed for the next game started
    GameState** games;
    // each game's legal actions, cached so ff_step can look up an index from the last observation.
    // one MAX_VALID_GP_ROT sized buffer per game
    valid_action** legal;
    uint32_t* n_legal;
};

static void refresh_legal(FFBatch* batch, uint32_t i){
    get_all_valid_gamepiece_rot(batch->games[i], batch->legal[i], &batch->n_legal[i]);
}

static void start_game(FFBatch* batch, uint32_t i){
    // (re)start slot i with the next seed. reuses the GameState, since reallocating its grid is slow
    if(batch->games[i]) reset_GameState(batch->games[i], batch->next_seed++);
    else batch->games[i] = init_GameState(batch->next_seed++);
    refresh_legal(batch, i);
}

FFBatch* ff_create(uint32_t n_games, uint64_t base_seed){
    FFBatch* batch = calloc(1, sizeof(FFBatch));
    batch->n_games = n_games;
    batch->next_seed = base_seed;
    batch->games = calloc(n_games, sizeof(GameState*));
    batch->legal = calloc(n_games, sizeof(valid_action*));
    batch->n_legal = calloc(n_games, sizeof(uint32_t));
    for(uint32_t i = 0; i < n_games; i++){
        batch->legal[i] = malloc(sizeof(valid_action) * MAX_VALID_GP_ROT);
        start_game(batch, i);
    }
    return batch;
}

void ff_destroy(FFBatch* batch){
    if(!batch) return;
    for(uint32_t i = 0; i < batch->n_games; i++){
        free_GameState(batch->games[i]);
        free(batch->legal[i]);
    }
    free(batch->games);
    free(batch->legal);
    free(batch->n_legal);
    free(batch);
}

void ff_reset(FFBatch* batch){
    for(uint32_t i = 0; i < batch->n_games; i++) start_game(batch, i);
}

int32_t ff_observe(FFBatch* batch,
                   float* placed, uint32_t max_placed, uint32_t* n_placed,
                   float* hand, uint32_t max_hand, uint32_t* n_hand,
                   float* actions, uint32_t max_actions, uint32_t* n_actions,
                   int32_t* scores){
    int32_t truncated = 0;

    for(uint32_t g = 0; g < batch->n_games; g++){
        GameState* gstate = batch->games[g];

        // placed cubes: [x, y, z, bit1 ... bit15]
        uint32_t np = gstate->placed_len;
        if(np > max_placed){ np = max_placed; truncated = 1; }
        float* out = placed + (size_t)g * max_placed * FF_PLACED_FEATURES;
        for(uint32_t i = 0; i < np; i++){
            uint32_t idx = gstate->placed[i];
            uint16_t cell = gstate->grid[idx];
            float* row = out + (size_t)i * FF_PLACED_FEATURES;
            row[0] = (float)(idx % GX);
            row[1] = (float)((idx / GX) % GY);
            row[2] = (float)(idx / (GX * GY));
            for(int b = 1; b < 16; b++) row[2 + b] = (float)((cell >> b) & 1);
        }
        n_placed[g] = np;

        // hand: [gp_id]
        uint32_t nh = gstate->hand_len;
        if(nh > max_hand){ nh = max_hand; truncated = 1; }
        float* hout = hand + (size_t)g * max_hand * FF_HAND_FEATURES;
        for(uint32_t i = 0; i < nh; i++) hout[i] = (float)gstate->hand[i];
        n_hand[g] = nh;

        // legal actions: [gp_id, x, y, z, rot]
        uint32_t na = batch->n_legal[g];
        if(na > max_actions){ na = max_actions; truncated = 1; }
        float* aout = actions + (size_t)g * max_actions * FF_ACTION_FEATURES;
        for(uint32_t i = 0; i < na; i++){
            valid_action a = batch->legal[g][i];
            float* row = aout + (size_t)i * FF_ACTION_FEATURES;
            row[0] = (float)a.gp_id;
            row[1] = (float)a.x;
            row[2] = (float)a.y;
            row[3] = (float)a.z;
            row[4] = (float)a.rot;
        }
        n_actions[g] = na;

        scores[g] = gstate->score;
    }
    return truncated;
}

int32_t ff_step(FFBatch* batch, const int32_t* action_idx,
                int32_t* rewards, uint8_t* dones, int32_t* final_scores){
    // validate every index first, so a bad call leaves every game untouched
    for(uint32_t g = 0; g < batch->n_games; g++){
        if(action_idx[g] < 0 || (uint32_t)action_idx[g] >= batch->n_legal[g]) return -1;
    }

    for(uint32_t g = 0; g < batch->n_games; g++){
        GameState* gstate = batch->games[g];
        valid_action a = batch->legal[g][action_idx[g]];

        int32_t before = gstate->score;
        place_gamepiece(gstate, a.gp_id, a.rot, cell_index(a.x, a.y, a.z));
        rewards[g] = gstate->score - before;
        final_scores[g] = gstate->score;

        refresh_legal(batch, g);
        // over when the hand is empty, or when nothing left in it can be placed
        dones[g] = gstate->game_over || batch->n_legal[g] == 0;
        if(dones[g]) start_game(batch, g);
    }
    return 0;
}

uint32_t ff_max_actions(void){ return MAX_VALID_GP_ROT; }
uint32_t ff_max_hand(void){ return MAX_HAND_SIZE; }
uint32_t ff_num_gamepieces(void){ return get_num_gamepieces(); }
