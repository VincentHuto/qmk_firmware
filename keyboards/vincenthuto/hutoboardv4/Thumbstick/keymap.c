#include QMK_KEYBOARD_H
#include "print.h"
#include "thumbstick.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define LAYER1 1

enum unicode_names {
    THORNE =SAFE_RANGE ,
    PHI,
    ENG,
    SCREENSHOT,
    IBIS,
    TMB_MODE
};

// Some basic macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x8( // layer 0 : default
                             // left hand
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_EQUAL, KC_EQUAL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F2, KC_F2,
        KC_CAPS_LOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_F3, KC_F4,
        KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, THORNE, SCREENSHOT,
        KC_LCTL, KC_LALT, KC_LGUI , KC_LEFT, KC_RIGHT, KC_SPC, KC_ENT, KC_F12,
                             // Right hand
        KC_BSPC, KC_0, KC_9, KC_8, KC_7, KC_6, KC_MINUS, KC_MINUS,
        KC_DEL, KC_P, KC_O, KC_I, KC_U, KC_Y, KC_QUOTE, KC_F14,
        KC_ENTER, KC_SEMICOLON, KC_L, KC_K, KC_J, KC_H, KC_F15, QK_BOOTLOADER,
        KC_LSFT,KC_SLASH, KC_DOT, KC_COMM, KC_M, KC_N, KC_BACKSLASH, IBIS,
        KC_LCTL, KC_RBRC, KC_LBRC, KC_DOWN, KC_UP, KC_SPC, KC_BSPC, KC_F24
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
    print("..::DEBUG::..\n");
    #ifdef THUMBSTICK_ENABLE
        print(":) THUMBSTICK_ENABLED!\n");
    #endif
    #ifdef THUMBSTICK_DEBUG
        print("THUMBSTICK_DEBUG!\n");
    #endif
   
   
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
        #ifdef THUMBSTICK_ENABLE
            case TMB_MODE:
                if (record->event.pressed) {
                    thumbstick_mode_cycle(false);
                }
        #endif
    }
    print("..::END_DEBUG::..\n");
    return true;
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  print("keyboard_post_init_user ;)");
  #ifdef THUMBSTICK_ENABLE
    print("THUMBSTICK_ENABLE");
  #endif
  debug_enable=true;
  debug_keyboard=true;
  debug_mouse=true;
}