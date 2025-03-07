/* Copyright 2023 splitkb.com <support@splitkb.com>
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

#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_KEYPRESSES
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define MASTER_LEFT 

#define RGB_MATRIX_PINS { B4, B5, B6, B7, D2, D3, D4, D5, D6, D7, E6, F4, F5, F6, F7, F0, F1, F2, F3, B0, B1, B2, B3, C6, C7, D0, D1, E2, E6, F4, F5, F6, F7, F0, F1, F2, F3 } // Broches pour les LED RGB par touche
#define RGB_MATRIX_UNDERGLOW_PINS { C6, C7, D0, D1, E2 } // Broches pour les LED underglow
#define RGB_MATRIX_DRIVER WS2812
#define RGB_MATRIX_SERIAL_DRIVER
#define RGB_MATRIX_SPLIT_USB_DRIVER
#define RGB_MATRIX_NUM_LEDS 38 // Nombre total de LED RGB par touche
#define RGB_MATRIX_UNDERGLOW_NUM_LEDS 5 // Nombre de LED underglow