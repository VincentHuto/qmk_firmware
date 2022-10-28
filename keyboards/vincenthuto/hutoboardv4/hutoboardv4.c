#include "hutoboardv4.h"

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif
#ifdef OLED_ENABLE

bool oled_task_kb(void) {
    draw_bongo(true);
        return false;

}
#endif
