#pragma once

#include "quantum.h"
#include "../layers.h"

bool process_record_vim(uint16_t keycode, keyrecord_t* record);

void layer_state_set_vim(layer_state_t state);

uint8_t get_active_mods(void);

