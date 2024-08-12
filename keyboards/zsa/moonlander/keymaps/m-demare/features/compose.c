#include "compose.h"

#include "keymap_spanish.h"
#include "moonlander.h"

#define MACRO_DELAY 50
#define LINUX_COMPOSE_KEY KC_RIGHT_ALT

inline static void compose_vowel(uint16_t keycode);
inline static void compose_n(void);
inline static void compose_g(void);
inline static void compose_d(void);

void with_no_mods_tap16(uint16_t key, uint8_t MODS_TO_REMOVE) {
    const uint8_t mods = get_mods();
    const uint8_t weak_mods = get_weak_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    del_mods(MODS_TO_REMOVE);
    del_weak_mods(MODS_TO_REMOVE);
    del_oneshot_mods(MODS_TO_REMOVE);

    tap_code16(key);

    set_mods(mods);
    set_weak_mods(weak_mods);
    set_oneshot_mods(oneshot_mods);
}

bool process_record_compose(uint16_t keycode, keyrecord_t* record){
    static bool composing = false;
    static bool is_hold = false;
    if(!(composing && record->event.pressed) && keycode!=COMPOSE) return true;

    switch (keycode) {
        case COMPOSE:
            if(record->tap.count == 2){
                // To give the option of pressing the actual compose key
                composing = false;
                ML_LED_4(false);
                return true;
            }
            is_hold = record->tap.count == 0;
            const bool keydown = record->event.pressed;
            composing = (is_hold && keydown) || (!is_hold && ((keydown && !composing) || (!keydown && composing)));
            ML_LED_4(composing);
            return false;
        case ES_A:
        case ES_E:
        case ES_I:
        case ES_O:
        case ES_U:
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
            composing = is_hold || keycode == KC_RSFT || (keycode == SFT_T(KC_ESC) && is_hold) || keycode == KC_CAPS_LOCK;
            ML_LED_4(composing);
            return true;
    }
    composing = is_hold;
    ML_LED_4(composing);
    return false;
}

inline static void compose_vowel(uint16_t keycode){
    with_no_mods_tap16(ES_ACUT, MOD_MASK_SHIFT);
    tap_code(keycode);
}

inline static void compose_n(void){
    tap_code(ES_NTIL);
}

inline static void compose_g(void){
    tap_code(ES_G);
    tap_code16(ES_DIAE);
    tap_code(ES_U);
}

inline static void compose_d(void){
    tap_code(ES_MORD);
}

