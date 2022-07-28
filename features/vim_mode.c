#include "vim_mode.h"

#define MACRO_DELAY 50

enum vmode {
  NORMAL,
  DELETE,
  CHANGE,
  INSERT
};
static enum vmode mode = NORMAL;
static enum layers layer = QWERTY;
static uint16_t registered_keycode = KC_NO;

static inline void unregister_keycode(void){
  if (registered_keycode != KC_NO) {
    unregister_code16(registered_keycode);
    registered_keycode = KC_NO;
  }
}

static inline void register_keycode(uint16_t code){
  unregister_keycode();
  registered_keycode = code;
  register_code16(code);
}

void register_or_unregister(bool keydown, uint16_t code){
  if(keydown) register_keycode(code);
  else unregister_keycode();
}

bool handle_insert(uint16_t keycode, keyrecord_t* record);
bool handle_normal(uint16_t keycode, keyrecord_t* record);
bool handle_delete(uint16_t keycode, keyrecord_t* record);

static inline uint8_t get_active_mods(void){
  const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
  const uint8_t all_mods = mods | get_oneshot_mods();
#else
  const uint8_t all_mods = mods;
#endif  // NO_ACTION_ONESHOT
  return all_mods;
}

bool process_record_vim(uint16_t keycode, keyrecord_t* record){
  if(layer != VIMISH) return true;

  switch (mode) {
    case INSERT:
      return handle_insert(keycode, record);
    case NORMAL:
      return handle_normal(keycode, record);
    case CHANGE:
    case DELETE:
      return handle_delete(keycode, record);
  }
  return true;
}

bool handle_insert(uint16_t keycode, keyrecord_t* record){
  const bool keydown = record->event.pressed;

  switch (keycode) {
    case MT(MOD_LSFT, KC_ESC):
      if(record->tap.count>0){
        mode = NORMAL;
        return false;
      }
      break;
    case KC_W:
      if(get_active_mods() & MOD_MASK_CTRL){
        register_or_unregister(keydown, C(KC_BACKSPACE));
        return false;
      }
      break;
    default:
      break;
  }
  return true;
}

bool handle_normal(uint16_t keycode, keyrecord_t* record){
  uint8_t mods = get_active_mods();

  // Ignore vim_mode if super is pressed
  if(mods & MOD_MASK_GUI)
    return true;

  const bool keydown = record->event.pressed;

  switch (keycode) {
    case KC_H:
      register_or_unregister(keydown, KC_LEFT);
      break;
    case KC_J:
      register_or_unregister(keydown, KC_DOWN);
      break;
    case KC_K:
      register_or_unregister(keydown, KC_UP);
      break;
    case KC_L:
      register_or_unregister(keydown, KC_RIGHT);
      break;

    case KC_N:
      register_or_unregister(keydown, KC_HOME);
      break;
    case KC_M:
      register_or_unregister(keydown, KC_PGDN);
      break;
    case KC_COMMA:
      register_or_unregister(keydown, KC_PGUP);
      break;
    case KC_DOT:
      register_or_unregister(keydown, KC_END);
      break;

    case KC_A:
      if(keydown){
        mode=INSERT;
        if(mods & MOD_MASK_SHIFT){
          del_mods(MOD_MASK_SHIFT);
          tap_code(KC_END);
        } else
          tap_code16(KC_RIGHT);
      }
      break;
    case KC_I:
      if(keydown){
        mode=INSERT;
        if(mods & MOD_MASK_SHIFT){
          del_mods(MOD_MASK_SHIFT);
          tap_code(KC_HOME);
        }
      }
      break;
    case KC_O:
      if(keydown){
        mode=INSERT;
        if(mods & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          SEND_STRING(SS_TAP(X_HOME) SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER) SS_DELAY(MACRO_DELAY) SS_TAP(X_UP));
        } else {
          SEND_STRING(SS_TAP(X_END) SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
        }
      }
      break;
    case KC_D:
    case KC_C:
      if(keydown && (mods & MOD_MASK_SHIFT)){
        SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(MACRO_DELAY) SS_TAP(X_BACKSPACE));
        mode = (keycode == KC_D ? NORMAL : INSERT);
        break;
      }
      if(keydown && !(mods & MOD_MASK_CTRL)) {
        mode = (keycode == KC_D ? DELETE : CHANGE);
        break;
      }
      return true;
    case KC_E:
      register_or_unregister(keydown, C(KC_RIGHT));
      break;
    case KC_W:
      if(mods & MOD_MASK_CTRL)
        return true;
      if(keydown)
        SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_DELAY(MACRO_DELAY) SS_TAP(X_RIGHT));
      break;
    case KC_B:
      register_or_unregister(keydown, C(KC_LEFT));
      break;

    case KC_U:
      register_or_unregister(keydown, C(KC_Z));
      break;
    case KC_R:
      if(mods & MOD_MASK_CTRL){
        register_or_unregister(keydown, C(KC_Y));
      }
      break;
    case MT(MOD_RCTL, KC_SLASH):
      if(record->tap.count==0) return true;
      if(keydown) tap_code16(C(KC_F));
      break;
    default:
      return true;
  }
  return false;
}

bool handle_delete(uint16_t keycode, keyrecord_t* record){
  const bool keydown = record->event.pressed;
  if (!keydown) return true;

  switch (keycode) {
    case KC_E:
    case KC_W:
      tap_code16(C(KC_DELETE));
      break;
    case KC_B:
      tap_code16(C(KC_BACKSPACE));
      break;
    case KC_I:
      tap_code16(C(KC_LEFT));
      return false; // Stay in CHANGE/DELETE
    case KC_L:
      tap_code16(KC_DELETE);
      break;
    case KC_H:
      tap_code16(KC_BACKSPACE);
      break;

    case KC_C:
    case KC_D:
      if((keycode == KC_C && mode == DELETE) || (keycode == KC_D && mode == CHANGE)) {
        mode=NORMAL;
        return false;
      }
      SEND_STRING(SS_TAP(X_HOME) SS_DELAY(MACRO_DELAY) SS_LSFT(SS_TAP(X_END)) SS_DELAY(MACRO_DELAY) SS_TAP(X_BACKSPACE));
      break;

    default:
      mode=NORMAL;
      return false;
  }
  mode = ( mode==DELETE ? NORMAL : INSERT );
  return false;
}

void layer_state_set_vim(layer_state_t state){
  layer = get_highest_layer(state);
  if(layer != VIMISH){
    unregister_keycode();
    if(!IS_LAYER_ON_STATE(state, VIMISH))
        mode = NORMAL;
  }
}

