#include QMK_KEYBOARD_H

bool encoder_update_user(uint8_t index, bool clockwise) {
    if(index == 1){
       if (clockwise) {
        tap_code(KC_WBAK);
      } else {
        tap_code(KC_WFWD);
      }
    }else{

   if (clockwise) {
        tap_code(KC_VOLD);
      } else {
        tap_code(KC_VOLU);
      }

    }
      return false;
}
