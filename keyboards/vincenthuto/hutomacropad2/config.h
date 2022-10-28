/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#define MASTER_LEFT
#define SOFT_SERIAL_PIN D2
/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 4

// wiring of each half
#define MATRIX_ROW_PINS {  B4, B3, B2, B6, B5}
#define MATRIX_COL_PINS { D4, C6, D7, E6}

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5
#define ENCODERS_PAD_A { B1,F5  }
#define ENCODERS_PAD_B { F7,F6  }
#define ENCODER_RESOLUTION 4
#define ENCODER_DIRECTION_FLIP
#define TAP_CODE_DELAY 10