#include QMK_KEYBOARD_H

enum my_keycodes {
    FOO = SAFE_RANGE
};

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    RGB_TOG,                   RGB_MOD, \
    RGB_VAI, RGB_VAD, RGB_M_SW, FOO, \
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    KC_P4,   KC_P5,   KC_P6,            \
    KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    KC_P0,            KC_PDOT           \
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            // tap_code(RGB_VAD);
            rgblight_increase_val();
        } else {
            // tap_code(RGB_VAI);
            rgblight_decrease_val();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
      if (record->event.pressed) {
        rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;

}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
    render_logo();
}
#endif
