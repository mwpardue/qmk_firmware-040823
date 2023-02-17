#include QMK_KEYBOARD_H

#include "custom_oneshot_mods.h"

extern os_t os;

static custom_oneshots_t custom_oneshots = {.timer = 0};
static bool              holding_oneshot_layer = false;

// Custom oneshot mods

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        custom_oneshots.timer = timer_read();
    } else {
        custom_oneshots.timer = 0;
    }
}

void clear_locked_and_oneshot_mods(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (oneshot_locked_mods || oneshot_mods) {
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        unregister_mods(MOD_LSFT);
        unregister_mods(MOD_LCTL);
        unregister_mods(MOD_LALT);
        unregister_mods(MOD_RALT);
        unregister_mods(MOD_LGUI);
    }
    dyn_macro_reset();
}

void clear_oneshot_mods_state(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (!(oneshot_locked_mods & MOD_LSFT) && (oneshot_mods & MOD_LSFT)) {
        del_oneshot_mods(MOD_LSFT);
        unregister_mods(MOD_LSFT);
    }
    if (!(oneshot_locked_mods & MOD_LCTL) && (oneshot_mods & MOD_LCTL)) {
        del_oneshot_mods(MOD_LCTL);
        unregister_mods(MOD_LCTL);
    }
    if (!(oneshot_locked_mods & MOD_LGUI) && (oneshot_mods & MOD_LGUI)) {
        del_oneshot_mods(MOD_LGUI);
        unregister_mods(MOD_LGUI);
    }
    if (!(oneshot_locked_mods & MOD_LALT) && (oneshot_mods & MOD_LALT)) {
        del_oneshot_mods(MOD_LALT);
        unregister_mods(MOD_LALT);
    }
    if (!(oneshot_locked_mods & MOD_RALT) && (oneshot_mods & MOD_RALT)) {
        del_oneshot_mods(MOD_RALT);
        unregister_mods(MOD_RALT);
    }
}

void disable_oneshot_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    custom_oneshots.timer = 0;
}

void disable_oneshot_mods(void) {
    clear_oneshot_mods_state();
    custom_oneshots.timer = 0;
}

void check_disable_oneshot(uint16_t keycode) {
    switch (keycode) {
        case NAV_ACT:
        case MED_CAS:
        case MAI_CAS:
        case MAI_ACT:
        case OS_LOW:
        case OS_RAI:
        case OS_LSFT:
        case OS_LCTL:
        case OS_LALT:
        case OS_LGUI:
            break;
        default:
            if (!holding_oneshot_layer) {
                disable_oneshot_layer();
            }
    }
}

// Custom oneshot timeout

bool custom_oneshots_expired(void) {
    return custom_oneshots.timer > 0 && (timer_elapsed(custom_oneshots.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_oneshot_timeout(void) {
    if (custom_oneshots_expired()) {
        disable_oneshot_mods();
        disable_oneshot_layer();
    }
}

// Custom oneshot keycodes

bool should_send_ctrl(bool isMacOS, bool isOneShotShift) {
    return (!isMacOS && !isOneShotShift) || (isMacOS && isOneShotShift);
}

process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record) {
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {
        case OS_LOW:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_LOWER)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_LOWER, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (record->event.pressed) {
                    holding_oneshot_layer = true;
                } else {
                    holding_oneshot_layer = false;
                }
            }
        case OS_RAI:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_RAISE)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_RAISE, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (record->event.pressed) {
                    holding_oneshot_layer = true;
                } else {
                    holding_oneshot_layer = false;
                }
            }

        case NAV_ACT:
        case MAI_ACT:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isOneShotLockedShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (get_mods() != 0) {
                        set_smart_case_for_mods(record);
                    } else if (!IS_LAYER_ON(_ACCENT)) {
                        set_oneshot_layer(_ACCENT, ONESHOT_START);
                        custom_oneshots.timer = timer_read();
                    } else {
                        if (!isOneShotShift && get_mods() == 0) {
                            add_oneshot_mods(MOD_LSFT);
                        } else {
                            clear_oneshot_layer_state(ONESHOT_PRESSED);
                            clear_shift();
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

        case MED_CAS:
        case MAI_CAS:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift || isOneShotLockedShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift && get_mods() == 0) {
                            add_oneshot_mods(MOD_LSFT);
                        } else {
                            set_smart_case_for_mods(record);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
