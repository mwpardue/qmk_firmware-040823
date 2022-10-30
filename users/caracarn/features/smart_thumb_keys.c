#include QMK_KEYBOARD_H

#include "smart_thumb_keys.h"
#ifdef CASEMODE_ENABLE
    #include "casemodes.h"
#endif

extern os_t           os;

uint8_t smart_mods = 0;
extern enum xcase_state xcase_state;
extern bool caps_word_on;

bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
    return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
}

process_record_result_t process_smart_thumb_keys(uint16_t keycode, keyrecord_t *record) {
    bool isWindowsOrLinux    = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotDefaultMod = (!isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_GUI)) ||
                               (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL));
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;


    switch (keycode) {
        case CAP_NUM:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if ((get_mods() & MOD_MASK_SHIFT)) {
                        enable_xcase();
                        enable_caps_word();
                        dprintln("Shift XCASE");
                        return false;
                    } else if ((xcase_state == XCASE_ON)) {
                        disable_xcase();
                        disable_caps_word();
                        dprintln("Disabled XCASE from ON state");
                        return false;
                    } else if ((xcase_state == (XCASE_WAIT))) {
                        dprintf("xcase_state: %d\n", xcase_state);
                        dprintf("caps_word_on: %d\n", caps_word_on);
                        disable_xcase();
                        enable_caps_word();
                        dprintf("Disabled xcase from WAIT and enabled caps_word\n");
                        dprintf("xcase_state: %d\n", xcase_state);
                        dprintf("caps_word_on: %d\n", caps_word_on);
                        return false;
                    } else if ((host_keyboard_led_state().caps_lock)) {
                        dprintf("xcase_state: %d\n", xcase_state);
                        dprintf("caps_word_on: %d\n", caps_word_on);
                        disable_caps_word();
                        dprintf("Disabled caps_word without XCASE state\n");
                        dprintf("xcase_state: %d\n", xcase_state);
                        dprintf("caps_word_on: %d\n", caps_word_on);
                        return false;
                    } else {
                        enable_xcase();
                        dprintln("Enabled XCASE to WAIT state");
                        dprintf("xcase_state: %d\n", xcase_state);
                        dprintf("caps_word_on: %d\n", caps_word_on);
                        return false;
                    }





                //    if ((get_mods() & MOD_MASK_ALT) && (get_mods() & MOD_MASK_SHIFT)) {
                //         smart_mods = get_mods();
                //         unregister_mods(smart_mods);
                //         enable_xcase();
                //         enable_caps_word();
                //         dprintf("Mod Mask Alt and Shift action\n");
                //         return false;
                //     } else if ((get_mods() & MOD_MASK_CTRL) && (get_mods() & MOD_MASK_SHIFT)) {
                //         smart_mods = get_mods();
                //         unregister_mods(smart_mods);
                //         enable_xcase_with(KC_UNDS);
                //         enable_caps_word();
                //         dprintf("Mod Mask Ctrl and Shift action\n");
                //         return false;
                //     } else if ((get_mods() & MOD_MASK_ALT)) {
                //         smart_mods = get_mods();
                //         unregister_mods(smart_mods);
                //         enable_xcase();
                //         dprintf("Mod Mask Alt action\n");
                //         return false;
                //     } else if ((get_mods() & MOD_MASK_CTRL)) {
                //         smart_mods = get_mods();
                //         unregister_mods(smart_mods);
                //         enable_xcase_with(KC_UNDS);
                //         dprintf("Mod Mask Ctrl action\n");
                //         return false;
                //     } else if ((get_mods() & MOD_MASK_SHIFT)) {
                //         smart_mods = get_mods();
                //         unregister_mods(smart_mods);
                //         clear_locked_and_oneshot_mods();
                //         enable_caps_word();
                //         dprintf("Mod Mask Shift action\n");
                //         return false;
                //     } else if ((xcase_state != (XCASE_OFF)) || (host_keyboard_led_state().caps_lock)) {
                //         dprintf("xcase_state: %d\n", xcase_state);
                //         dprintf("caps_word_on: %d\n", caps_word_on);
                //         disable_xcase();
                //         disable_caps_word();
                //         dprintf("Disabled xcase and caps_word\n");
                //         dprintf("xcase_state: %d\n", xcase_state);
                //         dprintf("caps_word_on: %d\n", caps_word_on);
                //         return false;
                //     } else if ((isOneShotShift) || (isOneShotLockedShift)) {
                //         unregister_mods(MOD_LSFT);
                //         unregister_mods(MOD_RSFT);
                //         clear_locked_and_oneshot_mods();
                //         enable_caps_word();
                //         dprintf("Enabled Caps Word\n");
                //         return false;
                //     } else if  ((!isOneShotShift) || (!isOneShotLockedShift)) {
                //         add_oneshot_mods(MOD_BIT(KC_LSFT));
                //         dprintf("Applied OSM\n");
                //         return false;
                //     }






                    // } else if (isOneShotShift && get_mods() == 0) {
                    //     clear_locked_and_oneshot_mods();
                    //     enable_caps_word();

            //         if (has_any_smart_case()) {
            //             disable_smart_case();
            //             clear_shift();
            //         } else {
            //             if (isAnyOneShotButShift || isOneShotLockedShift) {
            //                 clear_locked_and_oneshot_mods();
            //             } else if (!isOneShotShift && get_mods() == 0) {
            //                 add_oneshot_mods(MOD_BIT(KC_LSFT));
            //             } else {
            //                 set_smart_case_for_mods(record);
            //             }
            //         }
            //     }
                return PROCESS_RECORD_RETURN_FALSE;
            }

                case MOD_KEY:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotDefaultMod) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                            add_oneshot_mods(MOD_LCTL);
                        } else {
                            add_oneshot_mods(MOD_LGUI);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;
    }
}
    return PROCESS_RECORD_CONTINUE;
}
