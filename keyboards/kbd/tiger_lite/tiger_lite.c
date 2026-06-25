/* Copyright 2022 ZhaQian
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

#include QMK_KEYBOARD_H
#include "usb_util_kb.h"

#ifdef RGB_MATRIX_ENABLE

typedef union {
    uint32_t raw;
    struct {
        uint8_t pollingInterva : 8;
    };
} user_config_t;

user_config_t user_config;


bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(24, 0xFF, 0xFF, 0xFF);
    }
    return true;
}

#endif  // RGB_MATRIX_ENABLE


void eeconfig_init_user(void) {
    user_config.raw            = 0;
    user_config.pollingInterva = 4;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    usb_set_pollingInterva(user_config.pollingInterva);
}
