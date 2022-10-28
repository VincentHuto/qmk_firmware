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
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

// wiring of each half
#define MATRIX_ROW_PINS {  B2,B6}
#define MATRIX_COL_PINS { D4, C6,E6 ,F7 ,B4,B5,B3,B1}

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5
#define ENCODERS_PAD_A { F5}
#define ENCODERS_PAD_B { F6}
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10