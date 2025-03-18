// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROW_PINS { GP10, GP11, GP12, GP13 }
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP2, GP3, GP4 }
#define DIODE_DIRECTION ROW2COL

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define DEBUG_MATRIX_SCAN_RATE
#define TAPPING_TERM 100