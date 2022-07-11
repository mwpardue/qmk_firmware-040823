#include QMK_KEYBOARD_H
#include "caracarn.h"
//#include "features/caps_word.h"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

// #ifdef RGB_MATRIX_ENABLE
//     #ifdef RGB_MATRIX_LEDMAPS_ENABLED
//             #include "rgb_matrix_ledmaps.c"
//         #else
//             #include "rgb.c"
//     #endif //RGB_MATRIX_LEDMAPS_ENABLED
// #endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
  LLOCK,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    OSMLGUI,
  OSMLCTL, KC_A,   CTL_S,   ALT_D,   GUI_F,   KC_G,                         KC_H,    GUI_J,   ALT_K,   CTL_L,   TD_QUOT, OSMRALT,
  OSMLALT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
                                     MOD_KEY, TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
),

// [_COLEMAK_DH] = LAYOUT_split_3x6_3(
//   _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    TD_QUOT, KC_P,    _______,
//   _______, KC_A,   CTL_R,   ALT_S,   GUI_KCT, KC_G,                         KC_M,    GUI_N,   ALT_E,   CTL_I,   KC_O,    _______,
//   _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
//                                      MOD_KEY, TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
// ),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  KC_ESC,                       KC_MINS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_BTN1,                      KC_COLN, GUI_4,   ALT_5,   CTL_6,   KC_PDOT, _______,
  _______, MC_SWAP, MC_SWLE, LCTLC,   MC_SWRI, KC_ENT,                       KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, _______, _______,    SPCSFT,  KC_0,    NAV_LL
),

[_NAVIGATION] = LAYOUT_split_3x6_3(
  _______, KC_ESC,  MC_SWLE, HOME,    MC_SWRI, KC_WH_U,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_DEL,  WORD_LE, END,     WORD_RI, KC_WH_D,                      KC_COLN, GUI_4,   ALT_5,   CTL_6,   KC_PDOT, _______,
  _______, _______, MC_SWLE, MC_SELW, MC_SWRI, _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      LLOCK,   _______, _______,    SPCSFT,  KC_0,    _______
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, KC_MINS,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC, _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN,                      KC_COLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, _______, KC_UNDS, _______, KC_DOT,  _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, _______, SPCSFT,     KC_BSPC, KC_0,    LLOCK
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, KC_ESC,  KC_GRV,  KC_TILD, KC_BSLS, TIPS,                         KC_MINS, KC_AMPR, KC_ASTR, KC_RPRN, KC_BSLS, _______,
  _______, KC_AT,   KC_BSLS, KC_UNDS, KC_PIPE, _______,                      KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_SCLN, _______,
  _______, TD_CURB, TD_SQRB, TD_PARB, TD_ANGB, _______,                      KC_EQL,  KC_EXLM, KC_AT,   KC_HASH, KC_ENT,  _______,
                                      LLOCK,   _______, SPCSFT,     _______, KC_LPRN, _______
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, VIMQ,    VIMWQ,   _______, _______, KC_S6,                        TD_SSFL, TD_SNIP, ZOOMIN,  ZOOMOUT, TD_S78,  _______,
  _______, TD_S15,  TD_S119, _______, FOPEN,   _______,                      _______, KC_S4,   _______, TD_S310, _______, _______,
  _______, _______, TD_KBAB, TD_CAML, TD_SNAK, _______,                      KC_S12,  KC_S2,   _______, _______, ENT_FUN, _______,
                                      LLOCK,   _______,  SPCSFT,    _______, _______, _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,  KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, MACSLEP, _______, EEP_RST,  _______,                       _______, KC_VOLU, KC_MUTE, KC_VOLD, _______, _______,\
  _______, _______, _______, _______, QWERTY,   _______,                       _______, KC_MNXT, KC_MPLY, KC_MPRV, _______, _______,\
                                      TOHEX,     _______,  _______,   _______,  TOMAC,   TOBAS \
),

// [_ADJUST] = LAYOUT_split_3x6_3(
//   _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//   RGB_ALP, _______, _______, DEBUG,   DT_PRNT, DT_UP,                        RGB_SPP, RGB_CHG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
//   RGB_ALM, _______, _______, _______, _______, DT_DOWN,                      RGB_SPM, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
//                                       _______, _______, _______,    _______, _______,   TOBAS
// )

};

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#undef _______
#define _______ {0, 0, 0}

//const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
const ledmap PROGMEM ledmaps[] = {
  [_BASE] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
           BAS_UGL,          BAS_UGL,          BAS_UGL,                      BAS_UGL,          BAS_UGL,          BAS_UGL,
  _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
           BAS_UGL,                   BAS_UGL,
  _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,   _______,
  BAS_UGL, BAS_UGL, BAS_UGL, BAS_UGL,
                                      _______,  _______, _______,       _______, _______,  _______
  ),

//   [_COLEMAK_DH] = RGB_MATRIX_LAYOUT_LEDMAP(
//   _______, _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
//            CMK_UGL,          CMK_UGL,          CMK_UGL,                      CMK_UGL,          CMK_UGL,          CMK_UGL,
//   _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
//            CMK_UGL,                   CMK_UGL,
//   _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,   _______,
//   CMK_UGL, CMK_UGL, CMK_UGL, CMK_UGL,
//                                       _______,  _______, _______,       _______, _______,  _______
//   ),

  [_NUMPAD] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, BLUE,    SPRING,  BLUE,    SPRING,  PURPLE,                       YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NUM_UGL,          NUM_UGL,          NUM_UGL,                      NUM_UGL,          NUM_UGL,          NUM_UGL,
  _______, AQUA,    BLUE,    BLUE,    BLUE,    PINK,                         YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NUM_UGL,                                                    NUM_UGL,
  _______, ORANGE,  ORANGE,  PURPLE,  ORANGE,  GREEN,                        YELLOW,  CYAN,    CYAN,    CYAN,    GREEN,   _______,
                             NUM_UGL,          NUM_UGL,                      NUM_UGL,          NUM_UGL,
                                      _______, _______, _______,    BLUE,    CYAN,    PURPLE
  ),

  [_NAVIGATION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, PURPLE,  SPRING,  BLUE,    SPRING,  PINK,                         YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NAV_UGL,          NAV_UGL,          NAV_UGL,                      NAV_UGL,          NAV_UGL,          NAV_UGL,
  _______, AQUA,    SPRING,  BLUE,    SPRING,  PINK,                         YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NAV_UGL,                NAV_UGL,
  _______, _______, SPRING,  SPRING,  SPRING,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    GREEN,   _______,
                             NAV_UGL, NAV_UGL, NAV_UGL, NAV_UGL,
                                      PURPLE,  _______, _______,    BLUE,    CYAN,    _______
  ),

  [_HEX] = RGB_MATRIX_LAYOUT_LEDMAP(
  BLUE,   ORANGE, BLUE,   ORANGE, BLUE,   ORANGE,                          YELLOW, GREEN,  YELLOW, GREEN,  YELLOW, GREEN,
           RED,          RED,          RED,                       PURPLE,          PURPLE,          PURPLE,
  ORANGE, BLUE,   ORANGE, BLUE,   ORANGE, BLUE,                            GREEN,  YELLOW, GREEN,  YELLOW, GREEN,  YELLOW,
           RED,                                                                                      PURPLE,
  BLUE,   ORANGE, BLUE,   ORANGE, BLUE,   ORANGE,                          YELLOW, GREEN,  YELLOW, GREEN,  YELLOW, GREEN,
                             RED, RED,                                PURPLE, PURPLE,
                                      ORANGE, BLUE, ORANGE,       YELLOW, GREEN, YELLOW
  ),

  [_SYMBOL] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, PURPLE,  YELLOW,  YELLOW,  YELLOW,  ORANGE,                       YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  _______,
           SYM_UGL,          SYM_UGL,          SYM_UGL,                      SYM_UGL,          SYM_UGL,          SYM_UGL,
  _______, YELLOW,  YELLOW,  YELLOW,  YELLOW,  _______,                      YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  _______,
           SYM_UGL,                   SYM_UGL,
  _______, ORANGE,  ORANGE,  ORANGE,  ORANGE,  _______,                      YELLOW,  YELLOW,  YELLOW,  YELLOW,  GREEN,   _______,
  SYM_UGL, SYM_UGL, SYM_UGL, SYM_UGL,
                                      PURPLE,  _______, BLUE,       _______, YELLOW,  _______
  ),

  [_MACROS] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, PURPLE,  PURPLE,  _______, _______, CYAN,                         PURPLE,  PURPLE,  PURPLE,  PURPLE,  CYAN,    _______,
           MAC_UGL,          MAC_UGL,          MAC_UGL,                      MAC_UGL,          MAC_UGL,          MAC_UGL,
  _______, CYAN,    CYAN,    _______, PURPLE,  _______,                      _______, CYAN,    _______, CYAN,    _______, _______,
           MAC_UGL,                  MAC_UGL,
  _______, _______, SPRING,  SPRING,  SPRING,  _______,                      CYAN,    CYAN,    _______, _______, GREEN,   _______,
  MAC_UGL, MAC_UGL, MAC_UGL, MAC_UGL,
                                      PURPLE,  _______, BLUE,       _______, _______, _______
  ),

  [_FUNCTION] = RGB_MATRIX_LAYOUT_LEDMAP(
  GOLD,    GOLD,    GOLD,    GOLD,    GOLD,    GOLD,                         GOLD,    GOLD,    GOLD,    GOLD,    GOLD,    GOLD,
           FUN_UGL,          FUN_UGL,          FUN_UGL,                      FUN_UGL,          FUN_UGL,          FUN_UGL,
  _______, _______, PURPLE,  _______, _______, _______,                      _______, PURPLE,  RED,     GREEN,   _______, _______,
           FUN_UGL,                 FUN_UGL,
  _______, _______, _______, PINK,   AQUA,     YELLOW,                       _______, BLUE,    ORANGE,  YELLOW,  _______, _______,
FUN_UGL, FUN_UGL, FUN_UGL, FUN_UGL,
                                      PURPLE,  PINK,   _______,     _______, AZURE,   AQUA
  ),

//   [_ADJUST] = RGB_MATRIX_LAYOUT_LEDMAP(
//   _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//            ADJ_UGL,          ADJ_UGL,          ADJ_UGL,                      ADJ_UGL,          ADJ_UGL,          ADJ_UGL,
//   RED,     _______, _______, RED,     PURPLE,  YELLOW,                       PURPLE,  RED,     GREEN,   AZURE,   ORANGE,  AQUA,
//            ADJ_UGL,                 ADJ_UGL,
//   RED,     _______, _______, _______, _______, YELLOW,                       PURPLE,  BLUE,    GREEN,   AZURE,   ORANGE,  AQUA,
// ADJ_UGL, ADJ_UGL, ADJ_UGL, ADJ_UGL,
//                                       _______, _______, _______,    _______, PINK,   AQUA
//   ),
};

#undef _______
#define _______ KC_TRNS
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
