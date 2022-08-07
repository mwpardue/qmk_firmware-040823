#include "caracarn.h"
#include "transactions.h"
#include <string.h>

typedef union {
    uint32_t raw;
    struct {
        bool    rgb_matrix_ledmap_active  :1;
    };
} user_runtime_config_t;

user_runtime_config_t user_state;

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    // if buffer length matches size of data structure (simple error checking)
    if (in_buflen == sizeof(user_state)) {
        // copy data from master into local data structure
        memcpy(&user_state, in_data, in_buflen);
    }
}

void keyboard_post_init_user(void) {
    // register sync handler
    transaction_register_rpc(RPC_ID_USER_STATE_SYNC, user_sync_a_slave_handler);
}
void housekeeping_task_user(void) {
    if (is_keyboard_master()) {

// update values
        // copy local variable to sync data structure
        user_state.rgb_matrix_ledmap_active = ledmap_active;

// sync values
        static uint32_t last_sync = 0;
        static uint32_t last_user_state = 0;
        static bool needs_sync = false;

        // if value is different, then needs syncing
        if (memcmp(&user_state, &last_user_state, sizeof(user_state))) {
            needs_sync = true;
            // copy local user state to verify changes
            memcpy(&last_user_state, &user_state, sizeof(user_state));
        }
        // Send to slave every 250ms regardless of state change
        if (timer_elapsed32(last_sync) > 250) {
            needs_sync = true;
        }

        // if it needs syncing:
        if (needs_sync) {
            // send user_data stuct over to slave
            if(transaction_rpc_send(RPC_ID_USER_STATE_SYNC, sizeof(user_state), &user_state)) {
                // reset sync checks
                last_sync = timer_read32();
                needs_sync = false;
            }
        }

    } else { // not master:
        // copy value from data structure to local variable
        ledmap_active = user_state.rgb_matrix_ledmap_active;
    }
}
