#include QMK_KEYBOARD_H
#include "caracarn.h"
//#include "features/caps_word.h"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#ifdef RGB_MATRIX_ENABLE
    #include "rgb.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
  LLOCK,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    OSMRALT,
  OSMLCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    TD_QUOT, OSMLGUI,
  OSMLALT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
                                      OSMLGUI, TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  TIPS,                         KC_MINS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_AT,                        KC_COLN, GUI_4,   ALT_5,   CTL_6,   KC_PDOT, _______,
  _______, SS_SWIN, KC_BTN2, LCTLC,   KC_BTN1, KC_ENT,                       KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, TOBAS,   _______,    SPCSFT,  KC_0,    _______
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, KC_MINS,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC, _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN,                      KC_COLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, _______, KC_UNDS, _______, KC_DOT,  _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      TOBAS,   TOBAS,   SPCSFT,     KC_BSPC, KC_0,    _______
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, KC_ESC,  KC_GRV,  KC_TILD, KC_BSLS, KC_TAB,                       KC_UNDS, KC_AMPR, KC_ASTR, KC_LPRN, KC_PSLS, _______,
  _______, KC_AT,   TIPS,    KC_UNDS, KC_PIPE, KC_COLN,                      KC_SCLN, KC_DLR,  KC_PERC, KC_CIRC, KC_SCLN, _______,
  _______, TD_CURB, TD_SQRB, TD_PARB, TD_ANGB, KC_MINS,                      KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_ENT,  _______,
                                      _______, TOBAS,   SPCSFT,     _______, KC_RPRN, _______
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, VIMQ,    VIMWQ,   _______, _______, KC_S6,                        SS3,     SS4,     ZOOMIN,  ZOOMOUT, TD_S78,  _______,
  _______, TD_S15,  TD_S119, _______, FOPEN,   _______,                      KC_COLN, KC_S4,   _______, TD_S310, _______, _______,
  _______, _______, _______, _______, _______, _______,                      KC_S12,  KC_S2,   _______, _______, KC_ENT,  _______,
                                      _______, SPCSFT,  KC_LSFT,    TOBAS,   TOMAC,   _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, KC_VOLU, MACSLEP, DEBUG,   DT_PRNT, DT_UP,                        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,\
  _______, KC_VOLD, KC_MPLY, KC_MPRV, KC_MNXT, DT_DOWN,                      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,\
                                      TOHEX,   TONUM,   TOFUN,      TOSYM,   TOMAC,   TOBAS \
)


};
