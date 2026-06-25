/* Copyright 2023 OctopusZ
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

// Required for AT32 DMA driver (used by WS2812 PWM)
#define AT32_DMA_REQUIRED

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SAT_STEP 26
#    define RGB_MATRIX_SPD_STEP 51
#    define RGB_MATRIX_VAL_STEP 26

#    define WS2812_PWM_DRIVER PWMD1
#    define WS2812_PWM_CHANNEL 3
#    define WS2812_PWM_PAL_MODE 1
#    define WS2812_DMA_STREAM AT32_DMA1_STREAM1
#    define WS2812_DMAMUX_ID AT32_DMAMUX_TMR1_OVERFLOW
#    define WS2812_PWM_TARGET_PERIOD 800000

#    define RGB_MATRIX_LED_COUNT 87
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// HS USB (OTG2) — board default already enables OTG2+HS
#define USB_DRIVER USBD2
#define USB_POLLING_INTERVAL_MS 4

#define WEAR_LEVELING_LOGICAL_SIZE 8192
#define WEAR_LEVELING_BACKING_SIZE 16384

#ifdef VIA_ENABLE
#    define DYNAMIC_KEYMAP_LAYER_COUNT 10
#endif

#define EECONFIG_MAGIC_NUMBER (uint16_t)0x0009
#define USB_SUSPEND_WAKEUP_DELAY 500
