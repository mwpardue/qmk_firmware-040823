#include "caracarn.h"
#include "features/transport_sync.h"
#include "transactions.h"
#include <string.h>

uint32_t transport_user_state = 0;

user_runtime_config_t user_state;

extern bool ledmap_active;

// rgb_split_config_t rgb_split_config;

void user_state_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(transport_user_state)) {
        memcpy(&transport_user_state, initiator2target_buffer, initiator2target_buffer_size);
    }
}

void keyboard_post_init_transport_sync(void) {
    // Register keyboard state sync split transaction
    transaction_register_rpc(RPC_ID_USER_STATE_SYNC, user_state_sync);
}

void user_transport_update(void) {
    if (is_keyboard_master()) {
        // ledmap_active = get_ledmap_active();
        user_state.rgb_matrix_ledmap_active = ledmap_active;
        transport_user_state = user_state.raw;
        // dprintf("MASTER ledmap_active = %d\n", ledmap_active);
        // dprintf("MASTER user_state.rgb_matrix_ledmap_active = %d\n", user_state.rgb_matrix_ledmap_active);
        // dprintf("MASTER transport_user_state = %ld\n", transport_user_state);
        // dprintf("SLAVE user_state.raw = %ld\n", user_state.raw);
        // dprintf("SLAVE ledmap_active = %d\n", ledmap_active);
    } else {
        user_state.raw       = transport_user_state;
        ledmap_active = user_state.rgb_matrix_ledmap_active;
    }
}

void user_transport_sync(void) {
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static uint32_t last_sync = 0;
        static uint32_t last_user_state = 0;
        bool            needs_sync = false;

        // Check if the state values are different
        if (memcmp(&transport_user_state, &last_user_state, sizeof(transport_user_state))) {
            dprintf("memcmp different. LUS: %ld TUS: %ld\n", last_user_state, transport_user_state);
            needs_sync = true;
            memcpy(&last_user_state, &transport_user_state, sizeof(transport_user_state));
            dprintf("memcpy executed. LUS: %ld TUS: %ld\n", last_user_state, transport_user_state);
        }
        // Send to slave every 500ms regardless of state change
        if (timer_elapsed32(last_sync) > 250) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_USER_STATE_SYNC, sizeof(user_state), &user_state)) {
                dprintln("Resetting last_sync");
                last_sync = timer_read32();
                needs_sync = false;
            }
        }
    }
}

void housekeeping_task_transport_sync(void) {
    // Update kb_state so we can send to slave
    user_transport_update();

    // Data sync from master to slave
    user_transport_sync();
}
