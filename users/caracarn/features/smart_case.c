#include QMK_KEYBOARD_H

#include "smart_case.h"

// Custom oneshot mods timer

static oneshot_mods_timer_t oneshot_mods_timer = {.timer = 0};

static int8_t distance_to_last_delim = -1;

void clear_expired_oneshot_mods(void) {
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

void disable_expired_oneshot_mods(void) {
    clear_expired_oneshot_mods();
    oneshot_mods_timer.timer = 0;
}

bool oneshot_mods_timer_expired(void) {
    return oneshot_mods_timer.timer > 0 && (timer_elapsed(oneshot_mods_timer.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_oneshot_mods_timeout(void) {
    if (oneshot_mods_timer_expired()) {
        disable_expired_oneshot_mods();
    }
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        oneshot_mods_timer.timer = timer_read();
    } else {
        oneshot_mods_timer.timer = 0;
    }
}

// Smart Cases

smart_case_t smart_case = {.timer = 0, .type = NO_CASE};

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
    //dyn_macro_reset();
}

void clear_shift(void) {
    del_oneshot_mods(MOD_LSFT);
    unregister_mods(MOD_LSFT);
}

bool smart_case_timer_expired(void) {
    return smart_case.timer > 0 && (timer_elapsed(smart_case.timer) > 5 * CUSTOM_ONESHOT_TIMEOUT);
}

void start_smart_case_timer(void) {
    smart_case.timer = timer_read();
}

void clear_smart_case_timer(void) {
    smart_case.timer = 0;
}

void disable_smart_case(void) {
    smart_case.type = NO_CASE;
    clear_smart_case_timer();
    clear_shift();
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void check_disable_smart_case(void) {
    if (smart_case_timer_expired()) {
        disable_smart_case();
    }
}

void enable_smartcase(smart_case_type_t smart_case_types) {
    if (smart_case.type == NO_CASE) {
        smart_case.type = smart_case_types;
    } else {
        smart_case.type = smart_case.type | smart_case_types;
    }
    start_smart_case_timer();
}

void enable_capslock(void) {
    enable_smartcase(CAPS_LOCK);
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void set_smart_case(smart_case_type_t smart_case_types) {
    if (smart_case_types & CAPS_LOCK) {
        enable_capslock();
        return;
    }
    if (smart_case_types & WORD_CASE) {
        // Setting CamelCase with CapsWord already set, makes Pascal Case
        if (has_smart_case(CAMEL_CASE)) {
            add_oneshot_mods(MOD_LSFT);
            return;
        }
        if (!host_keyboard_led_state().caps_lock) {
            tap_code(KC_CAPS);
        }
    }
    if (smart_case_types & CAMEL_CASE) {
        // Setting CapsWord with CamelCase already set, makes Pascal Case
        if (has_smart_case(WORD_CASE)) {
            disable_smart_case();
            add_oneshot_mods(MOD_LSFT);
        }
    }
    enable_smartcase(smart_case_types);
}

bool has_smart_case(smart_case_type_t smart_case_types) {
    return smart_case.type & smart_case_types;
}

bool has_any_smart_case(void) {
    return smart_case.type != NO_CASE;
}

void toggle_capslock(bool capslock) {
    if (capslock) {
        set_smart_case(CAPS_LOCK);
    } else {
        disable_smart_case();
    }
}

void toggle_smart_case(smart_case_type_t smart_case_types) {
    if (has_smart_case(smart_case_types)) {
        disable_smart_case();
    } else {
        set_smart_case(smart_case_types);
    }
}

process_record_result_t process_smart_case_options(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_WORD:
                toggle_smart_case(WORD_CASE);
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_CAPS:
                toggle_capslock(!host_keyboard_led_state().caps_lock);
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_SNAK:
                toggle_smart_case(SNAKE_CASE);
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_KBAB:
                toggle_smart_case(KEBAB_CASE);
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_CAML:
                toggle_smart_case(CAMEL_CASE);
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}

void set_smart_case_for_mods(keyrecord_t *record) {
    int8_t mods = get_mods();
    disable_smart_case();
    if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_SHIFT) && (mods & MOD_MASK_ALT)) {
        process_smart_case_options(MC_CAPS, record);
        return;
    }
    if (mods == 0 || mods & MOD_MASK_CTRL) {
        process_smart_case_options(MC_WORD, record);
    }
    if (mods & MOD_MASK_SHIFT) {
        process_smart_case_options(MC_CAML, record);
        return;
    }
    if (mods & MOD_MASK_ALT) {
        process_smart_case_options(MC_SNAK, record);
        return;
    }
    if (mods & MOD_MASK_GUI) {
        process_smart_case_options(MC_KBAB, record);
        return;
    }
}

process_record_result_t process_smart_case_chars(uint16_t keycode, keyrecord_t *record) {
    if (has_any_smart_case() && record->event.pressed) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet.
                if (record->tap.count == 0) {
                    return PROCESS_RECORD_CONTINUE;
                }
                // Get the base tapping keycode of a mod- or layer-tap key.
                keycode = extract_base_tapping_keycode(keycode);
        }
        // Extend, process or break case
        switch (keycode) {
            case KC_SPC:
                if (has_smart_case(WORD_CASE) && !(has_smart_case(SNAKE_CASE)) && !(has_smart_case(KEBAB_CASE)) &&
                    !(has_smart_case(CAMEL_CASE))) {
                    disable_smart_case();
                    return PROCESS_RECORD_CONTINUE;
                }
                if (has_smart_case(SNAKE_CASE)) {
                    if (distance_to_last_delim != 0) {
                        tap_code16(KC_UNDS);
                        distance_to_last_delim = 0;
                        start_smart_case_timer();
                    } else {
                        disable_smart_case();
                        tap_code16(KC_BSPC);
                        distance_to_last_delim = -1;
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(KEBAB_CASE)) {
                    if (distance_to_last_delim != 0) {
                        tap_code16(KC_MINS);
                        distance_to_last_delim = 0;
                        start_smart_case_timer();
                    } else {
                        disable_smart_case();
                        tap_code16(KC_BSPC);
                        distance_to_last_delim = -1;
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(CAMEL_CASE)) {
                    if (distance_to_last_delim != 0) {
                        add_oneshot_mods(MOD_BIT(KC_LSFT));
                        distance_to_last_delim = 0;
                        start_smart_case_timer();
                    } else {
                        disable_smart_case();
                        del_oneshot_mods(MOD_LSFT);
                        distance_to_last_delim = -1;
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            //case STR_MACRO_START ... STR_MACRO_END:
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_MINS:
            case KC_UNDS:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_UP:
            case KC_DOWN:
            case KC_HOME:
            case KC_END:
            case TG_SNAK:
            case TG_KBAB:
            case TG_CAML:
                start_smart_case_timer();
                distance_to_last_delim = -1;
                break;
            default:
                if (is_key_on_tap(keycode) && (has_smart_case(WORD_CASE) || !has_smart_case(CAPS_LOCK))) {
                    disable_smart_case();
                }
                break;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_smart_case(uint16_t keycode, keyrecord_t *record) {
    switch (process_smart_case_chars(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return PROCESS_RECORD_RETURN_TRUE;
        case PROCESS_RECORD_RETURN_FALSE:
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    switch (process_smart_case_options(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return PROCESS_RECORD_RETURN_TRUE;
        case PROCESS_RECORD_RETURN_FALSE:
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
}
