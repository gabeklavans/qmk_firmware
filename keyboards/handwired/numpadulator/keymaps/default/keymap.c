#include QMK_KEYBOARD_H

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    RGB_TOG, KC_A, KC_B,   KC_D, \
    KC_E,   KC_F,   KC_G,   KC_H, \
    KC_P4,   KC_P5,   KC_P6,   KC_MINS, \
    KC_P1,   KC_P2,   KC_P3,   KC_ENT, \
    KC_P0,   KC_DOT,  KC_RGHT, KC_TAB \
  )
};
