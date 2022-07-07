#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "quantum.h"

process_record_result_t process_rgb_matrix_keys(uint16_t keycode, keyrecord_t *record);
