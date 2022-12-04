#pragma once

#include "layers.h"

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

#ifdef MACRO_ENABLE
    DDS,
    TIPS,
    FOPEN,
    VIMWQ,
    MVIMQ,
#endif

#ifdef SECRETS_ENABLE
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,
    KC_SECRET_6,
    KC_SECRET_7,
    KC_SECRET_8,
    KC_SECRET_9,
    KC_SECRET_10,
    KC_SECRET_11,
    KC_SECRET_12,
#endif

#ifdef OS_TOGGLE_ENABLE
    TG_MAC, TG_WIN, TG_LIN,
#endif

#ifdef CAPITALIZE_KEY_ENABLE
    SP_CAP, CAP_KEY, SS_CAPS,
#endif

#ifdef DEFAULT_MOD_KEY_ENABLE
    SP_MOD, DEF_MOD,
#endif

#ifdef SMART_THUMB_KEYS_ENABLE
    CAP_KEY, SP_CAP, SP_MOD, DEF_MOD, XCASE,
#endif

#ifdef SMART_CASE_ENABLE
    MC_CAPS, MC_WORD, MC_CAML, MC_SNAK, MC_KBAB,
#endif

#ifdef SHORTCUTS_ENABLE
    SS_MODP, SS_MODM, COLEMAK, QWERTY, TG_KBAB, TG_CAML, TG_SNAK, SM_PARN,
    SM_BRAC, SM_ANGB, SM_CURB, SFT_TTP, SFT_TTM, BSP_WRD, BSP_LIN, T_CLOSE, S_ARRNG,
    BROWSER_BACK, BROWSER_FORWARD, TAB_BACK, TAB_FORWARD, TMX_LDS,
#endif

#ifdef SELECT_WORD_ENABLE
    MC_SELW,
#endif

#ifdef WINDOW_SWAPPER_ENABLE
    MC_SWLE, MC_SWRI, MC_SWAP,
#endif

#ifdef COMBO_ENABLE
    SM_LOGN,
#endif

#ifdef LAYER_LOCK_ENABLE
    LLOCK,
#endif

#ifdef CUSTOM_LEADER_ENABLE
  LEADER,
#endif

#ifdef RGB_MATRIX_ENABLED
    RGB_SPP, RGB_SPM, RGB_ALP, RGB_ALM, RGB_CHG, RGB_MDT,
#endif

    CUSTOM_KEYCODE_END
};

// Mod-taps

// One-shot mods

#define OSMLSFT OSM(MOD_LSFT)
#define OSMLCTL OSM(MOD_LCTL)
#define OSMLALT OSM(MOD_LALT)
#define OSMRALT OSM(MOD_RALT)
#define OSMLGUI OSM(MOD_LGUI)
#define OSMRCTL OSM(MOD_RCTL)

// Left-hand home row mods
#define SFT_D LSFT_T(KC_D)
#define ALT_D LALT_T(KC_D)
#define ALT_S LALT_T(KC_S)
#define CTL_F LCTL_T(KC_F)
#define CTL_A LCTL_T(KC_A)
#define CTL_CA LCTL_T(KC_A)
#define ALT_CR LALT_T(KC_R)
#define SFT_CS LSFT_T(KC_S)
#define GUI_CT LGUI_T(KC_T)
#define CTL_S LCTL_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define GUI_F LGUI_T(KC_F)
#define ALT_BSL LALT_T(KC_BSLS)
#define GUI_PIP LGUI_T(KC_PIPE)
// #define ALT_BRC LALT_T(SM_BRAC)
#define CTL_AT LCTL_T(KC_AT)
#define SFT_MNS LSFT_T(KC_MINS)

// // Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define SFT_K RSFT_T(KC_K)
#define CTL_QUO RCTL_T(KC_QUOT)
#define CTL_CO RCTL_T(KC_O)
#define ALT_CI RALT_T(KC_I)
#define SFT_CE RSFT_T(KC_E)
#define GUI_CN RGUI_T(KC_N)
#define ALT_L RALT_T(KC_L)
#define CTL_K RCTL_T(KC_K)
#define GUI_J RGUI_T(KC_J)
#define GUI_4 RGUI_T(KC_4)
#define ALT_5 RALT_T(KC_5)
#define SFT_5 RSFT_T(KC_5)
#define ALT_6 RALT_T(KC_6)
#define ALT_4 RALT_T(KC_4)
#define ALT_1 RALT_T(KC_1)
#define CTL_PLS RCTL_T(KC_PLUS)
#define CTL_SCL RCTL_T(KC_SCLN)

// Layer-taps

#define MOD_KEY LGUI_T(SP_MOD)
#define MOD_CTL LCTL_T(SP_MOD)
#define SPC_SYM LT(_SYMBOL, KC_SPC)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define BSP_MSE LT(_MOUSE, KC_BSPC)
#define ESC_MAC LT(_MACROS, KC_ESC)
#define SPC_MAC LT(_MACROS, KC_SPACE)
#define ESC_NUM LT(_NUMPAD, KC_ESC)
#define ENT_FUN LT(_FUNCTION, KC_ENT)
#define ENT_MED LT(_MEDIA, KC_ENT)
#define ENT_SYM LT(_SYMBOL, KC_ENT)
#define ENT_NUM LT(_NUMPAD, KC_ENT)
#define KC0_MEH MEH_T(KC_0)
#define SYM_LL LT(_SYMBOL, LLOCK)
#define XCS_SFT LSFT_T(XCASE)
#define CAP_FUN LT(_FUNCTION, SP_CAP)
#define CAP_MSE LT(_MOUSE, SP_CAP)
#define TAB_SYM LT(_SYMBOL, KC_TAB)
#define ESC_FUN LT(_FUNCTION, KC_ESC)
#define FUN_Z LT(_FUNCTION, KC_Z)
#define SPC_MEH MEH_T(KC_SPACE)
#define DEL_MEH MEH_T(KC_DEL)
#define BSP_MEH MEH_T(KC_BACKSPACE)
#define ENT_HYP HYPR_T(KC_ENT)
#define MC_SWAP LGUI(KC_GRV)

// Layer transitions

#define MOFUN MO(_FUNCTION)
#define TOBAS TO(_BASE)
#define TONUM TO(_NUMPAD)
#define TOSYM TO(_SYMBOL)
#define TOMAC TO(_MACROS)
#define TOHEX TO(_HEX)
#define TOFUN TO(_FUNCTION)
#define TOADJ TO(_ADJUST)
#define TOCMK TO(_COLEMAK_DH)
// #define TONAV TO(_NAVIGATION)
#define OSL_MAC OSL(_MACROS)

// Custom Shortcuts

#define SS3 LGUI(LSFT(KC_3))
#define SS4 LGUI(LSFT(KC_4))
#define LCTLC LCTL(KC_C)
#define SELALL LGUI(KC_A)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define SAVE LGUI(KC_S)
#define FIND LGUI(KC_F)
// #define PRVTAB LCTL(LSFT(KC_TAB))
// #define NXTTAB LCTL(KC_TAB)
// #define BRBACK LGUI(KC_LEFT)
// #define BRFWD LGUI(KC_RIGHT)
#define ZOOMIN LGUI(KC_PPLS)
#define ZOOMOUT LGUI(KC_PMNS)
#define ESC_CTL LCTL_T(KC_ESC)
#define GUI_ENT LGUI_T(KC_ENT)
#define HOME LGUI(KC_UP)
#define END LGUI(KC_DOWN)
#define WORD_LE LALT(KC_LEFT)
#define WORD_RI LALT(KC_RIGHT)
#define TMUX_LD LCTL(KC_SPACE)
#define BEG_LIN LGUI(KC_LEFT)
#define END_LIN LGUI(KC_RIGHT)
#define SPCSFT LSFT_T(KC_SPC)
#define DOTSFT LSFT_T(KC_DOT)
#define MACSLEP LSFT(LCTL(KC_POWER))
#define GUI_VD LGUI_T(KC_VOLD)
#define SFT_MUT LSFT_T(KC_MUTE)
#define ALT_VU ALT_T(KC_VOLU)
#define ALT_PRV LALT_T(KC_MPRV)
#define SFT_BSP LSFT_T(KC_BSPC)
#define CTL_BRB LCTL_T(BROWSER_BACK)
#define GUI_TFW LGUI_T(TAB_FORWARD)
#define ALT_BRF LALT_T(BROWSER_FORWARD)
#define SFT_TBK LSFT_T(TAB_BACK)

uint16_t extract_base_tapping_keycode(uint16_t keycode);

//#ifdef SMART_CASE_ENABLE
    bool is_key_on_tap(uint16_t keycode);
//#endif
