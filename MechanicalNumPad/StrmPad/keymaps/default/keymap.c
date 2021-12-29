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
    _FN,
    _GH,
    _F12
};

enum custom_keycodes {
    KC_DBL0 = SAFE_RANGE,
    GITPUSH,
    GITPULL,
    GITCOMMIT,
    GITSTATUS,
    GITADD,
    GITINIT
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
    TO(_F12), KC_MUTE, /* Buttons 03/04 */
    KC_MNXT, KC_P7, KC_P8, KC_P9, KC_KP_MINUS,
    KC_MPRV, KC_P4, KC_P5, KC_P6, KC_KP_PLUS,
    KC_MPLY, KC_P1, KC_P2, KC_P3, KC_PENT,
    KC_F24, KC_0, KC_NUMLOCK, KC_PDOT
  ),
  [_FN] = LAYOUT(
    TO(_GH), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_HOME, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_END, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_PGUP, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    KC_PGDN, KC_TRNS, KC_TRNS,KC_TRNS
  ),
  [_GH] = LAYOUT(
    TO(_BL), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    GITPUSH, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    GITPULL, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    GITADD, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
    GITCOMMIT, KC_TRNS, KC_TRNS,KC_TRNS
  ),
  [_F12] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,
    TO(_BL), KC_TRNS,
    TO(_BL), KC_F10, KC_F11,KC_F12, KC_TRNS,
    TO(_FN), KC_F7, KC_F8,KC_F9, KC_TRNS,
    TO(_GH), KC_F4, KC_F5,KC_F6, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2,KC_F3
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
    case GITADD:
        if (record->event.pressed) {
            SEND_STRING("git add .\n");
        } else {
            ;
        }
        break;
    case GITCOMMIT:
        if (record->event.pressed) {
            SEND_STRING("git commit -m");
        } else {
            ;
        }
        break;
    case GITINIT:
        if (record->event.pressed) {
            SEND_STRING("git init");
        } else {
            ;
        }
        break;
    case GITPULL:
        if (record->event.pressed) {
            SEND_STRING("git pull\n");
        } else {
            ;
        }
        break; 
    case GITPUSH:
        if (record->event.pressed) {
            SEND_STRING("git push\n");
        } else {
            ;
        }
        break;
    case GITSTATUS:
            if (record->event.pressed) {
                SEND_STRING("git status\n");
            } else {
                ;
            }
            break;
    }
    return true;
};
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    default:
      if(clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
      break;
  }
  return true;
};

static void render_onion(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 48,  8,252, 36,240, 80, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64,192,160, 96,122,158, 99,  0,207, 16, 63,176,176, 48, 32, 32, 96, 96,224,224,192,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,128,224, 48, 24, 12, 38, 26, 15,  7,  2,193, 33,  8,  4,  2,  0,  0,  0,  1,  2, 12, 16, 32,  1,  1,  3,  2,  4,  8, 24, 49, 97,130,  4,  9, 19, 38, 12, 24,112,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,224,252,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 63,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,255,254,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  7, 31,124,240,192,128,  0, 32, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,  0,  0,  0,  0,255,  0,  0,  0,  0,128,  0,  0,  0,128,192, 56,192, 96,152,206,224, 60, 31,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  3,  7, 15, 14, 28, 57, 54,116,104,248,240,224,227,196,152,176,224, 64,131,136,176,192,223,240,192,224,120,115,120, 60, 62, 63, 29, 15,  7,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1, 13,  3, 15,  3, 11,  3, 15,  3,  5,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

#ifdef OLED_DRIVER_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_0; 
};

void oled_task_user(void){
    // Host Keyboard Layer Status
    
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
      case _BL:
        oled_write_ln_P(PSTR(" BASE"), false);
        break;
      case _FN:
        oled_write_ln_P(PSTR(" FUNC"), false);
        break;
      case _GH:
        oled_write_ln_P(PSTR(" GIT"),false);
        break;
      case _F12:
      oled_write_ln_P(PSTR(" FUNCTION KEYS"),false);
      break;
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR(" UND"), false);
    };

    render_onion();


};
#endif




