#ifndef DRAW_KEYMAP
    #include QMK_KEYBOARD_H
    #include "keymap_spanish.h"
    #include "layers.h"
    #include "features/compose.h"
    #include "features/vim_mode.h"
#else
    #define LAYOUT_moonlander LAYOUT
    #define QWERTY 0
    #define VIMISH 1
    #define SYMBOLS 2
    #define NUMBERS 3
    #define MOUSE_AND_MEDIA 4
    #define GAMING 5
#endif /* ifndef DRAW_KEYMAP */

#include "keydefs.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_moonlander(
         XXX ,  ES_1  ,  ES_2  ,  ES_3  ,  ES_4  ,  ES_5  , XXX ,                XXX ,  ES_6  ,  ES_7  ,  ES_8  ,  ES_9  ,  ES_0  ,  XXX   ,
      KC_DEL ,  ES_Q  ,  ES_W  ,  ES_E  ,  ES_R  ,  ES_T  , XXX ,              TG_NUM,  ES_Y  ,  ES_U  ,  ES_I  ,  ES_O  ,  ES_P  ,  XXX   ,
      KC_BSPC,  ES_A  ,  ES_S  ,  ES_D  ,   _F   ,  ES_G  , XXX ,                XXX ,  ES_H  ,  ES_J  ,  ES_K  ,  ES_L  , _SCLN  , _QUOT  ,
         _ESC,   _Z   ,  ES_X  ,  ES_C  ,  ES_V  ,  ES_B  ,                             ES_N  ,  ES_M  , ES_COMM, ES_DOT , _SLSH  , KC_RSFT,
     KC_LCTL ,  XXX   ,  XXX   ,KC_LEFT ,KC_RIGHT,        TG_VIM,              TG_GAM,           KC_UP , KC_DOWN,  XXX   ,  XXX   ,  XXX   ,
                                 KC_SPC ,KC_LALT ,KC_LGUI ,                           COMPOSE ,  _TAB  , _ENTER
    ),
    [VIMISH] = LAYOUT_moonlander(
          _  ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,                  _ ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,
          _  ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,                  _ ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,
          _  ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,                  _ ,  _  ,  _  ,  _  ,  _  ,  _  ,  _  ,
          _  ,  _  ,  _  ,  _  ,  _  ,  _  ,                             _  ,  _  ,  _  ,  _  ,  _  ,  _  ,
          _  ,  _  ,  _  ,  _  ,  _  ,        _  ,                  _ ,        _  ,  _  ,  _  ,  _  ,  _  ,
                            _  ,  _  ,  _  ,                             _  ,  _  ,  _
    ),
    [SYMBOLS] = LAYOUT_moonlander(
          _   , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,   _   ,                   _  , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
          _   ,  XXX  , ES_AT ,ES_LCBR,ES_RCBR,  XXX  ,   _   ,                   _  ,  XXX  ,  XXX  ,ES_LABK,ES_RABK,ES_HASH, KC_F12,
          _   ,ES_DLR ,ES_UNDS,ES_LPRN,ES_RPRN,ES_TILD,   _   ,                   _  ,ES_PIPE, ES_EQL,ES_PLUS,ES_MINS,ES_ASTR,   _   ,
          _   , _CIRC ,ES_PERC,ES_LBRC,ES_RBRC,  GRV  ,                               ES_AMPR,  XXX  ,ES_EXLM,  XXX , ES_BSLS,   _   ,
          _   ,   _   ,   _   ,RGB_VAD,RGB_VAI,       RGB_MOD,                 XXX  ,           _   ,  XXX  ,  XXX  ,   _   ,   _   ,
                                  _   ,   _   ,   _   ,                                  _   ,   _   ,   _
    ),
    [NUMBERS] = LAYOUT_moonlander(
         XXX , XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX , XXX , XXX , XXX , XXX , XXX ,
         XXX , XXX , XXX , XXX , XXX , XXX , XXX ,                 _  , XXX ,KC_7 ,KC_8 ,KC_9 , XXX , XXX ,
          _  , XXX , XXX , XXX , XXX , XXX , XXX ,                XXX , XXX ,KC_4 ,KC_5 ,KC_6 ,KC_0 , XXX ,
          _  ,  _  , XXX , XXX , XXX , XXX ,                            XXX ,KC_1 ,KC_2 ,KC_3 ,  _  ,  _  ,
          _  , XXX ,  _  ,  _  ,  _  ,       XXX ,                XXX ,        _  ,  _  , XXX , XXX , XXX ,
                            _  ,  _  ,  _  ,                            XXX ,  _  ,  _
    ),
    [MOUSE_AND_MEDIA] = LAYOUT_moonlander(
          _   ,   _   ,   _   ,   _   ,   _   ,   _   ,   _   ,                  _   ,   _   ,   _   ,   _   ,   _   ,   _   ,QK_BOOT,
          _   ,   _   ,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,   _   ,                  _   ,   _   ,   _   ,   _   ,   _   ,   _   ,   _   ,
          _   ,   _   ,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,   _   ,                  _   ,   _   ,   _   ,   _   ,   _   ,   _   ,KC_MPLY,
          _   ,   _   ,   _   ,   _   ,   _   ,   _   ,                                  _   ,   _   ,   _   ,   _   ,   _   ,   _   ,
          _   ,   _   ,   _   ,KC_MPRV,KC_MNXT,                   _    ,         _   ,        KC_VOLU,KC_VOLD,KC_MUTE,   _   ,   _   ,
                                  _   ,   _   ,   _   ,                                  _   ,KC_WBAK,KC_WFWD
    ),
    [GAMING] = LAYOUT_moonlander(
      KC_ESC  , ES_1  , ES_2  , ES_3  , ES_4  , ES_5  , ES_6  ,                  _   ,   _   ,   _   ,   _   ,   _   ,   _   ,   _   ,
      KC_TAB  , ES_Q  , ES_W  , ES_E  , ES_R  , ES_T  , ES_7  ,              KC_GCHAT,   _   ,   _   ,   _   ,   _   ,   _   ,   _   ,
      KC_CAPS , ES_A  , ES_S  , ES_D  , ES_F  , ES_G  , ES_8  ,              KC_SOUND,   _   ,   _   ,   _   , KC_UP ,   _   ,   _   ,
      KC_LSFT , ES_Z  , ES_X  , ES_C  , ES_V  , ES_B  ,                                  _   ,   _   ,KC_LEFT,KC_DOWN,KC_RIGHT,  _   ,
      KC_LCTL ,   _   ,   _   ,   _   ,   _   ,           _,                     _   ,           _   ,   _   ,   _   ,   _   ,   _   ,
                                KC_SPC,KC_LALT,   _   ,                                  _   ,   _   ,   _
    ),
};
// clang-format on

#undef _

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

#define NO_COL {0,0,0}

// clang-format off
// Note: each row corresponds to a column
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [VIMISH] = {
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210},

        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},

        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210}, {89,252,210},
        {89,252,210}, {89,252,210}, {144,252,181}, {89,252,210},
        {89,252,210}, {89,252,210}, {89,252,210},

        {89,252,210}, {89,252,210}, {89,252,210}, {89,252,210}
    },

    [SYMBOLS] = {
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, {127,245,221}, {127,245,221}, {127,245,221}, NO_COL,
        NO_COL, {127,245,221}, {127,245,221}, {127,245,221}, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL
    },

    [NUMBERS] = {
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, {127,245,221}, NO_COL, NO_COL,
        NO_COL, {127,245,221}, {127,245,221}, {127,245,221}, NO_COL,
        NO_COL, {127,245,221}, {127,245,221}, {127,245,221}, NO_COL,
        NO_COL, {127,245,221}, {127,245,221}, {127,245,221}, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL
    },

    [MOUSE_AND_MEDIA] = {
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, {201,201,235}, NO_COL, NO_COL,
        NO_COL, {201,201,235}, {201,201,235}, NO_COL, NO_COL,
        NO_COL, NO_COL, {201,201,235}, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL,

        {201,201,235}, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL
    },

    [GAMING] = {
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, {185,219,233}, {0,221,226}, {185,219,233}, NO_COL,
        NO_COL, {0,221,226}, {0,221,226}, {185,219,233}, NO_COL,
        NO_COL, {185,219,233}, {0,221,226}, {185,219,233}, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL,

        {0,221,226}, NO_COL, NO_COL, NO_COL,

        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, {0,221,226}, NO_COL,
        NO_COL, NO_COL, {0,221,226}, {0,221,226}, NO_COL,
        NO_COL, NO_COL, NO_COL, {0,221,226}, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, NO_COL, NO_COL, NO_COL,
        NO_COL, {60,219,233}, {185,219,233},

        NO_COL, NO_COL, NO_COL, NO_COL
    },
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
    switch (layer){
        case SYMBOLS:
        case NUMBERS:
        case VIMISH:
        case MOUSE_AND_MEDIA:
        case GAMING:
            set_layer_color(layer);
            return false;
        default: return true;
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
        case _CIRC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_6)); // On hold send ctrl-^ (buffer swap)
                return false;
            }
            if (record->event.pressed) {
                // On tap send ^
                tap_sequence(CIRC);
            }
            return false;
        case KC_GCHAT:
            if (!record->event.pressed) return false;
            if (host_keyboard_led_state().caps_lock) tap_code(KC_CAPS_LOCK);
            layer_clear();
            tap_code(KC_ENTER);
            return false;
        case _QUOT:
            if (record->tap.count && record->event.pressed) {
                if(get_active_mods() & MOD_MASK_SHIFT)
                    tap_code16(ES_DQUO);
                else
                    tap_code(ES_QUOT);
            } else if (!record->tap.count){
                return true;
            }
            return false;
        case _SLSH:
            if (record->tap.count && record->event.pressed) {
                if(get_active_mods() & MOD_MASK_SHIFT)
                    tap_code16(ES_QUES);
                else
                    tap_code16(ES_SLSH);
            } else if (!record->tap.count){
                return true;
            }
            return false;
        case _SCLN:
            if (record->tap.count && record->event.pressed) {
                if(get_active_mods() & MOD_MASK_SHIFT)
                    tap_code16(ES_COLN);
                else
                    tap_code16(ES_SCLN);
            } else if (!record->tap.count){
                return true;
            }
            return false;
        case FIRST_SEQUENCE_INDEX ... LAST_SEQUENCE_INDEX:
            if (!record->event.pressed) return false;
            tap_sequence(keycode);
            return false;
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case ES_A ... ES_Z:
            add_weak_mods(MOD_BIT_LSHIFT);
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case ES_1 ... ES_0:
        case KC_BSPC:
        case KC_DEL:
        case ES_UNDS:
        case ES_MINS:
        case COMPOSE:
            return true;

        // Deactivate Caps Word.
        default:
            return false;
    }
}
