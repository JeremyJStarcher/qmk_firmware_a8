// Copyright 2022 Jeremy J Starcher (@jeremy.starcher)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//#define OLED_DISPLAY_128X64
// #define OLED_IC OLED_IC_SH1106

//#define OLED_DISPLAY_WIDTH 	128  //	The width of the OLED display.
//#define OLED_DISPLAY_HEIGHT 	64 // 	The height of the OLED display.

#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_BUTTON_COUNT 1

// An array of four GPIO pins connected to the display's D4-D7 pins
// #define HD44780_DATA_PINS 	{ F1, F3, F2, F6 }

// (Required) The GPIO connected to the display's RS pin
// #define HD44780_RS_PIN 	B1

// (Required) The GPIO connected to the display's RW pin
// #define HD44780_RW_PIN 	B0

// (Required) The GPIO connected to the display's E pin
// #define HD44780_E_PIN 	B2

// The number of visible characters on a single line of the display
// #define HD44780_DISPLAY_COLS 	16

// The number of visible lines on the display
// #define HD44780_DISPLAY_LINES 	2

// 	If defined, input characters will wrap to the next line
// #define HD44780_WRAP_LINES

// #define MATRIX_UNSELECT_DRIVE_HIGH

// https://docs.qmk.fm/#/i2c_driver?id=arm-configuration

// settings for the oled keyboard demo with Adafruit 0.91" OLED display on the Stemma QT port
#define OLED_DISPLAY_128X32
#define I2C_DRIVER I2CD1

// THIS DIFFERS FROM THE BOARD LAYOUT, MANUAL WIRING MAY NEED DONE
#define I2C0_SDA_PIN GP16 // DECLARED AS 9
#define I2C0_SCL_PIN GP9  // DECLARED AS 10

// #define I2C1_SDA_PIN GP16  // DECLARED AS 9
// #define I2C1_SCL_PIN GP9  // DECLARED AS 10

// I2C1 - SDA 2/6/10/14/18/26
// I2C2 - SCL 3/7/11/15/19/27

#define I2C1_SDA_PIN GP14
#define I2C1_SCL_PIN GP15

#define I2C1_CLOCK_SPEED 400000
