#include "compose.h"
#include "moonlander.h"

#define MACRO_DELAY 50
#define LINUX_COMPOSE_KEY KC_RIGHT_ALT

enum Platform {
    LINUX,
    WINDOWS
};

static enum Platform platform = LINUX;

inline static void compose_vowel(uint16_t keycode);
inline static void compose_n(void);
inline static void compose_g(void);
inline static void compose_d(void);

static void linux_compose(uint16_t n1, uint8_t n2);
static void win_ascii(uint8_t n1, uint8_t n2);

bool process_record_compose(uint16_t keycode, keyrecord_t* record){
    static bool composing = false;
    static bool is_hold = false;
    if((!composing || !record->event.pressed) && keycode!=COMPOSE) return true;

    switch (keycode) {
        case COMPOSE:
            if(record->event.pressed && record->tap.count == 3){
                platform = platform == LINUX ? WINDOWS : LINUX;
                composing = false;
                ML_LED_4(false);
                return false;
            }
            if(record->tap.count == 2){
                // To give the option of actually pressing RALT
                composing = false;
                ML_LED_4(false);
                return true;
            }
            is_hold = record->tap.count == 0;
            const bool keydown = record->event.pressed;
            composing = (is_hold && keydown) || (!is_hold && ((keydown && !composing) || (!keydown && composing)));
            ML_LED_4(composing);
            return false;
        case KC_A:
        case KC_E:
        case KC_I:
        case KC_O:
        case KC_U:
            compose_vowel(keycode);
            break;
        case KC_N:
            compose_n();
            break;
        case KC_G:
            compose_g();
            break;
        case KC_D:
            compose_d();
            break;
        default:
            composing = is_hold || keycode == KC_RSFT || keycode == SFT_T(KC_ESC) || keycode == KC_CAPS_LOCK;
            ML_LED_4(composing);
            return true;
    }
    composing = is_hold;
    ML_LED_4(composing);
    return false;
}

static void linux_compose(uint16_t n1, uint8_t n2){
    uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    tap_code(LINUX_COMPOSE_KEY);
    tap_code16(n1);
    set_mods(mods);
    tap_code(n2);
}

static void win_ascii(uint8_t n1, uint8_t n2){
    register_code16(KC_LEFT_ALT);
    tap_code(KC_KP_1);
    tap_code(n1);
    tap_code(n2);
    unregister_code16(KC_LEFT_ALT);
}

inline static void compose_vowel(uint16_t keycode){
    if (platform == LINUX) {
        linux_compose(KC_QUOTE, keycode);
        return;
    }
    switch (keycode) {
        case KC_A:
            win_ascii(KC_KP_6, KC_KP_0);
            break;
        case KC_E:
            win_ascii(KC_KP_3, KC_KP_0);
            break;
        case KC_I:
            win_ascii(KC_KP_6, KC_KP_1);
            break;
        case KC_O:
            win_ascii(KC_KP_6, KC_KP_2);
            break;
        case KC_U:
            win_ascii(KC_KP_6, KC_KP_3);
            break;
    }
}

inline static void compose_n(void){
    if (platform == LINUX) {
        linux_compose(KC_TILDE, KC_N);
        return;
    }
    win_ascii(KC_KP_6, KC_KP_4);
}

inline static void compose_g(void){
    tap_code(KC_G);
    if (platform == LINUX) {
        linux_compose(KC_DQUO, KC_U);
        return;
    }
    win_ascii(KC_KP_2, KC_KP_9);
}

inline static void compose_d(void){
    if (platform == LINUX) {
        linux_compose(KC_O, KC_O);
        return;
    }

    register_code16(KC_LEFT_ALT);
    tap_code(KC_KP_0);
    tap_code(KC_KP_1);
    tap_code(KC_KP_7);
    tap_code(KC_KP_6);
    unregister_code16(KC_LEFT_ALT);
}

