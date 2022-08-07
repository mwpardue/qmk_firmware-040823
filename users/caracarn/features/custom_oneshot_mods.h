#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"

typedef struct {
    uint16_t timer;
} oneshot_mods_timer_t;

void check_oneshot_mods_timeout(void);
void clear_locked_and_oneshot_mods(void);
void clear_shift(void);
