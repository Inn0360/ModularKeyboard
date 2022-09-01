
/* Copyright 2021
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
#pragma once /* only compiles once */

#include "quantum.h"
#include "via.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

/* StrmPadv2 Physical Layout
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
#define LAYOUT( \
	k00, k01, k02, k03, k04,  \
	k05, k06, k07, k08, k09,  \
	k10, k11, k12, k13, k14,  \
	k15, k16, k17, k18, k19,  \
	k20, k21, k22, k23        \
){ \
	{k00, k01, k02, k03, k04 }, \
	{k05, k06, k07, k08, k09 }, \
	{k10, k11, k12, k13, k14 }, \
	{k15, k16, k17, k18, k19 }, \
	{k20, k21, k22, k23, KC_NO }  \
}
