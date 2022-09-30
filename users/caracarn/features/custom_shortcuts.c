#include QMK_KEYBOARD_H

#include "custom_shortcuts.h"

extern os_t os;

process_record_result_t process_custom_shortcuts(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    uint8_t smart_mods = 0;

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

        case LGUI_T(KC_VOLD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_VOLD);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case LSFT_T(KC_MUTE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MUTE);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case LCTL_T(KC_VOLU):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_VOLU);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case LALT_T(KC_MPRV):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MPRV);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

            case LGUI_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

            // case LSFT_T(KC_AT):
            // if (record->tap.count && record->event.pressed) {
            //     tap_code16(KC_AT);
            //     return PROCESS_RECORD_RETURN_FALSE;
            // }
            // return PROCESS_RECORD_RETURN_TRUE;

            case LALT_T(SM_BRAC):
            if (record->tap.count && record->event.pressed) {
                if ((get_oneshot_mods() & MOD_MASK_SHIFT) || get_mods() & MOD_MASK_SHIFT) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_LBRC);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else if ((get_oneshot_mods() & MOD_MASK_CTRL) || get_mods() & MOD_MASK_CTRL) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_RBRC);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    tap_code16(KC_LBRC);
                    tap_code16(KC_RBRC);
                    tap_code16(KC_LEFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

        case SM_PARN:
            if (record->event.pressed) {
                if ((get_oneshot_mods() & MOD_MASK_SHIFT) || get_mods() & MOD_MASK_SHIFT) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_LPRN);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else if ((get_oneshot_mods() & MOD_MASK_CTRL) || get_mods() & MOD_MASK_CTRL) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_RPRN);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    tap_code16(KC_LPRN);
                    tap_code16(KC_RPRN);
                    tap_code16(KC_LEFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case SM_CURB:
            if (record->event.pressed) {
                if ((get_oneshot_mods() & MOD_MASK_SHIFT) || get_mods() & MOD_MASK_SHIFT) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_LCBR);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else if ((get_oneshot_mods() & MOD_MASK_CTRL) || get_mods() & MOD_MASK_CTRL) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_RCBR);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    tap_code16(KC_LCBR);
                    tap_code16(KC_RCBR);
                    tap_code16(KC_LEFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        // case SM_BRAC:
        //     if (record->event.pressed) {
        //         if ((get_oneshot_mods() & MOD_MASK_SHIFT) || get_mods() & MOD_MASK_SHIFT) {
        //             smart_mods = get_mods();
        //             unregister_mods(smart_mods);
        //             tap_code16(KC_LBRC);
        //             register_mods(smart_mods);
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         } else if ((get_oneshot_mods() & MOD_MASK_CTRL) || get_mods() & MOD_MASK_CTRL) {
        //             smart_mods = get_mods();
        //             unregister_mods(smart_mods);
        //             tap_code16(KC_RBRC);
        //             register_mods(smart_mods);
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         } else {
        //             tap_code16(KC_LBRC);
        //             tap_code16(KC_RBRC);
        //             tap_code16(KC_LEFT);
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         }
        //         return PROCESS_RECORD_RETURN_FALSE;
        //     }

        case SM_ANGB:
            if (record->event.pressed) {
                if ((get_oneshot_mods() & MOD_MASK_SHIFT) || get_mods() & MOD_MASK_SHIFT) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_LT);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else if ((get_oneshot_mods() & MOD_MASK_CTRL) || get_mods() & MOD_MASK_CTRL) {
                    smart_mods = get_mods();
                    unregister_mods(smart_mods);
                    tap_code16(KC_GT);
                    register_mods(smart_mods);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    tap_code16(KC_LT);
                    tap_code16(KC_GT);
                    tap_code16(KC_LEFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }
    return PROCESS_RECORD_CONTINUE;
}
