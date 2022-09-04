#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "layers.h"
#include "features/compose.h"
#include "features/vim_mode.h"


// To avoid ccls complaining
#include "dummy_includes.h"

#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    VIM_W = ML_SAFE_RANGE,
    VIM_O,
};

// Abbreviations
#define CTLT(kc) MT(MOD_LCTL, KC_##kc)
#define RCTLT(kc) MT(MOD_RCTL, KC_##kc)
#define SFTT(key) (MT(MOD_LSFT, KC_##key))
#define LGUIT(kc) MT(MOD_LGUI, KC_##kc)
#define SYM SYMBOLS
#define VIM VIMISH
#define MY_SCLN LT(MOUSE_AND_MEDIA,KC_SCLN)

// Special keys
#define MY_CARET LT(0, KC_CIRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_moonlander(
        KC_GRAVE ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   ,  XXXXXXX,               KC_EQUAL ,  KC_6   ,  KC_7   ,   KC_8  ,  KC_9   ,  KC_0   , KC_MINUS,
        KC_DELETE,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,  XXXXXXX,               TG(SYM)  ,  KC_Y   ,  KC_U   ,   KC_I  ,  KC_O   ,  KC_P   ,  KC_BSLS,
        KC_BSPACE,  KC_A   ,  KC_S   ,  KC_D   ,LT(VIM,KC_F),KC_G  ,  XXXXXXX,               XXXXXXX  ,  KC_H   ,  KC_J   ,   KC_K  ,  KC_L   ,MY_SCLN,LGUIT(QUOT),
        SFTT(ESC),  CTLT(Z),  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                                     KC_N   ,  KC_M   , KC_COMMA,  KC_DOT ,RCTLT(SLSH),KC_RSFT,
        KC_LCTRL ,  XXXXXXX,  XXXXXXX,  KC_LEFT, KC_RIGHT,                   TG(VIM), TG(GAMING)                ,  KC_UP  ,  KC_DOWN,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                KC_SPACE ,  KC_LALT,  KC_LGUI,               COMPOSE,LT(SYM,KC_TAB),KC_ENTER
    ),
    [VIMISH] = LAYOUT_moonlander(
        _______  ,  _______,  _______,  _______,  _______,  _______,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,  _______,
        _______  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,  _______,               _______  ,  KC_Y   ,  KC_U   ,   KC_I  ,  KC_O   ,  KC_P   ,  _______,
        _______  ,  KC_A   ,  KC_S   ,  KC_D   ,  _______,  KC_G   ,  _______,               _______  ,  KC_H   ,  KC_J   ,   KC_K  ,  KC_L   ,  _______,  _______,
        _______  ,  CTLT(Z),  KC_X   ,  KC_C   ,  KC_V   ,  KC_B,                                        KC_N   ,  KC_M   , KC_COMMA,  KC_DOT ,  _______,  _______,
        _______  ,  _______,  _______,  _______,  _______,                  _______, _______                    ,  _______,  _______,  _______,  _______,  _______,
                                                  _______,  _______,  _______,               _______  ,  _______,  _______
    ),
    [SYMBOLS] = LAYOUT_moonlander(
        KC_ESC   ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  _______,               _______  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,
        _______  ,  KC_EXLM,  KC_AT  ,  KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,               _______  , KC_MINUS,  KC_7   ,  KC_8   ,  KC_9   ,  KC_ASTR,  KC_F12 ,
        _______  ,  KC_HASH,  KC_DLR ,  KC_LPRN,  KC_RPRN, KC_GRAVE,  _______,               _______  ,  KC_UNDS,  KC_4   ,  KC_5   ,  KC_6   ,  KC_EQL ,  KC_PPLS,
        _______  ,  KC_PERC, MY_CARET,  KC_LBRC,  KC_RBRC,  KC_TILD,                                     KC_AMPR,  KC_1   ,  KC_2   ,  KC_3   ,  KC_BSLS,  _______,
        _______  , KC_COMMA,  _______,  RGB_VAD,  RGB_VAI,                   RGB_MOD, RGB_TOG                   ,  _______,  KC_0   ,  KC_DOT ,  _______,  _______,
                                                  _______,  _______,  _______,               _______  ,  _______,  _______
    ),
    [MOUSE_AND_MEDIA] = LAYOUT_moonlander(
        _______  ,  _______,  _______,  _______,  _______,  _______,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,    RESET,
        _______  ,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,  _______,
        _______  ,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,  KC_MPLY,
        _______  ,  _______,  _______,  _______,  _______,  _______,                                     _______,  _______,  _______,  _______,  _______,  _______,
        _______  ,  _______,  _______,  KC_MPRV,  KC_MNXT,                   _______,_______                    ,  KC_VOLU,  KC_VOLD,  KC_MUTE,  _______,  _______,
                                                _______  ,  _______,  _______,               _______  ,  KC_WBAK,  KC_WFWD
    ),
    [GAMING] = LAYOUT_moonlander(
        KC_ESC   ,  _______,  _______,  _______,  _______,  _______,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_TAB   ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  _______,  _______,               _______  ,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_CAPS  ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  _______,  _______,               _______  ,  _______,  _______,  _______,  KC_UP  ,  _______,  _______,
        KC_LSHIFT,  KC_Z   ,  KC_X   ,  KC_C   ,  _______,  _______,                                     _______,  _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,  _______,
        KC_LCTRL ,  _______,  _______,  _______,  _______,                  _______, _______                    ,  _______,  _______,  _______,  _______,  _______,
                                                KC_SPACE ,  _______,  _______,               _______  ,  _______,  _______
    ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [VIMISH] = { {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210} },

    [SYMBOLS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MOUSE_AND_MEDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [GAMING] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    if(SYMBOLS == layer || VIMISH == layer || MOUSE_AND_MEDIA == layer || GAMING == layer){
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE){
        rgb_matrix_set_color_all(0, 0, 0);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_set_vim(state);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_compose(keycode, record)) { return false; }
    if (!process_record_vim(keycode, record)) { return false; }

    switch (keycode) {
        case LT(0, KC_CIRC):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_6));    // On hold send ctrl-^ (buffer swap)
                return false;
            }
            if (record->event.pressed) {
                // On tap send ^. Cannot just return true, since LT(0, KC_CIRC)==LT(0, KC_6)
                tap_code16(KC_CIRC);
            }
            return false;
    }
    return true;
}


