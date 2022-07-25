#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_spanish.h"
#include "keymap_us_international.h"

// To avoid ccls complaining
#include "dummy_includes.h"

#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define MOON_LED_LEVEL LED_LEVEL
#define MY_CARET LT(0, KC_CIRC)

enum custom_keycodes {
  VIM_W = ML_SAFE_RANGE,
  VIM_O,
};

// Abbreviations
#define WCTL(key) (MT(MOD_LCTL, key))
#define WSFT(key) (MT(MOD_LSFT, key))

enum layers {
    QWERTY,
    SYMBOLS,
    VIMISH,
    MOUSE_AND_MEDIA,
    GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_moonlander(
    KC_GRAVE ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   ,  XXXXXXX,               KC_EQUAL ,  KC_6   ,  KC_7   ,   KC_8   ,  KC_9   ,  KC_0   ,  KC_MINUS,
    KC_DELETE,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,  XXXXXXX,               TG(1)    ,  KC_Y   ,  KC_U   ,   KC_I   ,  KC_O   ,  KC_P   ,  KC_BSLS ,
    KC_BSPACE,  KC_A   ,  KC_S   ,  KC_D   ,LT(2,KC_F), KC_G   ,  XXXXXXX,               XXXXXXX  ,  KC_H   ,  KC_J   ,   KC_K   ,  KC_L   ,LT(3,KC_SCOLON),MT(MOD_LGUI, KC_QUOTE),
WSFT(KC_ESC), WCTL(KC_Z), KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                                     KC_N   ,  KC_M   ,  KC_COMMA,  KC_DOT ,MT(MOD_RCTL, KC_SLASH),KC_RSHIFT,
    KC_LCTRL ,  XXXXXXX,  XXXXXXX,  KC_LEFT, KC_RIGHT,                     TG(2), TG(4)                     ,  KC_UP  ,  KC_DOWN ,  XXXXXXX,  XXXXXXX, CAPS_WORD,
                                            KC_SPACE ,  KC_LALT,  KC_LGUI,               KC_RALT,  LT(1,KC_TAB),   KC_ENTER
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_ESC   ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  _______,               _______  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,
    _______  ,  KC_EXLM,  KC_AT  ,  KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,               _______  , KC_MINUS,  KC_7   ,  KC_8   ,  KC_9   ,  KC_ASTR,  KC_F12 ,
    _______  ,  KC_HASH,  KC_DLR ,  KC_LPRN,  KC_RPRN, KC_GRAVE,  _______,               _______  ,  KC_UNDS,  KC_4   ,  KC_5   ,  KC_6   ,  KC_EQL ,  KC_PPLS,
    _______  ,  KC_PERC, MY_CARET,  KC_LBRC,  KC_RBRC,  KC_TILD,                                     KC_AMPR,  KC_1   ,  KC_2   ,  KC_3   ,  KC_BSLS,  _______,
    _______  , KC_COMMA,  _______,  RGB_VAD,  RGB_VAI,                   RGB_MOD, RGB_TOG                   ,  _______,  KC_0   ,  KC_DOT ,  _______,  _______,
                                              _______,  _______,  _______,               _______  ,  _______,  _______
  ),
  [VIMISH] = LAYOUT_moonlander(
    _______  ,  _______,  _______,  _______,  _______,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______  ,  _______,  VIM_W  ,C(KC_RGHT), _______,  _______,  _______,               _______,  _______,  _______,  TO(0)  ,  VIM_O  , _______, _______,
    _______  ,  TO(0)  ,  _______,C(KC_DEL),  _______,  _______,  _______,               _______,  KC_LEFT,  KC_DOWN,  KC_UP  , KC_RIGHT,  _______,  _______,
    _______  ,  _______,  _______,  _______,  _______,C(KC_LEFT),                                  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,  _______,  _______,
    _______  ,  _______,  _______,  _______,  _______,                  _______, _______                  ,  _______,  _______,  _______,  _______,  _______,
                                              _______,  _______,  _______,               _______,  _______,  _______
  ),
  [MOUSE_AND_MEDIA] = LAYOUT_moonlander(
    _______  , _______,  _______,  _______,  _______,  _______,  _______,                _______,  _______,  _______,  _______,  _______,  _______,  RESET,
    _______  , _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,                _______,  _______,  _______,  _______,  _______,  _______, _______,
    _______  , _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,                _______,  _______,  _______,  _______,  _______,  _______,KC_MEDIA_PLAY_PAUSE,
    _______  , _______,  _______,  _______,  _______,  _______,                                    _______,  _______,  _______,  _______,  _______,  _______,
    _______  , _______,  _______,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______,_______                  ,  KC_VOLU,  KC_VOLD,  KC_MUTE,_______,_______,
                                             _______  , _______,  _______,               _______,  KC_WBAK,  KC_WFWD
  ),
  [GAMING] = LAYOUT_moonlander(
    KC_ESC   ,  _______,  _______,  _______,  _______,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_TAB   ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_CAPS  ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  _______,  _______,               _______,  _______,  _______,  _______,  KC_UP  ,  _______,  _______,
    KC_LSHIFT,  KC_Z   ,  KC_X   ,  KC_C   ,  _______,  _______,                                   _______,  _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,  _______,
    KC_LCTRL ,  _______,  _______,  _______,  _______,                  _______, _______                  ,  _______,  _______,  _______,  _______,  _______,
                                            KC_SPACE ,  _______,  _______,               _______,  _______,  _______
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  uint8_t layer = biton32(layer_state);
  if(SYMBOLS == layer || VIMISH == layer || MOUSE_AND_MEDIA == layer || GAMING == layer)
      set_layer_color(layer);
  else if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIM_W:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(100) SS_TAP(X_RIGHT));
      }
      break;
    case VIM_O:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) SS_DELAY(100) SS_TAP(X_ENTER));
        layer_move(QWERTY);
        return false;
      }
      break;
    case LT(0, KC_CIRC):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(C(KC_6));    // On hold send ctrl-^ (buffer swap)
        return false;
      }
      if (record->event.pressed) {
          tap_code16(KC_CIRC);  // On tap send ^
      }
      return false;
  }
  return true;
}


