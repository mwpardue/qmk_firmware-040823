#include QMK_KEYBOARD_H

#include "tapdance.h"
#include "secrets.h"
#include "smart_case.h"

//extern os_t os;

static td_tap_t tap_state = {
    .state = TD_NONE
};

/* static tap td_caps_key_tap_state = {
    .is_press_action = true,
    .state = 0
} */

__attribute__ ((weak)) td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Dancing brackets

void td_curly_braces(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LCBR);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            tap_code(KC_LEFT);
            break;
        default: break;
    }
}

void td_square_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_LBRC);
            tap_code16(KC_RBRC);
            tap_code(KC_LEFT);
            break;
        default: break;
    }
}

void td_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_LEFT);
            break;
        default: break;
    }
}

void td_angle_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_LT);
            tap_code16(KC_GT);
            tap_code(KC_LEFT);
            break;
        default: break;
    }
}

// Quotes

void td_quotes(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_QUOT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_DQUO);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_COLN);
            break;
        default: break;
    }
}

void td_secret15(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            send_string(secrets[0]);
            break;
        case TD_DOUBLE_TAP:
            send_string(secrets[4]);
            break;
        default: break;
    }
}

void td_secret78(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            send_string(secrets[6]);
            break;
        case TD_DOUBLE_TAP:
            send_string(secrets[7]);
            break;
        default: break;
    }
}

void td_secret119(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            send_string(secrets[10]);
            break;
        case TD_DOUBLE_TAP:
            send_string(secrets[8]);
            break;
        default: break;
    }
}

void td_secret310(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            send_string(secrets[2]);
            break;
        case TD_DOUBLE_TAP:
            send_string(secrets[9]);
            break;
        default: break;
    }
}

void td_kebab(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_smart_case(KEBAB_CASE);
            break;
        case TD_DOUBLE_TAP:
            set_smart_case(KEBAB_CASE);
            set_smart_case(WORD_CASE);
            break;
        default: break;
    }
}

void td_snake(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_smart_case(SNAKE_CASE);
            break;
        case TD_DOUBLE_TAP:
            set_smart_case(SNAKE_CASE);
            set_smart_case(WORD_CASE);
            break;
        default: break;
    }
}

void td_camel(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_smart_case(CAMEL_CASE);
            break;
        case TD_DOUBLE_TAP:
            set_smart_case(CAMEL_CASE);
            add_oneshot_mods(MOD_LSFT);
            break;
        default: break;
    }
}

void td_screenshot_full(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(LGUI(LSFT(LCTL(KC_3))));
            break;
        case TD_DOUBLE_TAP:
            tap_code16(LGUI(LSFT(KC_3)));
            break;
        default: break;
    }
}

void td_sssnippet_finished (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = dance_state(state);
  switch (tap_state.state) {
    case TD_SINGLE_TAP:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_4);
        break;
    case TD_SINGLE_HOLD:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_4);
        register_code(KC_SPC);
        break;
    case TD_DOUBLE_TAP:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        register_code(KC_4);
        break;
    default: break;
  }
}

void td_sssnippet_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case TD_SINGLE_TAP:
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_4);
        break;
    case TD_SINGLE_HOLD:
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_4);
        unregister_code(KC_SPC);
        break;
    case TD_DOUBLE_TAP:
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_4);
        break;
    default: break;
  }
  tap_state.state = 0;
}

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [SEC1_5] = ACTION_TAP_DANCE_FN(td_secret15),
    [SEC7_8] = ACTION_TAP_DANCE_FN(td_secret78),
    [SEC11_9] = ACTION_TAP_DANCE_FN(td_secret119),
    [SEC3_10] = ACTION_TAP_DANCE_FN(td_secret310),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    [SDB_QUO] = ACTION_TAP_DANCE_FN(td_quotes),
    [KEBAB] = ACTION_TAP_DANCE_FN(td_kebab),
    [SNAKE] = ACTION_TAP_DANCE_FN(td_snake),
    [CAMEL] = ACTION_TAP_DANCE_FN(td_camel),
    [SS_FULL] = ACTION_TAP_DANCE_FN(td_screenshot_full),
    [SS_SNIP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,td_sssnippet_finished, td_sssnippet_reset)
};
