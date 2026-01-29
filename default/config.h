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
#include "quantum.h"

// Configuration du clavier split
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define MASTER_LEFT
#define SPLIT_RGB_MATRIX_ENABLE

// Configuration RGB Matrix
#define RGB_MATRIX_SLEEP          // Éteindre les LEDs après inactivité
#define RGB_MATRIX_KEYPRESSES     // Effets réactifs aux touches
#define RGB_MATRIX_HUE_STEP 8

// Activer uniquement les effets souhaités (gain d'espace firmware)
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE  // Effet "goutte d'eau"
#define ENABLE_RGB_MATRIX_SOLID_SPLASH           // Effet splash
