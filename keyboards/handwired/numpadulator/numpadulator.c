#include "numpad20.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {0}
}, {
    {0, 0}
}, {
    4
} };
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}
