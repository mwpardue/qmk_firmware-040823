#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"

process_record_result_t process_capitalize_key(uint16_t keycode, keyrecord_t *record);
