#pragma once

#include "quantum.h"
#define BONGO_ENABLE

enum oled_modes {
  OLED_BONGO,
  OLED_BONGO_MIN
};
#define LAYOUT_numpad_5x4( \
    K00, K01, K02, K03, K04, K05, K06, K07,\
    K10, K11, K12, K13, K14, K15, K16, K17 \
) { \
    { K00,   K01,   K02,   K03, K04,   K05,   K06,   K07 }, \
    { K10,   K11,   K12,   K13, K14,   K15,   K16,   K17 }, \
}
