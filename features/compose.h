#pragma once

#include "quantum.h"
#include "../dummy_includes.h"

#define COMPOSE LT(0, KC_RALT)

bool process_record_compose(uint16_t keycode, keyrecord_t* record);

