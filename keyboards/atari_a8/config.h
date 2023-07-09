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
#define OLED_IC OLED_IC_SH1106

//#define OLED_DISPLAY_WIDTH 	128  //	The width of the OLED display.
//#define OLED_DISPLAY_HEIGHT 	64 // 	The height of the OLED display.