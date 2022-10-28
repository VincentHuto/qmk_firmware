#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _FUNCTION1 1
#define _FUNCTION2 2
#define _FUNCTION3 3
#define _FUNCTION4 4

enum unicode_names {
    THORNE =SAFE_RANGE ,
    PHI,
    ENG,
    SCREENSHOT,
    IBIS
};

// Some basic macros


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_numpad_5x4(
			KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,   KC_F11,   KC_F12,
			KC_MUTE,   MO(_FUNCTION1),    MO(_FUNCTION2),   KC_F15,  MO(_FUNCTION3), MO(_FUNCTION4)  ,  MO(_FUNCTION4),     KC_F17),

	[_FUNCTION1] = LAYOUT_numpad_5x4(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, 
			QK_BOOTLOADER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_FUNCTION2] = LAYOUT_numpad_5x4(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_FUNCTION3] = LAYOUT_numpad_5x4(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

	[_FUNCTION4] = LAYOUT_numpad_5x4(
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS),

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
