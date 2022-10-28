#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _FUNCTION 1
#define _SPECIAL 2

enum unicode_names {
    THORNE =SAFE_RANGE ,
    PHI,
    ENG,
    SCREENSHOT,
    IBIS
};

// Some basic macros


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_ortho_5x4(
			KC_NUM,   KC_PSLS, KC_PAST, KC_PMNS, 
			KC_P7,   KC_P8,   KC_P9,   KC_MPLY, 
			KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
			KC_P1,   KC_P2,   KC_P3,    MO(_FUNCTION),
			KC_P0,   KC_MUTE,  KC_PDOT, KC_ENT),

	[_FUNCTION] = LAYOUT_ortho_5x4(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_UNDO, KC_UP, KC_AGAIN, QK_BOOTLOADER, 
			KC_LEFT, KC_TRNS, KC_RIGHT, KC_TRNS, 
			KC_COPY, KC_DOWN, KC_PASTE, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

void printWinComposeUnicode(uint16_t keycode1, uint16_t keycode2, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_RALT);
        register_code(keycode1);
        register_code(keycode2);

    } else {
        unregister_code(KC_RALT);
        unregister_code(keycode1);
        unregister_code(keycode2);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THORNE:
            printWinComposeUnicode(KC_T, KC_H, record);
            return false;
        case PHI:
            printWinComposeUnicode(KC_PAST, KC_F, record);
            return false;
        case ENG:
            printWinComposeUnicode(KC_N, KC_G, record);
            return false;
        case IBIS:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(KC_H);
                register_code(KC_I);
                register_code(KC_R);
                register_code(KC_D);

            } else {
                unregister_code(KC_RALT);
                unregister_code(KC_H);
                unregister_code(KC_I);
                unregister_code(KC_R);
                unregister_code(KC_D);
            }
            return false;
        case SCREENSHOT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                register_code(KC_S);

            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
                unregister_code(KC_S);
            }
            return false;
    }

    return true;
};
