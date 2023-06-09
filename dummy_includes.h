#ifndef PROGMEM
    #error "Shouldn't be here"
    #include "config.h"
    #include "../../config.h"
    #include "../../moonlander.h"
    #include "../../../../quantum/quantum.h"
    #include "../../../../quantum/quantum_keycodes.h"
    #include "../../../../quantum/action_code.h"
    #include "../../../../quantum/action_layer.h"
    #include "../../../../quantum/action_util.h"
    #include "../../../../quantum/action_tapping.h"
    #include "../../../../quantum/color.h"
    #include "../../../../quantum/send_string_keycodes.h"
    #include "../../../../quantum/send_string.h"
    #include "../../../../quantum/bitwise.h"
    #include "../../../../quantum/rgblight/rgblight.h"
    #include "../../../../quantum/rgb_matrix/rgb_matrix_types.h"
    #include "../../../../quantum/rgb_matrix/rgb_matrix.h"
    #include "../../../../platforms/progmem.h"
    #include <stdint.h>
    #define PROGMEM
#endif /* !PROGMEM */

