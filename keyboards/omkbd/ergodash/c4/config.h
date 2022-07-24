/* Copyright 2022 customMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

// For boards using Bonsai C4 as a reference design, the VBUS sense pin A9
// can be used for other purposes instead (e.g. the switch matrix). If A9
// is not used for VBUS sensing, uncomment the line below. Most keyboards
// using Bonsai C4 itself should leave the line below commented out.
//
// #define BOARD_OTG_NOVBUSSENS 1
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0100
#define MANUFACTURER    Omkbd
#define PRODUCT         ErgoDash

// FRAM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A0
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 4 // 48MHz / 4 = 12MHz; max supported by MB85R64 is 20MHz
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64 // does not matter for FRAM, just sets the RAM buffer size in STM32F chip
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191


// External flash configuration
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B12
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 1  // 48MHz; max supported by W25Q128JV is 133MHz
#define EXTERNAL_FLASH_BYTE_COUNT (16 * 1024 * 1024)  //128Mbit or 16MByte
#define EXTERNAL_FLASH_PAGE_SIZE 256
#define EXTERNAL_FLASH_SPI_TIMEOUT 200000 //datasheet max is 200 seconds for flash chip erase

// SPI Configuration (needed for FRAM and FLASH)
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN B5
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN B4
#define SPI_MISO_PAL_MODE 5

// I2C Configuration (optional example, can use for OLED, etc.)
// not used by CustomMK
// #define I2C_DRIVER I2CD1
// #define I2C_SCL_PIN B6
// #define I2C_SDA_PIN B7
// #define I2C_SCL_PAL_MODE 4
// #define I2C_SDA_PAL_MODE 4

// #define I2C1_CLOCK_SPEED 100000
// #define I2C1_DUTY_CYCLE STD_DUTY_CYCLE
/*
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
*/


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { A4, A3, B10, A8, B0 }
#define MATRIX_COL_PINS { A7, A6, A5, A1, B13, B14, B15 }
// #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

#define DIODE_DIRECTION COL2ROW



// #define OLED_UPDATE_INTERVAL 66

/* example code for PWM backlight */
  #define BACKLIGHT_PIN B1 // B1 < CustomMK
  #define BACKLIGHT_LIMIT_VAL 255
  #define BACKLIGHT_LEVELS 17
  #define BACKLIGHT_PWM_DRIVER PWMD3
  #define BACKLIGHT_PWM_CHANNEL 4
  #define BACKLIGHT_PAL_MODE 2

/* example code for WS2812-style underglow */
#define RGB_DI_PIN  A10 // D3 <- Original | A10 < CustomMK
#define RGBLED_NUM 24
#define WS2812_PWM_PAL_MODE 1

// #define WS2812_PWM_DRIVER PWMD4
// #define WS2812_PWM_CHANNEL 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM3
// #define WS2812_DMA_CHANNEL 3

#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6




#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 12, 12 }    // Number of LEDs

// The LEDs on the slave half go in reverse order
#define RGBLIGHT_LED_MAP { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, \
                          23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12}

/* example code for encoder */
// #define ENCODERS_PAD_A { A4 }
// #define ENCODERS_PAD_B { B9 }
// #define ENCODER_RESOLUTION 2



//#undef NO_DEBUG
//#define DEBUG


#define SOFT_SERIAL_PIN B6
#define SELECT_SOFT_SERIAL_SPEED 1

// from CustomMK
/* communication between sides */
#define USE_SERIAL
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#define SERIAL_USART_TIMEOUT 20

#define AUDIO_PIN B8
