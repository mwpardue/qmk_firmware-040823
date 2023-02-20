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
  EE_CLR,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    OSMLGUI,
  OSMLCTL, KC_A,   CTL_S,   SFT_D,   GUI_F,    KC_G,                        KC_H,    GUI_J,   SFT_K,   CTL_L,   KC_QUOT, OSMRALT,
  LEADER,  KC_Z,   KC_X,    KC_C,    ALT_V,    KC_B,                        KC_N,    ALT_M,   KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
                                     ESC_MEH, TAB_NAV, SFT_NUM,    BSP_SYM, SPC_MAC, ENT_HYP
),

[_COLEMAK_DH] = LAYOUT_split_3x6_3(
  _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    TD_QUOT, _______,
  _______, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
  _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                     ESC_NUM, TAB_NAV, MOD_SFT,    BSP_SYM, SPC_CTL, ENT_MAC
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, EE_CLR,  _______, SS3,                          KC_BSLS, KC_7,    KC_8,    KC_9,    KC_SLSH, _______,
  _______, KC_BSPC, OSMLCTL, OSMLSFT, OSMLGUI, SS4,                          KC_MINS, KC_4,    KC_5,    KC_6,    KC_SCLN, _______,
  _______, UNDO,    CUT,     COPY,    OPT_PST, _______,                      KC_EQL,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                      _______, _______, _______,    SPC_SYM, KC_0,    ENT_HYP
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, TIPS,                        KC_GRV,  KC_AMPR, KC_ASTR, KC_LPRN, KC_TILD, _______,
  _______, KC_AT,   KC_BSLS, KC_MINS, KC_UNDS, KC_PIPE,                     KC_PIPE, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN, _______,
  _______, KC_LT,   KC_GT,   KC_LBRC, KC_RBRC, _______,                     KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_DOT,  _______,
                                      _______, _______, FUN_XCS,   _______, _______, _______
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, _______,                      KC_PIPE, KC_7,    KC_8,    KC_9,    KC_TILD, _______,
  _______, _______, KC_SLSH, _______, _______, _______,                      KC_UNDS, KC_4,    KC_5,    KC_6,    KC_COLN, _______,
  _______, TOBAS,   TOBAS,   _______, _______, _______,                      KC_MINS, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                      _______, _______, KC_BSPC,     KC_SPC, KC_0,    KC_ENT
),

[_NAVIGATION] = LAYOUT_split_3x6_3(
  _______, BRWS_BK, TAB_LFT, BRWS_FW, TAB_RGT, _______,  		             WD_LEFT, SEL_WRD,  SEL_LIN, WD_RGHT, PASSPAL, _______,
  _______, MC_SWRI, OSMLCTL, OSMLSFT, OSMLGUI, _______,                  KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______,
  _______, MC_SWLE, MOV_LFT, MC_SWAP, ALT_RGT, KC_ENT,  		             _______, _______,  _______, _______, _______, _______,
							                        _______, _______, _______,    KC_BSPC, KC_SPC,  KC_ENT
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, _______, _______, _______, _______, _______,                      _______, KC_VOLD,  KC_MUTE, KC_VOLU, PASSPAL, _______,
  _______, _______, MON_L,   MON_M,   MON_R,   _______,                      _______, OSMRGUI,  OSMRSFT, OSMRCTL, _______, _______,
  _______, MON_BL,  MAX_SCR, _______, _______, _______,                      _______, OSMRALT,  KC_MPRV, KC_MPLY, KC_MNXT, _______,
                                      OSMHYPR, OSMMEH,  _______,    _______, _______, _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  _______, TOADJ,   _______, _______, _______, CAD,                           _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
  _______, MDT_TTP, _______, TOADJ,   _______, _______,                       _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,\
  _______, MDT_TTM, TOHEX,   _______, _______, _______,                       _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_MEDIA] = LAYOUT_split_3x6_3( \
  _______, _______, _______, _______, _______,  _______,                       _______, _______, _______, _______, _______, _______,  \
  RGB_ALP, RGB_SPP, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                        RGB_CHG, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,\
  RGB_ALM, RGB_SPM, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                        RGB_MOD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_ADJUST] = LAYOUT_split_3x6_3( \
  _______, TOBAS,   TOCMK,   EE_CLR,  QK_RBT,  _______,                      _______, RGB_MDT, MDT_TTM, MDT_TTP, TOBAS,   _______,  \
  RGB_ALP, RGB_ALP, RGB_SPP, DB_TOGG, DT_PRNT, DT_UP,                        RGB_CHG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,\
  RGB_ALM, RGB_ALM, RGB_SPM, SFT_TTM, SFT_TTP, DT_DOWN,                      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,\
                                      ACH_TTM, _______, _______,    _______, _______, ACH_TTP \
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

  [_NAVIGATION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, AZURE,   ORANGE,  AZURE,   ORANGE,  CYAN,                        YELLOW,  AQUA,    PINK,    YELLOW,  RED,     _______,
           NAV_UGL,         NAV_UGL,         NAV_UGL,                             NAV_UGL,          NAV_UGL,          NAV_UGL,
  _______, PURPLE,  PURPLE,  PURPLE,  PURPLE,  CYAN,                        BLUE,    BLUE,    BLUE,    BLUE,    _______, _______,
           NAV_UGL,                                                                                                   NAV_UGL,
  _______, BLUE,    AQUA,    BLUE,    AQUA,    GREEN,                        ORANGE, PINK,    AQUA,    ORANGE,  _______, _______,
                            NAV_UGL,         NAV_UGL,                             NAV_UGL,          NAV_UGL,
                                      _______, _______, _______,    AQUA,    CYAN,    GREEN
  ),

  [_NUMPAD] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, _______,                  ORANGE,  BLUE,    BLUE,    BLUE,    ORANGE,  _______,
           NUM_UGL,         NUM_UGL,         NUM_UGL,                              NUM_UGL,          NUM_UGL,          NUM_UGL,
  _______, PURPLE,  PURPLE,  PURPLE,  PURPLE,  _______,                  ORANGE,  BLUE,    BLUE,    BLUE,    ORANGE,  _______,
           NUM_UGL,                                                                                                    NUM_UGL,
  _______, _______, _______, _______, AZURE,   GREEN,                    ORANGE,  BLUE,    BLUE,    BLUE,    ORANGE,  _______,
                            NUM_UGL,         NUM_UGL,                              NUM_UGL,          NUM_UGL,
                                      _______, _______, _______,    YELLOW,  BLUE,    GREEN
  ),

  [_HEX] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, BLUE,    _______, _______, _______, YELLOW,                       YELLOW,  CYAN,    CYAN,    CYAN,    BAS_UGL, _______,
           HEX_UGL,         HEX_UGL,         HEX_UGL,                              HEX_UGL,          HEX_UGL,          HEX_UGL,
  _______, _______, YELLOW,  _______, _______, YELLOW,                       YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           HEX_UGL,                                                                                                    HEX_UGL,
  _______, PURPLE,  YELLOW,  _______, YELLOW,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
                            HEX_UGL,         HEX_UGL,                              HEX_UGL,          HEX_UGL,
                                      _______, _______, BLUE,       BLUE,    CYAN,    GREEN
  ),

  [_SYMBOL] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, AQUA,    YELLOW,  BLUE,    GREEN,   ORANGE,                       _______, CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           SYM_UGL,         SYM_UGL,         SYM_UGL,                             SYM_UGL,          SYM_UGL,          SYM_UGL,
  _______, ORANGE,  GOLD,    MAGENT,  PURPLE,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           SYM_UGL,                                                                                                    SYM_UGL,
  _______, GREEN,   GREEN,   CYAN,    CYAN,    _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    _______, _______,
                            SYM_UGL,          SYM_UGL,                            SYM_UGL,          SYM_UGL,
                                      _______, PURPLE,  PURPLE,     _______, _______, _______
  ),

  [_MACROS] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______, _______, AQUA,                         _______, GREEN,   GREEN,   GREEN,   RED,  _______,
           MAC_UGL,         MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,          MAC_UGL,
  _______, _______, AQUA,    _______, YELLOW,  _______,                      _______, PURPLE, PURPLE, PURPLE,  PURPLE, _______,
           MAC_UGL,                                                                                                   MAC_UGL,
  _______, _______, AQUA,    PINK,    AQUA,    _______,                      _______, ORANGE, ORANGE, ORANGE, _______, _______,
                            MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,
                                      PURPLE, PURPLE, _______,    _______, _______, _______
  ),

  [_FUNCTION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, ADJ_UGL, _______, _______, _______, RED,                             _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
           FUN_UGL,         FUN_UGL,         FUN_UGL,                             FUN_UGL,          FUN_UGL,          FUN_UGL,
  _______, _______, _______, ADJ_UGL, _______, _______,                         _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
           FUN_UGL,                                                                                                   FUN_UGL,
  _______, _______, HEX_UGL, _______, _______, _______,                         _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
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

// [_ADJUST] = RGB_MATRIX_LAYOUT_LEDMAP(
//   _______, BAS_UGL, _______, RED,     GREEN,   _______,                    _______, GREEN,   _______, _______, BAS_UGL, _______,
//            ADJ_UGL,         ADJ_UGL,         ADJ_UGL,                             ADJ_UGL,          ADJ_UGL,          ADJ_UGL,
//   RED,     CYAN,    AQUA,    YELLOW,  CYAN,    BLUE,                       ORANGE,  BLUE,    GREEN,   AZURE,   ORANGE,  AQUA,
//            ADJ_UGL,                                                                                                   ADJ_UGL,
//   RED,     CYAN,    AQUA,    _______, _______, BLUE,                       RED,     BLUE,    GREEN,   AZURE,   ORANGE,  AQUA,
//                              ADJ_UGL,          ADJ_UGL,                          ADJ_UGL,          ADJ_UGL,
//                                       _______, _______, _______,    _______, _______, _______
//   ),

  [_ADJUST] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, _______, _______,     _______,   _______,                    _______, _______,   _______, _______, _______, _______,
           ADJ_UGL,         ADJ_UGL,         ADJ_UGL,                             ADJ_UGL,          ADJ_UGL,          ADJ_UGL,
  _______,     _______,    _______,    _______,  _______,    _______,                       _______,  _______,    _______,   _______,   _______,  _______,
           ADJ_UGL,                                                                                                   ADJ_UGL,
  _______,     _______,    _______,    _______, _______, _______,                       _______,     _______,    _______,   _______,   _______,  _______,
                             ADJ_UGL,          ADJ_UGL,                          ADJ_UGL,          ADJ_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),
};

#undef _______
#define _______ KC_TRNS
#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
