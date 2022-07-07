#include "rgb_matrix_ledmaps.h"
//#include "caracarn.h"
#include "definitions/layers.h"

extern led_config_t g_led_config;

__attribute__((weak)) void rgb_matrix_indicators_keymap(void) { return; }
__attribute__((weak)) void rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return;
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

static bool enabled = true;

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

void rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifdef RGB_MATRIX_LEDMAPS_ENABLED
    if (rgb_matrix_is_enabled() && enabled) {
        set_layer_rgb(led_min, led_max, get_highest_layer(layer_state | default_layer_state));
    }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
    rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer) {
    const ledmap *l = &(ledmaps[layer]);

    uint8_t val = rgb_matrix_get_val();
    if (layer == _BASE) {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
            HSV hsv = BAS_UGL;
            RGB rgb = hsv_to_rgb(hsv);
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
            }
        }
    } else {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
            HSV hsv = {
                .h = (*l)[i][0],
                .s = (*l)[i][1],
                .v = val,
            };

            if (hsv.h || hsv.s) {
                RGB rgb = hsv_to_rgb(hsv);
                RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
                // if (i == 0) {
                //     dprintf("Beginning LED Loop\n");
                // }
                // if (rgb.r > 0 || rgb.g > 0 || rgb.b > 0) {
                // dprintf("LED being lit: %d - (%d, %d, %d)\n", i, hsv.h, hsv.s, hsv.v);
                };
            }
        }
        // for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        //     HSV hsv = {
        //         .h = (*l)[i][0],
        //         .s = (*l)[i][1],
        //         .v = val,
        //     };

        //     if (hsv.h || hsv.s) {
        //         RGB rgb = hsv_to_rgb(hsv);
        //         RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
        //     }
        // }
}
// }

void rgb_matrix_layers_enable() {
    dprintf("ledmaps are enabled\n");
    enabled = true;
}

void rgb_matrix_layers_disable() {
    dprintf("ledmaps are disabled\n");
    enabled = false;
}

#endif  // RGB_MATRIX_LEDMAPS_ENABLED
