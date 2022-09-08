#include "caracarn.h"
#include "features/rgb_matrix_ledmaps.h"
#include "definitions/layers.h"
#ifdef SMART_CASE_ENABLE
    #include "features/smart_case.h"
#endif
#ifdef CAPS_WORD_ENABLE
    #include "features/caps_word.h"
#endif

extern led_config_t g_led_config;

bool ledmap_active;

uint8_t rgb_matrix_get_heatmap_spread(void) {
    return user_config.rgb_matrix_heatmap_spread;
}

uint8_t rgb_matrix_get_heatmap_area_limit(void) {
    return user_config.rgb_matrix_heatmap_area;
}

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }
__attribute__((weak)) void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return;
}

void rgb_matrix_set_smart_case_color() {
    if ((has_smart_case(CAMEL_CASE)) && (has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_PINK);
    } else if ((has_smart_case(KEBAB_CASE)) && (has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_GREEN);
    } else if ((has_smart_case(SNAKE_CASE)) && (has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_BLUE);
    } else if ((has_smart_case(CAMEL_CASE)) && !(has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_ORANGE);
    } else if ((has_smart_case(KEBAB_CASE)) && !(has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_CYAN);
    } else if ((has_smart_case(SNAKE_CASE)) && !(has_smart_case(WORD_CASE))) {
                rgb_matrix_set_color(6, RGB_TURQUOISE);
    } else if ((has_smart_case(WORD_CASE)) && !(has_smart_case(KEBAB_CASE)) && !(has_smart_case(SNAKE_CASE)) && !(has_smart_case(CAMEL_CASE))) {
                rgb_matrix_set_color(6, RGB_RED);
    }
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

static bool enabled = true;

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    if (rgb_matrix_is_enabled() && enabled) {
        switch (rgb_matrix_get_flags()) {
            case LED_FLAG_ALL: {
                set_layer_rgb_matrix(led_min, led_max, get_highest_layer(layer_state | default_layer_state), (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR | LED_FLAG_UNDERGLOW));
            }
            break;
            case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                set_layer_rgb_matrix(led_min, led_max, get_highest_layer(layer_state | default_layer_state), (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR));
            }
            break;
            case LED_FLAG_UNDERGLOW: {
                set_layer_rgb_matrix(led_min, led_max, get_highest_layer(layer_state | default_layer_state), (LED_FLAG_UNDERGLOW));
            }
            break;
            default: {
                set_layer_rgb_matrix(led_min, led_max, get_highest_layer(layer_state | default_layer_state), (LED_FLAG_NONE));
            }
            break;
        }
    }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
    rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

void rgb_matrix_base_underglow(void) {

}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

// void set_layer_rgb_matrix(uint8_t led_min, uint8_t led_max, int layer, int led_type) {
//     const ledmap *l = &(ledmaps[layer]);
//     uint8_t val = rgb_matrix_get_val();
//     if (!user_config.rgb_matrix_ledmap_active) {
//         // Normal RGB Matrix Effects
//             for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
//                 HSV hsv = {
//                     .h = (*l)[0][0],
//                     .s = (*l)[0][1],
//                     .v = val,
//                 };
// 			    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
//                 if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
//                     RGB rgb = hsv_to_rgb(hsv);
//                     RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
//             }
//             }
//             // if (layer != _BASE || _COLEMAK_DH || _ADJUST) {
//             //     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
//             // }
//     } else {
//         // RGB Matrix Utilizing LED Map
//             for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//                 HSV hsv = {
//                     .h = (*l)[i][0],
//                     .s = (*l)[i][1],
//                     .v = val,
//                 };
//                 if (hsv.h || hsv.s) {
//                     RGB rgb = hsv_to_rgb(hsv);
//                     if (HAS_ANY_FLAGS(g_led_config.flags[i], led_type)) {
//                         RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
//                     }
//                 }
//             }
//     }
//     // Global RGB Matrix Effects
//     #ifdef CAPS_WORD_ENABLE
//             if (isCapsWord) {
//                 rgb_matrix_set_color(6, 255, 0, 0);
//             } else {
//                 rgb_matrix_set_color(6, 0, 0, 0);
//             }
//     #endif
//     #ifdef SMART_CASE_ENABLE
//             if (has_any_smart_case()){
//                 rgb_matrix_set_color(6, RGB_RED);
//             } else if ((rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW) && (!has_any_smart_case())) {
//                 rgb_matrix_set_color(6, 0, 0, 0);
//             }
//     #endif
// }

void set_layer_rgb_matrix(uint8_t led_min, uint8_t led_max, int layer, int led_type) {
    const ledmap *l = &(ledmaps[layer]);
    uint8_t val = rgb_matrix_get_val();
        for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
            if (!user_config.rgb_matrix_ledmap_active) {
                HSV hsv = {
                    .h = (*l)[0][0],
                    .s = (*l)[0][1],
                    .v = val,
                };
			    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
                if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    RGB rgb = hsv_to_rgb(hsv);
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
            }
            } else {
                HSV hsv = {
                    .h = (*l)[i][0],
                    .s = (*l)[i][1],
                    .v = val,
            };
                if (hsv.h || hsv.s) {
                RGB rgb = hsv_to_rgb(hsv);
                    if (HAS_ANY_FLAGS(g_led_config.flags[i], led_type)) {
                        RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
                    }
                }
            }
            // RGB rgb = hsv_to_rgb(hsv);
            // if (HAS_ANY_FLAGS(g_led_config.flags[i], led_type)) {
            //     RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
            // }
        }
        if (has_any_smart_case()) {
            rgb_matrix_set_smart_case_color();
        }
        // if (user_config.rgb_matrix_heatmap_area != rgb_matrix_typing_heatmap_area_limit) {
        //     rgb_matrix_typing_heatmap_area_limit = user_config.rgb_matrix_heatmap_area;
        // }
        // if (user_config.rgb_matrix_heatmap_spread != rgb_matrix_typing_heatmap_spread) {
        //     rgb_matrix_typing_heatmap_spread = user_config.rgb_matrix_heatmap_spread;
        // }
}


void rgb_matrix_layers_enable() {
    dprintf("ledmaps are enabled\n");
    enabled = true;
}

void rgb_matrix_layers_disable() {
    dprintf("ledmaps are disabled\n");
    enabled = false;
}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
