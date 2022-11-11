/*
 * Copyright 2017 skully <skullydazed@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device Descriptor */

#define PRODUCT StrmPad
#define DEVICE_VER 0x0001
/* Matrix Size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F7, B1, B3, B2, B6 }

/* RGB Config */
#define RGB_DI_PIN F4
#define DRIVER_LED_TOTAL 23

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#define RGBLIGHT_SLEEP
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 2

/* ENCODER SUPPORT */
#define ENCODERS_PAD_A {F6}
#define ENCODERS_PAD_B {F5}
#define ENCODER_RESOLUTION 4

//Space Reduction

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

        /* define if matrix has ghost (lacks anti-ghosting diodes) */
        //#define MATRIX_HAS_GHOST

        /* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
        //#define LOCKING_SUPPORT_ENABLE
        /* Locking resynchronize hack */
        //#define LOCKING_RESYNC_ENABLE

        /*
         * Feature disable options
         *  These options are also useful to firmware size reduction.
         */

        /* disable debug print */
        //#define NO_DEBUG

        /* disable print */
        //#define NO_PRINT

        /* disable action features */
        //#define NO_ACTION_LAYER
        //#define NO_ACTION_TAPPING
        //#define NO_ACTION_MACRO
        //#define NO_ACTION_FUNCTION

        /* Bootmagic Lite key configuration */
        // #define BOOTMAGIC_LITE_ROW 0
        // #define BOOTMAGIC_LITE_COLUMN 0

        /* VIA Layout */
        /*
        #define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 3
        */
