#pragma once

#include "caracarn.h"

typedef union {
    uint32_t raw;
    struct {
        bool    rgb_matrix_ledmap_active  :1;
    };
} user_runtime_config_t;

extern user_runtime_config_t user_state;

void keyboard_post_init_transport_sync(void);
void housekeeping_task_transport_sync(void);
