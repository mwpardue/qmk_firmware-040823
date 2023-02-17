/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "crkbd.h"
#include "eeprom_driver.h"
#include <stdbool.h>
#include <print.h>
// #include "flash/flash_spi.h"
// #include "flash/flash_spi.c"
#include "ws2812.h"


void keyboard_post_init_kb(void) {
    #ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
	    setPinOutput(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
		writePinHigh(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
        keyboard_post_init_user();
	#endif
}

void eeconfig_init_kb(void) {
    // set default config
    eeconfig_init_user();
}

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
	// Left
	{{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
	{{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
	{{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
	{{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
	// Right
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
	{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
	{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
	{{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}}
};
#endif


void board_init(void) {
    // B9 is configured as I2C1_SDA in the board file; that function must be
    // disabled before using B9 as I2C1_SDA
  #ifdef CONVERT_TO_BONSAI_C4
    setPinInputHigh(F4);
  #else
    setPinInputHigh(B9);
  #endif

    // setPinOutput(B0);
    // writePinHigh(B0);
}
