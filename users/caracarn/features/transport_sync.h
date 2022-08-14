#pragma once

// #include "caracarn.h"
#include "features/rgb_matrix_keys.h"
#include "features/rgb_matrix_ledmaps.h"

typedef union {
    uint32_t raw;
    struct {
        bool    rgb_matrix_ledmap_active  :1;
        bool    rgb_matrix_toggle :1;
    };
} user_runtime_config_t;

user_runtime_config_t user_state;

typedef union {
    uint32_t raw;
    struct {
        bool    rgb_matrix_ledmap_active  :1;
        bool    rgb_matrix_toggle :1;
    };
} rgb_split_config_t;

rgb_split_config_t rgb_split_config;

void keyboard_post_init_transport_sync(void);
void housekeeping_task_transport_sync(void);
