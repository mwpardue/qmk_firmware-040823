#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"
#include "smart_thumb_keys.h"

// #ifndef DEFAULT_MOD_KEY_ENABLE
//     void clear_locked_and_oneshot_mods(void);
// #endif

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record);
