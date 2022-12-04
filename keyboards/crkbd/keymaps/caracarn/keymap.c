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
  OSMLCTL, CTL_A,  ALT_S,   SFT_D,   GUI_F,   KC_G,                         KC_H,    GUI_J,   SFT_K,   ALT_L,   CTL_QUO, OSMRALT,
  LEADER, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
                                     DEL_MEH, ESC_NUM, TAB_SYM,    BSP_MSE, SPC_MAC, ENT_HYP
),

[_COLEMAK_DH] = LAYOUT_split_3x6_3(
  _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    TD_QUOT, _______,
  _______, CTL_CA, ALT_CR,  SFT_CS,  GUI_CT,  KC_G,                         KC_M,    GUI_CN,  SFT_CE,  ALT_CI,  CTL_CO,  _______,
  _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                     DEL_MEH, ESC_NUM, TAB_SYM,    BSP_MSE, SPC_MAC, ENT_HYP
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, _______, MC_SWLE, MC_SWAP, MC_SWRI, TD_SSFL,                      _______, _______, _______, _______, _______, _______,
  _______, CTL_BRB, ALT_BRF, SFT_TBK, GUI_TFW, TD_SNIP,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, LLOCK,   _______, LEADER,  _______, KC_ENT,                       _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,    KC_BSPC, KC_SPC,  _______
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, KC_GRV,  KC_TILD, KC_UNDS, KC_UNDS, TIPS,                        KC_MINS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, CTL_AT,  ALT_BSL, SFT_MNS, GUI_PIP, _______,                     KC_COLN, GUI_4,   SFT_5,   ALT_6,   CTL_SCL, _______,
  _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,                     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                      _______, _______, _______,   XCS_SFT, KC_0,    ENT_NUM
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, KC_MINS,                      KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC, _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN,                      KC_COLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, TOBAS,   KC_UNDS, _______, KC_DOT,  _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, _______, SPCSFT,     KC_BSPC, KC_0,    LLOCK
),

[_MOUSE] = LAYOUT_split_3x6_3(
  _______, _______, MC_SELW, HOME,    _______, TOBAS,  		                 TD_SSFL, TD_SNIP,  ZOOMIN,  ZOOMOUT, OSL_MAC, _______,
  _______, BEG_LIN, WORD_LE, END,     WORD_RI, END_LIN, 		             _______, GUI_VD,   SFT_MUT, ALT_VU,  KC_RCTL, _______,
  _______, _______, _______, TD_COPY, TD_PAST, _______, 		             _______, KC_MPRV,  KC_MPLY, KC_MNXT, LLOCK,   _______,
							          BSP_LIN, BSP_WRD, CAP_FUN,    _______, _______, _______
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, _______, _______, _______, _______, _______,                      _______, _______, ZOOMIN,  ZOOMOUT, _______, _______,
  _______, S_ARRNG, TMX_LDS, _______, _______, _______,                      _______, _______, _______, TMUX_LD, _______, _______,
  _______, _______, T_CLOSE, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,    _______, _______, _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  _______, TOADJ,   _______, _______, _______, _______,                       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,\
  _______, _______, _______, TOADJ,   _______, _______,                       _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,\
  _______, _______, TOHEX,   _______, _______, _______,                       _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_MEDIA] = LAYOUT_split_3x6_3( \
  _______, _______, _______, _______, _______,  _______,                       _______, _______, _______, _______, _______, _______,  \
  RGB_ALP, RGB_SPP, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                        RGB_CHG, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,\
  RGB_ALM, RGB_SPM, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                        RGB_MOD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,\
                                      _______,  _______,  _______,   _______,  _______, _______ \
),

[_ADJUST] = LAYOUT_split_3x6_3( \
  _______, TOBAS,   TOCMK,   EEP_RST, QK_RBT,  _______,                      _______, RGB_MDT, _______, _______, TOBAS,   _______,  \
  RGB_ALP, RGB_ALP, RGB_SPP, DEBUG,   DT_PRNT, DT_UP,                        RGB_CHG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,\
  RGB_ALM, RGB_ALM, RGB_SPM, SFT_TTM, SFT_TTP, DT_DOWN,                      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,\
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
  _______, _______, ORANGE, _______, ORANGE,  AZURE,                        _______, _______, _______, _______, _______, _______,
           NUM_UGL,         NUM_UGL,         NUM_UGL,                             NUM_UGL,          NUM_UGL,          NUM_UGL,
  _______, ORANGE,  BLUE,   BLUE,    ORANGE,  AZURE,                        YELLOW,  YELLOW,  YELLOW,  YELLOW,  _______, _______,
           NUM_UGL,                                                                                                   NUM_UGL,
  _______, PURPLE,  ORANGE, YELLOW,  ORANGE,  GREEN,                        _______, _______, _______, _______, _______, _______,
                            NUM_UGL,         NUM_UGL,                             NUM_UGL,          NUM_UGL,
                                      _______, _______, _______,    AQUA,    CYAN,    _______
  ),

  [_MOUSE] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, _______, AZURE,   BLUE,    _______, BAS_UGL,                  AZURE,   AZURE,   MAGENT,  MAGENT,  MAC_UGL, _______,
           MSE_UGL,         MSE_UGL,         MSE_UGL,                              MSE_UGL,          MSE_UGL,          MSE_UGL,
  _______, BLUE,    BLUE,    BLUE,    BLUE,    BLUE,                     _______, ORANGE,  ORANGE,  ORANGE,  CYAN,    _______,
           MSE_UGL,                                                                                                    MSE_UGL,
  _______, _______, _______, AZURE,   AZURE,   _______,                  _______, AZURE,   AZURE,   AZURE,   PURPLE,  _______,
                            MSE_UGL,         MSE_UGL,                              MSE_UGL,          MSE_UGL,
                                      CYAN,    BLUE,    FUN_UGL,    _______, _______, _______
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
  _______, AQUA,    YELLOW,  BLUE,    GREEN,   ORANGE,                       YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           SYM_UGL,         SYM_UGL,         SYM_UGL,                             SYM_UGL,          SYM_UGL,          SYM_UGL,
  _______, ORANGE,  GOLD,    MAGENT,  PURPLE,  _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
           SYM_UGL,                                                                                                    SYM_UGL,
  _______, GREEN,   GREEN,   CYAN,    CYAN,    _______,                      YELLOW,  CYAN,    CYAN,    CYAN,    YELLOW,  _______,
                            SYM_UGL,          SYM_UGL,                            SYM_UGL,          SYM_UGL,
                                      _______, _______, _______,    AQUA,   CYAN,    NUM_UGL
  ),

  [_MACROS] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, GREEN,   ORANGE,  BLUE,    _______, _______,                      _______, _______, GREEN,   GREEN,   _______, _______,
           MAC_UGL,         MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,          MAC_UGL,
  _______, PURPLE,  CYAN,    YELLOW,  _______, _______,                      _______, _______, _______, PURPLE,  _______, _______,
           MAC_UGL,                                                                                                   MAC_UGL,
  _______, AZURE,   PINK,    PINK,    _______, _______,                      _______, _______, _______, _______, _______, _______,
                            MAC_UGL,         MAC_UGL,                             MAC_UGL,          MAC_UGL,
                                      _______, _______, _______,    _______, _______, _______
  ),

  [_FUNCTION] = RGB_MATRIX_LAYOUT_LEDMAP(
  _______, ADJ_UGL, _______, _______, _______, _______,                         _______, GOLD,    GOLD,    GOLD,    GOLD,    _______,
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
