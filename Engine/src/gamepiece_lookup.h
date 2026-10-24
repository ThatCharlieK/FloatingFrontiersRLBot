#ifndef FF_GAMEPIECE_LOOKUP_H
#define FF_GAMEPIECE_LOOKUP_H

#include <stdint.h>

#include "gamepiece_data.h"

/*
Lookup api for the precomputed gamepiece data (data/map1_gamepieces.h).
The table is shared and read only, so every GameState can use it at the same time.
gp_id is the index into map 1's GamepieceDatabase.allGamepieces list.
*/

// number of gamepieces in the map
uint16_t get_num_gamepieces(void);

// the gamepiece the game starts with (1x1GroundWithHouse)
uint8_t get_initial_gamepiece_id(void);

// precomputed data for gamepiece gp_id rotated rot * 90 degrees clockwise (rot 0-3). Don't modify it
gamepiece_rot* get_gamepiece_rot(uint8_t gp_id, uint8_t rot);

// gamepiece name in unity, for debugging
const char* get_gamepiece_name(uint8_t gp_id);

#endif
