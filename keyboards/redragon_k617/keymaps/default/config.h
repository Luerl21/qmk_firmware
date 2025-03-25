#undef OLED_FONT_H
#define OLED_FONT_H	"./keymaps/default/font.c"

#define TAPPING_TERM 100

#ifdef OLED_ENABLE
    #define I2C1_SDA_PIN        GP6
    #define I2C1_SCL_PIN        GP7
    #define I2C_DRIVER I2CD1
    #define OLED_DISPLAY_128x32  
#endif