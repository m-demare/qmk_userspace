#pragma once

#include "quantum.h"

#define COMPOSE LT(0, KC_MENU)

bool process_record_compose(uint16_t keycode, keyrecord_t* record);

