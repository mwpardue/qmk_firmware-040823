#include QMK_KEYBOARD_H

#include "taphold.h"

uint16_t get_tapping_term_result(uint16_t keycode) {
    switch (keycode) {
        case TAB_NUM:
        case SPC_MAC:
        case BSP_MSE:
        case ESC_FUN:
        case ENT_MED:
        case ENT_HYP:
        case SPC_MEH:
        case ENT_NUM:
        case CAP_SYM:
        case BSP_MEH:
            return g_tapping_term + 40;
        case GUI_4:
        case SFT_5:
        case ALT_6:
        case ALT_4:
        case CTL_SCL:
        case KC0_NUM:
            return g_tapping_term + 115;
        // case TD_ANGB:
        // case TD_PARB:
        // case TD_CURB:
        // case TD_SQRB:
        case TD_S15:
        case TD_S78:
        case TD_S119:
        case TD_S310:
        case TD_QUOT:
        case TD_SSFL:
        case TD_SNIP:
            return g_tapping_term + 100;
        case SFT_D:
        case CTL_D:
        case GUI_F:
        case CTL_A:
        case SFT_K:
        case ALT_K:
        case GUI_J:
        case CTL_QUO:
        case CTL_R:
        case ALT_S:
        case GUI_KCT:
        case GUI_N:
        case ALT_E:
        case CTL_I:
        case CTL_S:
        case ALT_L:
            return g_tapping_term + 100;
        default:
            return g_tapping_term;
    }
}

bool get_tapping_force_hold_result(uint16_t keycode) {
    switch (keycode) {
        case BSP_MSE:
        case SPC_MAC:
        case TAB_NUM:
        case ENT_MED:
        case ESC_FUN:
        case ENT_HYP:
        case SPC_MEH:
        case BSP_MEH:
        case ENT_NUM:
        case CAP_SYM:
            return false;
    }
    switch (keycode) {
        case QK_MOD_TAP...QK_MOD_TAP_MAX:
        case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
        case QK_MOMENTARY...QK_MOMENTARY_MAX:
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press_result(uint16_t keycode) {
    switch (keycode) {
        case TAB_NUM:
        case BSP_MSE:
        case ESC_FUN:
        case ENT_MED:
        case ENT_HYP:
        case ENT_NUM:
        case CAP_SYM:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold_result(uint16_t keycode) {
    switch (keycode) {
        case GUI_4:
        case SFT_5:
        case ALT_6:
        case CTL_SCL:
        case KC0_NUM:
        case SPCSFT:
        case SFT_D:
        case SFT_K:
        case CAP_SYM:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
