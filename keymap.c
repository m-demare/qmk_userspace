#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"
#include "layers.h"
#include "layout_mdemare.h"
#include "features/compose.h"
#include "features/vim_mode.h"

// To avoid ccls complaining
#include "dummy_includes.h"

#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    START = SAFE_RANGE,
};

// Abbreviations
#define KC_COMP COMPOSE
#define KC_TG_SYM TG(SYMBOLS)
#define KC_TG_VIM TG(VIMISH)
#define KC_TG_GAM TG(GAMING)

// Special keys
#define KC__CIRC LT(0, KC_CIRC)
#define KC__QUOT LGUI_T(KC_QUOT)
#define KC__TAB LT(SYMBOLS, KC_TAB)
#define KC__Z CTL_T(KC_Z)
#define KC__ESC SFT_T(KC_ESC)
#define KC__F LT(VIMISH, KC_F)
#define KC__SLSH RCTL_T(KC_SLSH)
#define KC__SCLN LT(MOUSE_AND_MEDIA, KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_moonlander_mdemare(
        GRAVE,  1  ,  2  ,  3  ,  4  ,  5  , XXX ,               EQUAL,  6  ,  7  ,  8  ,  9  ,  0  ,MINUS,
         DEL ,  Q  ,  W  ,  E  ,  R  ,  T  , XXX ,              TG_SYM,  Y  ,  U  ,  I  ,  O  ,  P  , BSLS,
         BSPC,  A  ,  S  ,  D  ,  _F ,  G  , XXX ,                XXX ,  H  ,  J  ,  K  ,  L  ,_SCLN,_QUOT,
         _ESC,  _Z ,  X  ,  C  ,  V  ,  B  ,                             N  ,  M  ,COMMA, DOT ,_SLSH, RSFT,
        LCTL ,  XXX,  XXX, LEFT,RIGHT,          TG_VIM,     TG_GAM,            UP , DOWN, XXX , XXX , XXX ,
                            SPC, LALT, LGUI,                            COMP, _TAB,ENTER
    ),
    [VIMISH] = LAYOUT_moonlander_mdemare(
             ,     ,     ,     ,     ,     ,     ,                    ,     ,     ,     ,     ,     ,     ,
             ,  Q  ,  W  ,  E  ,  R  ,  T  ,     ,                    ,  Y  ,  U  ,  I  ,  O  ,  P  ,     ,
             ,  A  ,  S  ,  D  ,     ,  G  ,     ,                    ,  H  ,  J  ,  K  ,  L  ,     ,     ,
             ,  _Z ,  X  ,  C  ,  V  ,  B  ,                             N  ,  M  ,COMMA, DOT ,     ,     ,
             ,     ,     ,     ,     ,                  ,       ,                 ,     ,     ,     ,     ,
                               ,     ,     ,                                ,     ,
    ),
    [SYMBOLS] = LAYOUT_moonlander_mdemare(
        ESC  ,  F1 ,  F2 ,  F3 ,  F4 ,  F5 ,     ,                    ,  F6 ,  F7 ,  F8 ,  F9 , F10 , F11 ,
             , EXLM,  AT , LCBR, RCBR, PIPE,     ,                    ,MINUS,  7  ,  8  ,  9  , ASTR, F12 ,
             , HASH, DLR , LPRN, RPRN,GRAVE,     ,                    , UNDS,  4  ,  5  ,  6  , EQL , PPLS,
             , PERC,_CIRC, LBRC, RBRC, TILD,                            AMPR,  1  ,  2  ,  3  , BSLS,     ,
             ,COMMA,     ,RGBDN,RGBUP,             RGBMD,  RGBTG,                 ,  0  , DOT ,     ,     ,
                               ,     ,     ,                                ,     ,
    ),
    [MOUSE_AND_MEDIA] = LAYOUT_moonlander_mdemare(
             ,     ,     ,     ,     ,     ,     ,                    ,     ,     ,     ,     ,     ,RESET,
             ,     , BTN1, MS_U, BTN2, WH_U,     ,                    ,     ,     ,     ,     ,     ,     ,
             ,     , MS_L, MS_D, MS_R, WH_D,     ,                    ,     ,     ,     ,     ,     , MPLY,
             ,     ,     ,     ,     ,     ,                                ,     ,     ,     ,     ,     ,
             ,     ,     , MPRV, MNXT,                  ,       ,             VOLU, VOLD, MUTE,     ,     ,
                               ,     ,     ,                                , WBAK, WFWD
    ),
    [GAMING] = LAYOUT_moonlander_mdemare(
        ESC  ,  1  ,  2  ,  3  ,  4  ,  5  ,  6  ,                    ,     ,     ,     ,     ,     ,     ,
        TAB  ,  Q  ,  W  ,  E  ,  R  ,  T  ,  7  ,                    ,     ,     ,     ,     ,     ,     ,
        CAPS ,  A  ,  S  ,  D  ,  F  ,  G  ,  8  ,                    ,     ,     ,     ,  UP ,     ,     ,
        LSFT ,  Z  ,  X  ,  C  ,  V  ,  B  ,                                ,     , LEFT, DOWN,RIGHT,     ,
        LCTL ,     ,     ,     ,     ,                     ,       ,              ,     ,     ,     ,     ,
                         SPACE ,     ,     ,                                ,     ,
    ),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

// clang-format off
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [VIMISH] = { {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210} },

    [SYMBOLS] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {127,245,221}, {127,245,221}, {127,245,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [MOUSE_AND_MEDIA] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {201,201,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [GAMING] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {185,219,233}, {0,221,226}, {185,219,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,221,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) { return false; }
    uint8_t layer = biton32(layer_state);
    if (SYMBOLS == layer || VIMISH == layer || MOUSE_AND_MEDIA == layer || GAMING == layer) {
        set_layer_color(layer);
        return false;
    }
    return true;
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
                tap_code16(C(KC_6)); // On hold send ctrl-^ (buffer swap)
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
