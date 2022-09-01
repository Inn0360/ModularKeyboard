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
 *
 *
 * .------------------------.
 * | 00 | 01 | 02 | 03 | 04 |
 * |----|----|----|----|----|
 * | 05 | 06 | 07 | 08 |    |
 * |----|----|----|----| 09 |----.
 * | 10 | 11 | 12 | 13 |    | 14 |
 * |----|----|----|----|----|----'
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
    _RGB,
    _GH,
    _F12,
    _F12_2,
    _LEFTBOARD
};
/*
enum custom_keycodes {
    KC_DBL0 = SAFE_RANGE,
    GITPUSH,
    GITPULL,
    GITCOMMIT,
    GITSTATUS,
    GITADD,
    GITINIT,
    KEYHOLDF,
    KEYREPLAY100
}; */
// Tap Dance Functions
enum {
    MUTE_DEAFEN,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [MUTE_DEAFEN] = ACTION_TAP_DANCE_DOUBLE(KC_F23, KC_F24),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     */

    [_BL] = LAYOUT(
        TO(_RGB), TO(_F12), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, /* Buttons 03/04 */
        KC_MNXT, KC_P7, KC_P8, KC_P9, KC_KP_PLUS,
        KC_MPRV, KC_P4, KC_P5, KC_P6, KC_MUTE,
        KC_MPLY, KC_P1, KC_P2, KC_P3, KC_PENT,
        TD(MUTE_DEAFEN), RGB_TOG, KC_0, KC_PDOT),
    [_RGB] = LAYOUT(
        TO(_LEFTBOARD), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_F12] = LAYOUT(
        TO(_BL), KC_LEFT, KC_TRNS, KC_RIGHT, KC_LCTL,
        TO(_BL), KC_F10, KC_F11, KC_F12, MO(_F12_2),
        TO(_RGB), KC_F7, KC_F8, KC_F9, KC_TRNS,
        KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS,
        KC_TRNS, KC_F1, KC_LGUI, KC_F3),
    [_F12_2] = LAYOUT(
        TO(_BL), KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL,
        TO(_BL), KC_F10, KC_F11, KC_F12, KC_TRNS,
        TO(_RGB), KC_F7, KC_F8, KC_F9, KC_TRNS,
        KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS,
        KC_TRNS, KC_F1, KC_LGUI, KC_F3),
    [_LEFTBOARD] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, TO(_BL),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R,
        KC_CAPS, KC_A, KC_S, KC_D, KC_T, /* Right Most is Encoder */
        KC_LSFT, KC_Z, KC_X, KC_C, KC_SPC,
        KC_LCTL, KC_TRNS, KC_Z, KC_LALT)
    };
/*
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
    case KEYHOLDF:
      if (record -> event.pressed){
          int h;
          for(h = 0; h < 15;h++){

            SEND_STRING(SS_DOWN(X_F) SS_DELAY(1000) SS_UP(X_F));
            wait_ms(1025);
          }
      }
      break;
    case KEYREPLAY100:
      if(record -> event.pressed){
        int i;
        int x;
        for(x = 0; x < 15; x++) {
          tap_code(KC_BTN1);
          for(i = 0; i < 180; i++){
            //SEND_STRING(SS_DELAY(500) SS_TAP(X_BTN1));
            tap_code(KC_MS_R);
          }
          for(i = 0; i < 50; i++){
            tap_code(KC_MS_U);
          }
          tap_code(KC_BTN1);
          for (i = 0; i < 180; i++) {
              // SEND_STRING(SS_DELAY(500) SS_TAP(X_BTN1));
              tap_code(KC_MS_L);
          }
          for (i = 0; i < 50; i++) {
              tap_code(KC_MS_D);
          }
        }
      }
      break;
  }
    return true;
};
*/
bool encoder_update_user(uint8_t index, bool clockwise) {
  switch(get_highest_layer(layer_state)) {
    case _F12:
      if(clockwise) {
        tap_code(KC_MS_WH_UP);
      } else {
        tap_code(KC_MS_WH_DOWN);
      }
    break;
    case _F12_2:
      if (clockwise) {
          tap_code(KC_WH_L);
      } else {
          tap_code(KC_WH_R);
      }
    break;
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

void suspend_power_down_user(void) {
  rgb_matrix_set_color_all(0,0,0);
  rgb_matrix_disable();
  rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
  rgb_matrix_set_suspend_state(false);
  rgb_matrix_enable();
}

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _BL:
          rgb_matrix_set_color(0, 18, 18,18);
          rgb_matrix_set_color(4, 18, 18, 18);
          rgb_matrix_set_color(18, 18, 18, 18);
          rgb_matrix_set_color(22, 18, 18, 18);

          break;
        case _RGB:
          rgb_matrix_set_color(0, 0, 16,0);
          rgb_matrix_set_color(4, 0, 16,0);
          rgb_matrix_set_color(18, 0, 16, 0);
          rgb_matrix_set_color(22, 0, 16,0);

          break;
        case _F12:
          rgb_matrix_set_color(0, 16, 0, 0);
          rgb_matrix_set_color(4, 16, 0, 0);
          rgb_matrix_set_color(18, 16, 0, 0);
          rgb_matrix_set_color(22, 16, 0,0);

          break;
        case _LEFTBOARD:
          rgb_matrix_set_color_all(16,0,0);
          break;
    }
}
