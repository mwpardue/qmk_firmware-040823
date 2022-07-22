#include QMK_KEYBOARD_H

#include "custom_shortcuts.h"

extern os_t os;

// #ifndef DEFAULT_MOD_ENABLE
//         bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
//             return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
//         }
// #endif

process_record_result_t process_custom_shortcuts(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        // Zoom shortcuts

        case SS_MODP:
            if (record->event.pressed) {
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("+"));
                } else {
                    SEND_STRING(SS_LGUI("+"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_MODM:
            if (record->event.pressed) {
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("-"));
                } else {
                    SEND_STRING(SS_LGUI("-"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case QWERTY:
            if (record->event.pressed) {
                dprintf("Base layer changed to QWERTY\n");
                set_single_persistent_default_layer(_BASE);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
                dprintf("Base layer changed to COLEMAK\n");
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case TG_KBAB:
            if (record->event.pressed) {
                if (has_smart_case(KEBAB_CASE) && has_smart_case(WORD_CASE)) {
                    disable_smart_case();
                } else if (has_smart_case(KEBAB_CASE)) {
                    set_smart_case(WORD_CASE);
                } else {
                    set_smart_case(KEBAB_CASE);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case TG_SNAK:
            if (record->event.pressed) {
                if (has_smart_case(SNAKE_CASE) && has_smart_case(WORD_CASE)) {
                    disable_smart_case();
                } else if (has_smart_case(SNAKE_CASE)) {
                    set_smart_case(WORD_CASE);
                } else {
                    set_smart_case(SNAKE_CASE);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case TG_CAML:
            if (record->event.pressed) {
                if (has_smart_case(CAMEL_CASE)) {
                    disable_smart_case();
                } else {
                    set_smart_case(CAMEL_CASE);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

    }

    return PROCESS_RECORD_CONTINUE;
}
