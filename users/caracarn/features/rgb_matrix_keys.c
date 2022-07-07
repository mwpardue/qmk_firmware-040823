#include QMK_KEYBOARD_H

#include "rgb_matrix_keys.h"
#include "caracarn.h"
#include "rgb_matrix.h"
#include "config.h"

static void heatmap_spread_report(void) {
    const char *heatmap_spread_str = get_u16_str(RGB_MATRIX_TYPING_HEATMAP_SPREAD, ' ');
    // Skip padding spaces
    while (*heatmap_spread_str == ' ') {
        heatmap_spread_str++;
    }
    send_string(heatmap_spread_str);
}

static void heatmap_area_report(void) {
    const char *heatmap_area_str = get_u16_str(RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT, ' ');
    // Skip padding spaces
    while (*heatmap_area_str == ' ') {
        heatmap_area_str++;
    }
    send_string(heatmap_area_str);
}

process_record_result_t process_rgb_matrix_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
              return PROCESS_RECORD_RETURN_FALSE;
            }
        case RGB_SPP:
            if (record->event.pressed) {
                RGB_MATRIX_TYPING_HEATMAP_SPREAD + 1;
                heatmap_spread_report();
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
        case RGB_SPM:
            if (record->event.pressed) {
                RGB_MATRIX_TYPING_HEATMAP_SPREAD - 1;
                heatmap_spread_report();
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
        case RGB_ALP:
            if (record->event.pressed) {
                RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT + 1;
                heatmap_area_report();
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
        case RGB_ALM:
            if (record->event.pressed) {
                RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT - 1;
                heatmap_area_report();
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
  }
    return PROCESS_RECORD_CONTINUE; // Process all other keycodes normally
}
