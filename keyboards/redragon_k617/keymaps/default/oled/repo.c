#include QMK_KEYBOARD_H

static bool left_pressed = false;
static bool right_pressed = false;

// 'left_close', 35x30px
static const char left_close [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x18, 0x04, 0x02, 0x01, 0x01, 0x01, 0x01, 0x81, 
	0x81, 0x03, 0x07, 0x1f, 0xff, 0xff, 0x1f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x81, 0x81, 0x02, 
	0x06, 0x00, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0xb8, 0xb0, 0xb0, 
	0xb0, 0xb0, 0xb3, 0xb3, 0xbb, 0xbc, 0xbe, 0xbf, 0xbf, 0xbf, 0xbc, 0xb8, 0xb8, 0xb0, 0xb0, 0xb0, 
	0xb3, 0xbb, 0xbb, 0xbc, 0xbe, 0xbf, 0xbf, 0xbf, 0x38, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f
};
// 'left_open', 35x30px
static const char left_open [] PROGMEM = {
	0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x70, 0x78, 0x78, 0x7c, 0x7c, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
	0x1f, 0x0f, 0x07, 0x02, 0x02, 0x02, 0x02, 0x80, 0x84, 0x08, 0x18, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0xf8, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x70, 0x70, 0x01, 
	0xe7, 0xff, 0xff, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x63, 0x33, 0x33, 0x3c, 0x3f, 0x1f, 
	0x1f, 0x1f, 0x0e, 0x08, 0x00, 0x00, 0x07, 0x3f, 0xbf, 0xbf, 0x9e, 0x9e, 0x9c, 0x8c, 0x8c, 0x8e, 
	0x86, 0x86, 0x87, 0x83, 0x83, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f
};
// 'right_close', 35x30px
static const char right_close [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0x00, 0x06, 0x02, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01, 
	0x03, 0x07, 0x1f, 0xff, 0xff, 0x1f, 0x07, 0x03, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 
	0x18, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x38, 0xbf, 0xbf, 0xbf, 0xbe, 0xbc, 0xbb, 0xbb, 0xb3, 0xb0, 
	0xb0, 0xb0, 0xb8, 0xb8, 0xbc, 0xbf, 0xbf, 0xbf, 0xbe, 0xbc, 0xbb, 0xb3, 0xb3, 0xb0, 0xb0, 0xb0, 
	0xb0, 0xb8, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x00
};
// 'right_open', 35x30px
static const char right_open [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x18, 0x08, 0x84, 0x80, 0x02, 0x02, 0x02, 0x02, 
	0x07, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x7c, 0x7c, 0x78, 0x78, 0x70, 0x60, 0xc0, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0e, 0x1f, 0x1f, 0x1f, 0x3f, 0x3c, 0x33, 0x33, 0x63, 0x60, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf8, 0xff, 0xff, 0xe7, 0x01, 0x70, 0x70, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x80, 0xf8, 0xc0, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x83, 0x83, 0x87, 0x86, 0x86, 0x8e, 
	0x8c, 0x8c, 0x9c, 0x9e, 0x9e, 0xbf, 0xbf, 0x3f, 0x07, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x00
};

// Отображение персонажей
void render_character(void) {
    // Левый персонаж
    for (uint8_t i = 0; i < 4; i++) {  // 4 строки по 8 пикселей = 32 высота
        oled_set_cursor(0, i);  // слева
        oled_write_raw_P((left_pressed ? left_open : left_close) + i * 35, 35);
    }

    // Правый персонаж
    for (uint8_t i = 0; i < 4; i++) {
        oled_set_cursor(14, i);  // правее
        oled_write_raw_P((right_pressed ? right_open : right_close) + i * 35, 35);
    }
}

// Обработчик нажатий клавиш
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_G:  // Левая сторона клавиатуры
            left_pressed = record->event.pressed;
            break;
        case KC_H ... KC_L:  // Правая сторона клавиатуры
            right_pressed = record->event.pressed;
            break;
    }
    return true;
}