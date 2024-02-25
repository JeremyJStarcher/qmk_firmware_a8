// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define HAL_USE_PWM FALSE
// #define HAL_USE_ADC FALSE

#include_next <halconf.h>

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE
