#include QMK_KEYBOARD_H

// enum combo_events {
//     FLASH_BOOT,
//     COMBO_LENGTH
// };
// uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_3x3(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    )
};


const uint16_t PROGMEM bootloader_combo[] = {KC_P7, KC_P9, KC_P1, KC_P3, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(bootloader_combo, QK_BOOT),
    // [FLASH_BOOT] = COMBO_ACTION(bootloader_combo),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case FLASH_BOOT:
//       if (pressed) {
//         SEND_STRING("combo initiated");
//         reset_keyboard();
//       }
//       break;
//   }
// }
