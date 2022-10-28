#pragma once

#include "quantum.h"
#define BONGO_ENABLE

enum oled_modes {
  OLED_BONGO,
  OLED_BONGO_MIN
};
#define LAYOUT_5x8( \
    L00, L01, L02, L03, L04, L05, L06, L07, \
    L10, L11, L12, L13, L14, L15, L16, L17, \
    L20, L21, L22, L23, L24, L25, L26, L27, \
    L30, L31, L32, L33, L34, L35, L36, L37, \
    L40, L41, L42, L43, L44, L45, L46, L47, \
    \
    R08, R09, R0A, R0B, R0C, R0D, R0E, R0F, \
    R18, R19, R1A, R1B, R1C, R1D, R1E, R1F, \
    R28, R29, R2A, R2B, R2C, R2D, R2E, R2F, \
    R38, R39, R3A, R3B, R3C, R3D, R3E, R3F, \
    R48, R49, R4A, R4B, R4C, R4D, R4E, R4F  \
\
) { \
    { L00, L01, L02, L03, L04, L05, L06, L07}, \
    { L10, L11, L12, L13, L14, L15, L16, L17}, \
    { L20, L21, L22, L23, L24, L25, L26, L27}, \
    { L30, L31, L32, L33, L34, L35, L36, L37}, \
    { L40, L41, L42, L43, L44, L45, L46, L47}, \
    { R08, R09, R0A, R0B, R0C, R0D, R0E, R0F}, \
    { R18, R19, R1A, R1B, R1C, R1D, R1E, R1F}, \
    { R28, R29, R2A, R2B, R2C, R2D, R2E, R2F}, \
    { R38, R39, R3A, R3B, R3C, R3D, R3E, R3F}, \
    { R48, R49, R4A, R4B, R4C, R4D, R4E, R4F} \
}
