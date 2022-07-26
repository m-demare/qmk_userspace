#pragma once

#include "quantum.h"
#include "../dummy_includes.h"
#include "../layers.h"

bool process_record_vim(uint16_t keycode, keyrecord_t* record);

void layer_state_set_vim(layer_state_t state);

