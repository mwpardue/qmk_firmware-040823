#ifndef CONFIG_USER_H
    #define CONFIG_USER_H
#endif

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef USE_I2C

#define NO_USB_STARTUP_CHECK // Disables USB Suspend check after KB startup
// #define WAIT_FOR_USB // Wait for USB connection before it starts up

#define FORCE_NKRO

#define USB_POLLING_INTERVAL_MS 1

#define USB_SUSPEND_WAKEUP_DELAY 200

// #define KEYBOARD_SHARED_EP

#undef RGB_DI_PIN
#ifdef CONVERT_TO_HELIOS
  #define RGB_DI_PIN 25U

  #define ENCODERS_PAD_A { B5 }
  #define ENCODERS_PAD_B { B4 }
  #define ENCODERS_PAD_A_RIGHT { B4 }
  #define ENCODERS_PAD_B_RIGHT { B5 }
  #define ENCODER_MAP_KEY_DELAY 10
  #define ENCODER_RESOLUTION 2
#endif

#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

#ifdef SMART_CASE_ENABLE
    #define CUSTOM_ONESHOT_TIMEOUT 2000
#endif

#define SSD1306OLED

#ifdef MOUSEKEY_ENABLE
  #define MK_KINETIC_SPEED
#endif

#ifdef RGB_MATRIX_ENABLE
    //#define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
    //#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    //#define RGB_MATRIX_DEFAULT_HUE 231
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    // #   define RGB_MATRIX_TYPING_MEATMAP_DECREASE_DELAY_MS 50
    // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
    #define RGB_DISABLE_TIMEOUT 60000 // number of ticks to wait until disabling effects
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_DEFAULT_VAL 150
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
    #define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT rgb_matrix_get_heatmap_area_limit()

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
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
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#undef ENABLE_RGB_MATRIX_SOLID
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define HSV_AQUA 93, 250, 200

#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    #define BASE_UNDERGLOW HSV_CYAN
    #define NUMPAD_UNDERGLOW HSV_ORANGE
    #define NAVIGATION_UNDERGLOW HSV_BLUE
    #define MACROS_UNDERGLOW HSV_AQUA
    #define SYMBOL_UNDERGLOW HSV_YELLOW
    #define FUNCTION_UNDERGLOW HSV_RED
    #define HEX_UNDERGLOW HSV_PURPLE
    #define COLEMAK_DH_UNDERGLOW HSV_PINK
    #define MEDIA_UNDERGLOW HSV_PINK
    #define ADJUST_UNDERGLOW HSV_GREEN
#endif //RGB_MATRIX_LEDMAPS_ENABLED

#endif


#ifdef OLED_ENABLE
#   define OLED_FONT_H "keyboards/crkbd/keymaps/caracarn/glcdfont.c"
#   define OLED_TIMEOUT 60000
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#endif
