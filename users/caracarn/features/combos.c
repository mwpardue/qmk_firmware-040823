#include QMK_KEYBOARD_H

#include "combos.h"

//Shortcuts
const uint16_t PROGMEM bootloader_combo[] = {CAP_NAV, KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM sleep_combo[] = {CAP_NAV, KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM playpause_combo[] = {CAP_NAV, CTL_S, SFT_D, COMBO_END};
const uint16_t PROGMEM previous_combo[] = {CAP_NAV, KC_A, CTL_S, COMBO_END};
const uint16_t PROGMEM next_combo[] = {CAP_NAV, SFT_D, GUI_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  COMBO(bootloader_combo, QK_BOOT),
  COMBO(sleep_combo, MACSLEP),
  COMBO(playpause_combo, KC_MPLY),
  COMBO(previous_combo, KC_MPRV),
  COMBO(next_combo, KC_MNXT)

};

extern os_t os;

#ifndef DEFAULT_MOD_ENABLE
    #ifndef SHORTCUTS_ENABLE
        bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
            return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
        }
    #endif
#endif

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t idx = 0;
    bool combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                combo_must_tap = true;
                break;
            default:
                combo_must_tap = false;
                break;
        }
        if (!combo_must_tap) {
            return false;
        }
        idx += 1;
    }
    return combo_must_tap;
}

 process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    // bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    // bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        // case CB_NWTB:
        //     if (record->event.pressed) {
        //         clear_locked_and_oneshot_mods();
        //         if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
        //             SEND_STRING(SS_LCTL("t"));
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         }
        //     }
        //     break;

        // case CB_OPTB:
        //     if (record->event.pressed) {
        //         clear_locked_and_oneshot_mods();
        //         if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
        //             SEND_STRING(SS_LCTL(SS_LSFT("t")));
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         }
        //     }
        //     break;

        // case CB_NCGN:
        //     if (record->event.pressed) {
        //         clear_locked_and_oneshot_mods();
        //         if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
        //             SEND_STRING(SS_LCTL(SS_LSFT("n")));
        //             return PROCESS_RECORD_RETURN_FALSE;
        //         }
        //     }
        //     break;

        }

    return PROCESS_RECORD_CONTINUE;
}
