#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "caps_word.h"
#include "smart_case.h"
//#include "os_toggle.h"
//#include "default_mod_key.h"
//#include "dynamic_macro.h"

enum {
    SEC1_5,
    SEC7_8,
    SEC11_9,
    SEC3_10,
    BRT_CUR,
    BRT_SQR,
    BRT_PAR,
    BRT_ANG,
    SDB_QUO,
    KEBAB,
    SNAKE,
    CAMEL,
    SS_FULL,
    SS_SNIP
};

#define TD_S15 TD(SEC1_5)
#define TD_S78 TD(SEC7_8)
#define TD_S119 TD(SEC11_9)
#define TD_S310 TD(SEC3_10)
#define TD_CURB TD(BRT_CUR)
#define TD_SQRB TD(BRT_SQR)
#define TD_PARB TD(BRT_PAR)
#define TD_ANGB TD(BRT_ANG)
#define TD_QUOT TD(SDB_QUO)
#define TD_KBAB TD(KEBAB)
#define TD_SNAK TD(SNAKE)
#define TD_CAML TD(CAMEL)
#define TD_SSFL TD(SS_FULL)
#define TD_SNIP TD(SS_SNIP)
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
    bool recording;
} td_tap_t;

td_state_t dance_state(qk_tap_dance_state_t *state);
