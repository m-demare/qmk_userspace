#pragma once

// clang-format off
#define LAYOUT_moonlander_mdemare( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    KC_ ## k00, KC_ ## k01, KC_ ## k02, KC_ ## k03, KC_ ## k04, KC_ ## k05, KC_ ## k06,   KC_ ## k60, KC_ ## k61, KC_ ## k62, KC_ ## k63, KC_ ## k64, KC_ ## k65, KC_ ## k66, \
    KC_ ## k10, KC_ ## k11, KC_ ## k12, KC_ ## k13, KC_ ## k14, KC_ ## k15, KC_ ## k16,   KC_ ## k70, KC_ ## k71, KC_ ## k72, KC_ ## k73, KC_ ## k74, KC_ ## k75, KC_ ## k76, \
    KC_ ## k20, KC_ ## k21, KC_ ## k22, KC_ ## k23, KC_ ## k24, KC_ ## k25, KC_ ## k26,   KC_ ## k80, KC_ ## k81, KC_ ## k82, KC_ ## k83, KC_ ## k84, KC_ ## k85, KC_ ## k86, \
    KC_ ## k30, KC_ ## k31, KC_ ## k32, KC_ ## k33, KC_ ## k34, KC_ ## k35,                           KC_ ## k91, KC_ ## k92, KC_ ## k93, KC_ ## k94, KC_ ## k95, KC_ ## k96, \
    KC_ ## k40, KC_ ## k41, KC_ ## k42, KC_ ## k43, KC_ ## k44,             KC_ ## k53,   KC_ ## kb3,             KC_ ## ka2, KC_ ## ka3, KC_ ## ka4, KC_ ## ka5, KC_ ## ka6, \
                                                    KC_ ## k50, KC_ ## k51, KC_ ## k52,   KC_ ## kb4, KC_ ## kb5, KC_ ## kb6 \
)
// clang-format on

#define KC_     _______
#define KC_XXX  XXXXXXX

#define KC_RGBDN RGB_VAD
#define KC_RGBUP RGB_VAI
#define KC_RGBMD RGB_MOD
#define KC_RGBTG RGB_TOG
#define KC_RESET QK_BOOT
