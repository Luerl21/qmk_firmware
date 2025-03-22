#pragma once

#ifdef RGBLIGHT_ENABLE
    #define NOP_FUDGE 0.4
    #define WS2812_DI_PIN GP8
    #define RGBLIGHT_LED_COUNT 31
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_ALTERNATING
#endif

#undef OLED_FONT_H
#define OLED_FONT_H	"./keymaps/default/font.c"

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define TAPPING_TERM 100

#ifdef OLED_ENABLE
    #define I2C1_SDA_PIN        GP6
    #define I2C1_SCL_PIN        GP7
    #define I2C_DRIVER I2CD1
    #define OLED_DISPLAY_128x32  
#endif