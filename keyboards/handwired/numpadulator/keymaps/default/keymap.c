#include QMK_KEYBOARD_H

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    RGB_TOG,                   RGB_TOG, \
    RGB_TOG, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    KC_P4,   KC_P5,   KC_P6,            \
    KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    KC_P0,            KC_PDOT           \
  )
};

#ifdef OLED_DRIVER_ENABLE
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
