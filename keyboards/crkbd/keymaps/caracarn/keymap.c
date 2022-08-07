#include QMK_KEYBOARD_H
#include "caracarn.h"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

// #ifdef RGB_MATRIX_ENABLE
//     #ifdef RGB_MATRIX_LEDMAPS_ENABLED
//             #include "features/rgb_matrix_ledmaps.c"
//         #else
//             #include "rgb.c"
//     #endif //RGB_MATRIX_LEDMAPS_ENABLED
// #endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
  LLOCK,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    OSMLGUI,
  OSMLCTL, KC_A,   CTL_S,   SFT_D,   GUI_F,   KC_G,                         KC_H,    GUI_J,   SFT_K,   CTL_L,   TD_QUOT, OSMRALT,
  OSMLALT, KC_Z,   KC_X,    KC_C,    ALT_V,   KC_B,                         KC_N,    ALT_M,   KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
                                     ESC_FUN, TAB_NUM, CAP_NAV,    BSP_SYM, SPC_MAC, ENT_MED
),

[_COLEMAK_DH] = LAYOUT_split_3x6_3(
  _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    TD_QUOT, _______,
  _______, KC_A,   CTL_R,   ALT_S,   GUI_KCT, KC_G,                         KC_M,    GUI_N,   ALT_E,   CTL_I,   KC_O,    _______,
  _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                     MOD_KEY, TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  _______,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______,                      KC_COLN, GUI_4,   SFT_5,   CTL_6,   KC_PLUS, _______,
  _______, LLOCK,   MC_SWLE, MC_SWAP, MC_SWRI, _______,                      KC_EQL,  ALT_1,   KC_2,    KC_3,    KC_DOT,  _______,
                                      _______, _______, _______,    SPCSFT,  KC_0,    KC_ENT
),

[_NAVIGATION] = LAYOUT_split_3x6_3(
  _______, _______, CUT,     COPY,    PASTE,   _______,                      _______, KC_WH_U, KC_MS_U, KC_WH_D, TOBAS,   _______,
  _______, SELALL,  KC_LCTL, KC_LSFT, KC_LGUI, _______,                      KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,
  _______, LLOCK,   _______, _______, KC_LALT, TOSYM,                        _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,    KC_BTN2, KC_BTN1, KC_BTN3
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, KC_MINS,                      KC_MINS, KC_7,    KC_8,    KC_9,    TOBAS,   _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN,                      KC_COLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, TOBAS,   KC_UNDS, _______, KC_DOT,  _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, _______, SPCSFT,     KC_BSPC, KC_0,    KC_SPC
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, TOBAS,   KC_GRV,  KC_TILD, KC_BSLS, TIPS,                         _______, _______, _______, _______, _______, _______,
  _______, KC_AT,   KC_BSLS, KC_UNDS, KC_PIPE, KC_SCLN,                      _______, KC_RGUI, KC_RSFT, KC_RCTL, _______, _______,
  _______, TD_CURB, TD_SQRB, TD_PARB, TD_ANGB, _______,                      TONAV,   KC_RALT, _______, _______, LLOCK,   _______,
                                      _______, _______, SPCSFT,     _______, _______, _______
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, TD_VIMQ, MC_SELW, _______, _______, KC_S6,                        TD_SSFL, TD_SNIP, ZOOMIN,  ZOOMOUT, TD_S78,  _______,
  _______, TD_S15,  TD_S119, _______, _______, _______,                      _______, KC_S4,   _______, TD_S310, _______, _______,
  _______, _______, TG_KBAB, TG_CAML, TG_SNAK, _______,                      KC_S12,  KC_S2,   _______, _______, KC_ENT,  _______,
                                      _______, _______,  SPCSFT,    _______, _______, _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  _______, QWERTY,  _______, EEP_RST, _______,  QK_BOOT,                       QK_BOOT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
  _______, TOADJ,   MACSLEP, DEBUG,   DT_PRNT,  DT_UP,                         _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,\
  _______, TOHEX,   _______, COLEMAK, _______,  DT_DOWN,                       _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_MEDIA] = LAYOUT_split_3x6_3( \
  _______, _______, _______, _______, _______,  _______,                       _______, _______, _______, _______, _______, _______,  \
  RGB_ALP, RGB_SPP, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                        RGB_CHG, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,\
  RGB_ALM, RGB_SPM, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                        RGB_MOD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_ADJUST] = LAYOUT_split_3x6_3( \
  _______, TOBAS,   _______, _______, RGB_MDT, _______,                      _______, RGB_MDT, _______, _______, TOBAS,   _______,  \
  RGB_ALP, _______, _______, DEBUG,   DT_PRNT, DT_UP,                        RGB_SPP, RGB_CHG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,\
  RGB_ALM, _______, _______, _______, _______, DT_DOWN,                      RGB_SPM, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,\
                                      _______, _______, _______,    _______, _______, _______ \
)

};

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#undef _______
#define _______ {0, 0, 0}

const ledmap PROGMEM ledmaps[] = {
  [_BASE] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           BAS_UGL,         BAS_UGL,         BAS_UGL,                             BAS_UGL,          BAS_UGL,          BAS_UGL,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           BAS_UGL,                                                                                                   BAS_UGL,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                            BAS_UGL,         BAS_UGL,                             BAS_UGL,          BAS_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),

  [_COLEMAK_DH] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           CMK_UGL,         CMK_UGL,         CMK_UGL,                             CMK_UGL,          CMK_UGL,          CMK_UGL,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           CMK_UGL,                                                                                                   CMK_UGL,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  _______,
                            CMK_UGL,         CMK_UGL,                             CMK_UGL,          CMK_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),

  [_NUMPAD] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, AQUA,    ORANGE,  BLUE,    ORANGE,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NUM_UGL,         NUM_UGL,         NUM_UGL,                             NUM_UGL,          NUM_UGL,          NUM_UGL,
  _______, AQUA,    BLUE,    BLUE,    BLUE,    _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           NUM_UGL,                                                                                                   NUM_UGL,
  _______, PURPLE,  ORANGE,  ORANGE,  ORANGE,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
                            NUM_UGL,         NUM_UGL,                             NUM_UGL,          NUM_UGL,
                                      _______, _______, _______,    AQUA,    CYAN,    GREEN
  ),

  [_NAVIGATION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, ORANGE,  ORANGE,  ORANGE,  _______,                      _______, PINK,    CYAN,    PINK,    BAS_UGL, _______,
           NAV_UGL,         NAV_UGL,         NAV_UGL,                              NAV_UGL,          NAV_UGL,          NAV_UGL,
  _______, ORANGE,  RED,     RED,     RED,     _______,                      PINK,    CYAN,    CYAN,    CYAN,    PINK,    _______,
           NAV_UGL,                                                                                                    NAV_UGL,
  _______, PURPLE,  _______, _______, RED,     SYM_UGL,                      _______, _______, _______, _______, _______, _______,
                            NAV_UGL,         NAV_UGL,                              NAV_UGL,          NAV_UGL,
                                      PURPLE,  _______, _______,    BLUE,    BLUE,    BLUE
  ),

  [_HEX] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, BLUE,    _______, _______, _______, YELLOW,                       YELLOW,  CYAN,    CYAN,    CYAN,    BAS_UGL, _______,
           HEX_UGL,         HEX_UGL,         HEX_UGL,                              HEX_UGL,          HEX_UGL,          HEX_UGL,
  _______, _______, YELLOW,  _______, _______, YELLOW,                       YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           HEX_UGL,                                                                                                    HEX_UGL,
  _______, _______, YELLOW,  _______, YELLOW,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    GREEN,   _______,
                            HEX_UGL,         HEX_UGL,                              HEX_UGL,          HEX_UGL,
                                      _______, _______, BLUE,       BLUE,    CYAN,    BLUE
  ),

  [_SYMBOL] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, BAS_UGL, YELLOW,  YELLOW,  YELLOW,  ORANGE,                       _______, _______, _______, _______, _______, _______,
           SYM_UGL,         SYM_UGL,         SYM_UGL,                             SYM_UGL,          SYM_UGL,          SYM_UGL,
  _______, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,                       _______, RED,     RED,     RED,     _______, _______,
           SYM_UGL,                                                                                                    SYM_UGL,
  _______, GREEN,   GREEN,   GREEN,   GREEN,   _______,                      NAV_UGL, RED,     _______, _______, PURPLE,  _______,
                            SYM_UGL,          SYM_UGL,                            SYM_UGL,          SYM_UGL,
                                      _______, _______, BLUE,       _______, YELLOW,  _______
  ),

  [_MACROS] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, GREEN,   ORANGE,  _______, _______, PURPLE,                       GREEN,   GREEN,   GREEN,   GREEN,   PURPLE,  _______,
           MAC_UGL,         MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,          MAC_UGL,
  _______, PURPLE,  PURPLE,  _______, PURPLE,  _______,                      _______, PURPLE,  _______, PURPLE,  _______, _______,
           MAC_UGL,                                                                                                   MAC_UGL,
  _______, _______, PINK,    PINK,    PINK,    _______,                      PURPLE,  PURPLE,  _______, _______, _______, _______,
                            MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,
                                      _______, _______, BLUE,       _______, _______, _______
  ),

  [_FUNCTION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, BAS_UGL, _______, RED,     _______, _______,                      _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
           FUN_UGL,         FUN_UGL,         FUN_UGL,                             FUN_UGL,          FUN_UGL,          FUN_UGL,
  _______, ADJ_UGL, PURPLE,  RED,     BLUE,    BLUE,                         _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
           FUN_UGL,                                                                                                   FUN_UGL,
  _______, _______, _______, CMK_UGL, _______, BLUE,                         _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
                            FUN_UGL,         FUN_UGL,                             FUN_UGL,          FUN_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),

[_MEDIA] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           MED_UGL,         MED_UGL,         MED_UGL,                             MED_UGL,          MED_UGL,          MED_UGL,
  BLUE,    GREEN,   ORANGE,  CYAN,    PURPLE,  YELLOW,                       RED,     ORANGE,  AQUA,    ORANGE,  _______, _______,
           MED_UGL,                                                                                                   MED_UGL,
  BLUE,    GREEN,   ORANGE,  CYAN,    PURPLE,  YELLOW,                       YELLOW,  AZURE,   GREEN,   AZURE,   _______, _______,
                            MED_UGL,         MED_UGL,                             MED_UGL,          MED_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),

  [_ADJUST] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
           ADJ_UGL,         ADJ_UGL,         ADJ_UGL,                             ADJ_UGL,          ADJ_UGL,          ADJ_UGL,
  RED,     _______, _______, RED,     PURPLE,  YELLOW,                       PURPLE,  RED,     GREEN,   AZURE,   ORANGE,  AQUA,
           ADJ_UGL,                                                                                                   ADJ_UGL,
  RED,     _______, _______, _______, _______, YELLOW,                       PURPLE,  BLUE,    GREEN,   AZURE,   ORANGE,  AQUA,
                             ADJ_UGL,          ADJ_UGL,                          ADJ_UGL,          ADJ_UGL,
                                      _______, _______, _______,    _______, PINK,    AQUA
  ),
};

#undef _______
#define _______ KC_TRNS
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
