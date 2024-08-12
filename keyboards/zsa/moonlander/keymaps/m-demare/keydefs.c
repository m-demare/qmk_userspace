#include "keydefs.h"
#include "keymap_spanish.h"

#define SEQUENCE_MAX_LENGTH 3


static const uint16_t sequenceKeys[][SEQUENCE_MAX_LENGTH] PROGMEM = {
    //MEMBER
    { ES_MINS, ES_RABK, NULL_KEY },
    //ARROW
    { ES_EQL, ES_RABK, NULL_KEY },
    //GRV
    { ES_GRV, KC_SPC, NULL_KEY },
    //CIRC
    { ES_CIRC, KC_SPC, NULL_KEY },
};

void tap_sequence(uint16_t seqName){
    const uint16_t * sequence = sequenceKeys[seqName - FIRST_SEQUENCE_INDEX - 1];
    for(int i=0; i<SEQUENCE_MAX_LENGTH; i++){
        uint16_t currentKey = sequence[i];
        if(currentKey == NULL_KEY) break;
        tap_code16(currentKey);
    }
}

