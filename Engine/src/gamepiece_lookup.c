#include "gamepiece_lookup.h"

// the generated ground truth data. only included here, so the table exists once
#include "../data/map1_gamepieces.h"

uint16_t get_num_gamepieces(void){
    return MAP1_NUM_GAMEPIECES;
}

uint8_t get_initial_gamepiece_id(void){
    return MAP1_INITIAL_GAMEPIECE_ID;
}

gamepiece_rot* get_gamepiece_rot(uint8_t gp_id, uint8_t rot){
    return &MAP1_GAMEPIECE_ROTS[gp_id][rot];
}

const char* get_gamepiece_name(uint8_t gp_id){
    return MAP1_GAMEPIECE_NAMES[gp_id];
}
