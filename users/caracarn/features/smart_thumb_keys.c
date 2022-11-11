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
        case XCS_SFT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (xcase_state == XCASE_WAIT && host_keyboard_led_state().caps_lock) {
                        disable_xcase();
                        disable_caps_word();
                        dprintln("Disabled XCASE and Caps Word");
                    }
                    else if (xcase_state == XCASE_WAIT) {
                        // enable_xcase();
                        enable_caps_word();
                        dprintln("XCASE WAIT, enabled Caps Word");
                    }
                    else if (xcase_state == XCASE_ON) {
                        disable_xcase();
                        disable_caps_word();
                        dprintln("Disable XCASE from ON state");
                    }
                    else {
                        enable_xcase();
                        dprintln("Enabling XCASE to WAIT state");
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

            case CAP_FUN:
                if (record->tap.count > 0) {
                    if (record->event.pressed) {
                      if (caps_word_on) {
                        disable_caps_word();
                        tap_code(KC_CAPS);
                      }
                      else if (host_keyboard_led_state().caps_lock) {
                        disable_caps_word();
                        // tap_code(KC_CAPS);
                      }
                      else {
                        enable_caps_word();
                      }
                        // if (host_keyboard_led_state().caps_lock) {
                        //     disable_caps_word();
                        //     dprintln("CAP_FUN disabling caps word");
                        // } else {
                        //     enable_caps_word();
                        //     dprintln("CAP_FUN enabled caps word");
                        // }
                    }
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
// } Remove quotes and fix curly brackets, if thumb keys don't work.
    return PROCESS_RECORD_CONTINUE;
}
