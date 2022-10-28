#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
    [_QWERTY] = LAYOUT_5x8( // layer 0 : default
                             // left hand
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_EQUAL, KC_EQUAL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F13, KC_F14,
        KC_CAPS_LOCK, KC_A, KC_S, KC_D, KC_F, KC_G,  MO(_SPECIAL) , KC_F4,
        KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, THORNE, SCREENSHOT,
        KC_LCTL, KC_LALT, KC_LGUI , KC_LEFT, KC_RIGHT, KC_SPC, KC_ENT, MO(_FUNCTION),
                             // Right hand
        KC_BSPC, KC_0, KC_9, KC_8, KC_7, KC_6, KC_MINUS, KC_MINUS,
        KC_DEL, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_QUOTE, KC_F14,
        KC_ENTER, KC_SEMICOLON, KC_L, KC_K, KC_J, KC_H,  MO(_SPECIAL), QK_BOOTLOADER,
        KC_LSFT,KC_SLASH, KC_DOT, KC_COMM, KC_M, KC_N, KC_BACKSLASH, IBIS,
        KC_LCTL, KC_RBRC, KC_LBRC, KC_DOWN, KC_UP, KC_SPC, KC_BSPC, MO(_FUNCTION)
        ),
    [_FUNCTION] = LAYOUT_5x8( // layer 1 : Functions
                             // left hand
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F11, _______,
        _______, _______, _______, _______, _______, _______, _______ , _______,
        _______,_______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______ , _______, _______, _______, _______, _______,
                             // Right hand
        _______, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F12, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
        ),
        [_SPECIAL] = LAYOUT_5x8( // layer 1 : Functions
                             // left hand
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F11, _______,
        _______, _______, _______, _______, _______, _______, _______ , _______,
        _______,_______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______ , _______, _______, _______, _______, _______,
                             // Right hand
        _______, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F12, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______,_______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
        )
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
