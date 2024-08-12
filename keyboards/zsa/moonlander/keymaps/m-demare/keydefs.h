#pragma once

#ifndef DRAW_KEYMAP
    #include QMK_KEYBOARD_H
#endif /* ifndef DRAW_KEYMAP */

#define NULL_KEY KC_NO

// Abbreviations
#define TG_NUM TG(NUMBERS)
#define TG_VIM TG(VIMISH)
#define TG_GAM TG(GAMING)
#define KC_SOUND C(ES_GRV)
#define _    _______
#define XXX  XXXXXXX

// Special keys
#define _CIRC LT(0, ES_CIRC)
#define _QUOT LGUI_T(ES_QUOT)
#define _TAB LT(NUMBERS, KC_TAB)
#define _ENTER LT(SYMBOLS, KC_ENTER)
#define _Z CTL_T(ES_Z)
#define _ESC SFT_T(KC_ESC)
#define _F LT(VIMISH, ES_F)
#define _SLSH RCTL_T(ES_SLSH)
#define _SCLN LT(MOUSE_AND_MEDIA, ES_SCLN)

enum custom_keycodes {
    START = SAFE_RANGE,
    KC_GCHAT,

    FIRST_SEQUENCE_INDEX,
    MEMBER,
    ARROW,
    GRV,
    CIRC,
    QUOT,
    LAST_SEQUENCE_INDEX,
};


void tap_sequence(uint16_t seqName);

