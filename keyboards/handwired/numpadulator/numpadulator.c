#include "numpadulator.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
//   { 0, 18, 19 },
//   { 1,  2,  3,  4 },
//   { 5,  20, 6, 7, 8, 21 },
//   { 9, 10, 11 },
//   { 12, 13, 14, 15 },
//   { 22, 16, 17, 23 }
  { 0, NO_LED },
  { 3,  4,  5,  6 },
  { 7, 9, 10, 11 },
  { 13, 14, 15 },
  { 16, 17, 18, 19 },
  { 21, 22 },
  { 1, 2, 8, 12, 20, 23 }
}, {
  // LED Index to Physical Position
  { 0,  0 }, { 0,  4 }, { 224,  4 },
  { 0,  10 }, { 74,  10 }, { 148,  10 }, { 224,  10 },
  { 0,  21 }, { 0,  21 }, { 74,  21 }, { 148,  21 }, { 224, 25 }, { 224, 25 },
  { 0,  32 }, { 112,  32 }, { 224,  32 },
  { 0,  43 }, { 74,  43 }, { 148,  43 }, { 224,  43 },
  { 0, 64 }, { 0,  64 }, { 112,  64 }, { 224, 64 }


}, {
  // LED Index to Flag
  4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4,
  4, 4, 4, 4,
  4, 4,
  2, 2, 2, 2, 2, 2
} };
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}
