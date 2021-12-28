/* MIT License

Copyright (c) 2021 Howin Tam

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* StrmPad Physical Layout
 *                 .--------.
 *                | 03 | 04 |
 *      .---------|----|----|
 *      | 00 | 01 | 02 | 09 |
 * .----|----|----|----|----|
 * | 05 | 06 | 07 | 08 |    |
 * |----|----|----|----| 14 |
 * | 10 | 11 | 12 | 13 |    |
 * |----|----|----|----|----|
 * | 15 | 16 | 17 | 18 |    |
 * |----|----|----|----| 19 |
 * | 20 | 21 | 22 | 23 |    |
 * .------------------------'
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _BL,
    _FN
};

enum custom_keycodes {
    KC_DBL0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 *                 .--------.
 *                | 03 | 04 |
 *      .---------|----|----|
 *      | 00 | 01 | 02 | 09 |
 * .----|----|----|----|----|
 * | 05 | 06 | 07 | 08 |    |
 * |----|----|----|----| 14 |
 * | 10 | 11 | 12 | 13 |    |
 * |----|----|----|----|----|
 * | 15 | 16 | 17 | 18 |    |
 * |----|----|----|----| 19 |
 * | 20 | 21 | 22 | 23 |    |
 * .------------------------'
 */

  [_BL] = LAYOUT(
    TO(_FN), KC_KP_SLASH,KC_KP_ASTERISK, 
    KC_TRNS, KC_MUTE, /* Buttons 03/04 */
    KC_MNXT, KC_7, KC_8, KC_9, KC_KP_MINUS,
    KC_MPRV, KC_4, KC_5, KC_6, KC_KP_PLUS,
    KC_MPLY, KC_1, KC_2, KC_3, KC_PENT,
    KC_F24, KC_0, KC_DBL0, KC_PDOT
  ),
  [_FN] = LAYOUT(
    TO(_BL), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_HOME, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_END, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_PGUP, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_PGDN, KC_TRNS, KC_TRNS,KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DBL0:
      if (record->event.pressed) {
        SEND_STRING("00");
      } else {
        // when keycode KC_DBL0 is released
      }
      break;

  }
  return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    case _BL:
      if(clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
  }
  return true;
}



#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;  // flips the display 270 degrees
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer"), false);
  switch (get_highest_layer(layer_state)) {
    case _BL:
      oled_write_ln_P(PSTR(" BASE"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR(" FUNC"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR(" UND"), false);
  }

}
#endif