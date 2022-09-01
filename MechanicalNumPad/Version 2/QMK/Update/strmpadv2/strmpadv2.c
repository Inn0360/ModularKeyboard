/* Copyright 2017 skully <skullydazed@gmail.com>
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
#include "strmpadv2.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {10, 11, 12, 13, NO_LED},
    {14 ,15 ,16 , 17, 18},
    {19, 20, 21, 22, NO_LED} 

} , {
    // LED Index to Physical Position
    { 0, 0 }, { 56, 0 }, { 112, 0 }, {168, 0}, {224, 0},
    { 0, 16 }, { 56, 16 }, { 112, 16 }, { 168, 16 },
                                                    { 224, 24 },
    { 0, 32 }, { 56, 32 }, { 112, 32 }, { 168, 32 },
    { 0, 48 }, { 56, 48 }, { 112, 48 }, { 168, 48 },
                                                    { 224, 56 },
    { 0, 64 }, { 56, 64 }, { 112, 64 }, { 168, 64 },


}, {
    // LED Index to Flag
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4
}};

#endif
