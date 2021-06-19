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


void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
