//#include "quantum.h"

#ifndef CONFIG_USER_H
    #define CONFIG_USER_H
#endif

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef USE_I2C
//#undef SSD1306OLED

//#define USE_SERIAL_PD2

#define FORCE_NKRO

//#define LAYER_STATE_8BIT
#define USB_POLLING_INTERVAL_MS 1

#ifdef SMART_CASE_ENABLE
    #define CUSTOM_ONESHOT_TIMEOUT 2000
#endif

//#define RGBLIGHT_SPLIT

#define SSD1306OLED

#ifdef RGB_MATRIX_ENABLE
    //#define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
    //#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    //#define RGB_MATRIX_STARTUP_HUE 231
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    // #   define RGB_MATRIX_TYPING_MEATMAP_DECREASE_DELAY_MS 50
    // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
    #   define RGB_DISABLE_TIMEOUT 60000 // number of ticks to wait until disabling effects
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_STARTUP_VAL 200
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10
    #ifdef RGB_MATRIX_TYPING_HEATMAP_SPREAD
        #undef RGB_MATRIX_TYPING_HEATMAP_SPREAD
    #endif
    #ifdef RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
        #undef RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
    #endif
    #define RGB_MATRIX_TYPING_HEATMAP_SPREAD rgb_matrix_get_heatmap_spread()
    #define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT rgb_matrix_get_area_limit()

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

#undef ENABLE_RGB_MATRIX_SOLID
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define HSV_AQUA 93, 250, 200

#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    #define BASE_UNDERGLOW HSV_AQUA
    #define NUMPAD_UNDERGLOW HSV_CYAN
    #define NAVIGATION_UNDERGLOW HSV_ORANGE
    #define MACROS_UNDERGLOW HSV_AZURE
    #define SYMBOL_UNDERGLOW HSV_YELLOW
    #define FUNCTION_UNDERGLOW HSV_RED
    #define HEX_UNDERGLOW HSV_PURPLE
    #define COLEMAK_DH_UNDERGLOW HSV_PINK
    #define ADJUST_UNDERGLOW HSV_GREEN
#endif //RGB_MATRIX_LEDMAPS_ENABLED

#endif


#ifdef OLED_ENABLE
#   define OLED_FONT_H "keyboards/crkbd/keymaps/caracarn/glcdfont.c"
#   define OLED_TIMEOUT 30000
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#endif
