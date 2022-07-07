#pragma once

#include "quantum.h"

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define XXX \
    { 0, 0, 0 }

// clang-format off
#define RGB_MATRIX_LAYOUT_LEDMAP( \
  L30, L25, L20, L15, L04, L03,           R03, R04, R15, R20, R25, R30, \
       UL2,      UL1,      UL0,           UR0,      UR1,      UR2, \
  L31, L24, L21, L14, L05, L02,           R02, R05, R14, R21, R24, R31, \
       UL3,                                                   UR3, \
  L32, L23, L22, L13, L10, L01,           R01, R10, R13, R22, R23, R32, \
                 UL4,      UL5,           UR5,      UR4, \
                      L12, L11, L00, R00, R11, R12 \
  ) \
  { \
    UL5, UL4, UL3, UL2, UL1, UL0, \
    L00, L01, L02, L03, L04, L05, \
    L10, L11, L12, L13, L14, L15, \
    L20, L21, L22, L23, L24, L25, \
    L30, L31, L32, \
    UR5, UR4, UR3, UR2, UR1, UR0, \
    R00, R01, R02, R03, R04, R05, \
    R10, R11, R12, R13, R14, R15, \
    R20, R21, R22, R23, R24, R25, \
    R30, R31, R32 \
  }
// clang-format on
//extern uint8_t ledmap[DRIVER_LED_TOTAL][3];
typedef uint8_t ledmap[DRIVER_LED_TOTAL][3];
extern const ledmap ledmaps[];

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer);

void rgb_matrix_layers_enable(void);
void rgb_matrix_layers_disable(void);

// Just a handy defines to make our ledmaps look better
#    define RED \
        { HSV_RED }
#    define CORAL \
        { HSV_CORAL }
#    define ORANGE \
        { HSV_ORANGE }
#    define GOLDEN \
        { HSV_GOLDENROD }
#    define GOLD \
        { HSV_GOLD }
#    define YELLOW \
        { HSV_YELLOW }
#    define CHART \
        { HSV_CHARTREUSE }
#    define GREEN \
        { HSV_GREEN }
#    define SPRING \
        { HSV_SPRINGGREEN }
#    define TURQ \
        { HSV_TURQUOISE }
#    define TEAL \
        { HSV_TEAL }
#    define CYAN \
        { HSV_CYAN }
#    define AZURE \
        { HSV_AZURE }
#    define BLUE \
        { HSV_BLUE }
#    define PURPLE \
        { HSV_PURPLE }
#    define MAGENT \
        { HSV_MAGENTA }
#    define PINK \
        { HSV_PINK }
#    define BLACK \
        { HSV_BLACK }
#    define AQUA \
        { HSV_AQUA }
#    define BAS_UGL \
        { BASE_UNDERGLOW }
#    define NUM_UGL \
        { NUMPAD_UNDERGLOW }
#    define NAV_UGL \
        { NAVIGATION_UNDERGLOW }
#    define HEX_UGL \
        { HEX_UNDERGLOW }
#    define MAC_UGL \
        { MACROS_UNDERGLOW }
#    define FUN_UGL \
        { FUNCTION_UNDERGLOW }
#    define SYM_UGL \
        { SYMBOL_UNDERGLOW }

#endif //RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_keymap(void);
void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
