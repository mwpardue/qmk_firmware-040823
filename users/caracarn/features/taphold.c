#include QMK_KEYBOARD_H

#include "taphold.h"
#include "features/custom_shortcuts.h"

uint16_t get_tapping_term_result(uint16_t keycode) {
    switch (keycode) {
        case BSP_NUM:
        case DEL_MSE:
        case ESC_FUN:
        case ENT_MED:
        case ENT_HYP:
        case SPC_MEH:
        case ESC_MEH:
        case ENT_NUM:
        case TAB_SYM:
        case BSP_MEH:
        case SPC_MAC:
        case TD_COPY:
        case TD_PAST:
            return g_tapping_term + 40;
        case GUI_4:
        case SFT_5:
        case ALT_6:
        case ALT_4:
        case CTL_PLS:
        case CTL_SCL:
        case KC0_MEH:
        // case CTL_AT:
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
        case FUN_Z:
        // case SFT_D:
        case CTL_D:
        case GUI_F:
        case CTL_A:
        case ALT_S:
        // case SFT_K:
        case ALT_K:
        case GUI_J:
        case CTL_QUO:
        case ALT_CR:
        // case SFT_CS:
        case GUI_CT:
        case GUI_CN:
        // case SFT_CE:
        case ALT_CI:
        case CTL_CO:
        case CTL_S:
        case ALT_L:
            return g_tapping_term + 100;
        case SFT_D:
        case SFT_K:
        case SFT_CS:
        case SFT_CE:
            return get_sft_tapping_term();
        // case CTL_AT:
        //     return g_tapping_term - 50;
        default:
            return g_tapping_term;
    }
}

bool get_tapping_force_hold_result(uint16_t keycode) {
    switch (keycode) {
        case DEL_MSE:
        case BSP_NUM:
        case ENT_MED:
        case ESC_FUN:
        case FUN_Z:
        case ENT_HYP:
        case SPC_MEH:
        case BSP_MEH:
        case ENT_NUM:
        case ESC_MEH:
        // case TAB_SYM:
        case CTL_AT:
        case ALT_BSL:
        case SFT_MNS:
        case GUI_PIP:
        case SFT_BSP:
        case SPC_SYM:
        case GUI_J:
        case SFT_K:
        case ALT_L:
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
        case BSP_NUM:
        case DEL_MSE:
        case ESC_FUN:
        case FUN_Z:
        case ENT_MED:
        case ENT_HYP:
        case ENT_NUM:
        case TAB_SYM:
        case SPC_SYM:
            // Immediately select the hold action when another key is pressed.
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
        case CTL_PLS:
        case CTL_SCL:
        case KC0_MEH:
        case SPCSFT:
        // case SFT_D:
        // case SFT_K:
        case TAB_SYM:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
