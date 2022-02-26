#include QMK_KEYBOARD_H

#include "oled.h"

#ifdef OLED_FONT_ENABLE
void write_layer_state(void) {
    //char layer_name[11];

    switch (biton32(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Cole   mak"), false);
            break;
        case _FUNCT:
            oled_write_P(PSTR("Func  tion"), false);
            break;
        case _NAV_SYM:
            oled_write_P(PSTR("Nav    Sym"), false);
            break;
        case _MIRR_NUM:
            oled_write_P(PSTR("Mirr   Num"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            //snprintf(layer_name, sizeof(layer_name), "%5X", layer_state);	// l in %5lX should instead depend on sizeof(layer_state_t)?
            oled_write_ln(get_u8_str(layer_state, ' '), false);
    }
}

void write_host_led_state(void) {
    oled_write_char((IS_HOST_LED_ON(USB_LED_NUM_LOCK) ? 'N' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ? 'C' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ? 'S' : ' '), false);
}

void write_mod_state(void) {
	uint8_t mods = get_mods();
	
    oled_write_char((mods & MOD_BIT(KC_LEFT_SHIFT) ? '<' : ' '), false);
	oled_write_P(PSTR(" S "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_SHIFT) ? '>' : ' '), false);
    oled_advance_page(true);
	
    oled_write_char((mods & MOD_BIT(KC_LEFT_CTRL) ? '<' : ' '), false);
	oled_write_P(PSTR(" C "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_CTRL) ? '>' : ' '), false);
    oled_advance_page(true);
	
    oled_write_char((mods & MOD_BIT(KC_LEFT_ALT) ? '<' : ' '), false);
	oled_write_P(PSTR(" A "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_ALT) ? '>' : ' '), false);
    oled_advance_page(true);
	
    oled_write_char((mods & MOD_BIT(KC_LEFT_GUI) ? '<' : ' '), false);
	oled_write_P(PSTR(" G "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_GUI) ? '>' : ' '), false);
    oled_advance_page(true);
}
#endif  // OLED_FONT_ENABLE

#ifdef OLED_ENABLE
const char colemak_bmp[] PROGMEM = {
	// Colemak
	0b00011110,
	0b00100001,
	0b00100001,
	0b00010010,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00011000,
	0x00,
	0b00011110,
	0b00100000,
	0x00,
	0b00011000,
	0b00101100,
	0b00101100,
	0b00001000,
	0x00,
	0b00111000,
	0b00000100,
	0b00111000,
	0b00000100,
	0b00111000,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00111100,
	0x00,
	0b00111110,
	0b00011000,
	0b00100100
};

const char funct_bmp[] PROGMEM = {
	// Function
	0b00111111,
	0b00000101,
	0b00000101,
	0b00000001,
	0b00011100,
	0b00100000,
	0b00100000,
	0b00011100,
	0x00,
	0b00111100,
	0b00000100,
	0b00000100,
	0b00111000,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0x00,
	0b00011111,
	0b00100100,
	0x00,
	0b00111010,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00011000,
	0x00,
	0b00111100,
	0b00000100,
	0b00000100,
	0b00111000
};

const char nav_sym_bmp[] PROGMEM = {
	// Nav Sym
	0b00111111,
	0b00000100,
	0b00001000,
	0b00111111,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00111100,
	0x00,
	0b00001100,
	0b00010000,
	0b00100000,
	0b00010000,
	0b00001100,
	0x00,
	0x00,
	0x00,
	0b00100010,
	0b00100101,
	0b00100101,
	0b00011001,
	0x00,
	0b00000110,
	0b00111000,
	0b00000110,
	0x00,
	0b00111110,
	0b00000010,
	0b00111110,
	0b00000010,
	0b00111110
};

const char mirr_num_bmp[] PROGMEM = {
	// Mirr Num
	0b00111111,
	0b00000010,
	0b00111100,
	0b00000010,
	0b00111111,
	0x00,
	0b00111010,
	0x00,
	0b00111000,
	0b00000100,
	0b00000100,
	0x00,
	0b00111000,
	0b00000100,
	0b00000100,
	0x00,
	0x00,
	0x00,
	0b00111111,
	0b00000100,
	0b00001000,
	0b00111111,
	0x00,
	0b00111100,
	0b00100000,
	0b00111100,
	0x00,
	0b00111100,
	0b00000100,
	0b00111100,
	0b00000100,
	0b00111100
};

const char led_num_bmp[] PROGMEM = {
	// Num
	0b00111111,
	0b00000100,
	0b00001000,
	0b00111111,
	0x00,
	0b00111100,
	0b00100000,
	0b00111100,
	0x00,
	0b00111100,
	0b00000100,
	0b00111100,
	0b00000100,
	0b00111100
};

const char led_caps_bmp[] PROGMEM = {
	// Cap
	0b00111111,
	0b00100001,
	0b00110011,
	0x00,
	0b00111100,
	0b00010100,
	0b00111100,
	0x00,
	0b00111100,
	0b00010100,
	0b00011100
};

const char led_scroll_bmp[] PROGMEM = {
	// Sc
	0b00100111,
	0b00111101,
	0x00,
	0b00111100,
	0b00100100
};

const char shift_bmp[] PROGMEM = {
	// Shift
	0b01000110,
	0b01001001,
	0b00110001,
	0x00,
	0b01111110,
	0b00001000,
	0b01110000,
	0x00,
	0b01110100,
	0x00,
	0b01111100,
	0b00001010,
	0x00,
	0b00111110,
	0b01001000
};

const char ctrl_bmp[] PROGMEM = {
	// Ctrl
	0b00111100,
	0b01000010,
	0b01000010,
	0x00,
	0b00111110,
	0b01001000,
	0x00,
	0b01110000,
	0b00001000,
	0x00,
	0b00111110,
	0b01000000
};

const char alt_bmp[] PROGMEM = {
	// Alt
	0b01111110,
	0b00001001,
	0b01111110,
	0x00,
	0b00111110,
	0b01000000,
	0x00,
	0b00111110,
	0b01001000
};

const char gui_bmp[] PROGMEM = {
	// Gui
	0b01111111,
	0b01000001,
	0b01110011,
	0x00,
	0b01111110,
	0b01000000,
	0b01111110,
	0x00,
	0b01000010,
	0b01111110,
	0b01000010,
};

void clear_range(uint16_t index, uint16_t size) {
	for( uint16_t i = 0; i < size; i++) {
		oled_write_raw_byte( 0x00, index + i );
	}
}

void render_layer_state( uint16_t index ) {
	// Should check passed indices are line-aligned..?
    switch (biton32(layer_state)) {
        case _COLEMAK:
			oled_write_data_P(colemak_bmp, index, sizeof(colemak_bmp));
            break;
        case _FUNCT:
			oled_write_data_P(funct_bmp, index, sizeof(funct_bmp));
            break;
        case _NAV_SYM:
			oled_write_data_P(nav_sym_bmp, index, sizeof(nav_sym_bmp));
            break;
        case _MIRR_NUM:
			oled_write_data_P(mirr_num_bmp, index, sizeof(mirr_num_bmp));
            break;
        default:
			// Could display the layer number binary as a grid of 2x3 bits
			clear_range( index, 32 );
    }
}

void write_or_clear( bool write_not_clear, uint16_t index, const char *data, uint16_t size ) {
	if( write_not_clear ) {
		oled_write_data_P( data, index, size );
	} else {
		clear_range( index, size );
	}
}

void render_host_led_state( uint16_t index ) {
	write_or_clear( IS_HOST_LED_ON(USB_LED_NUM_LOCK), index, led_num_bmp, sizeof(led_num_bmp) );
	index += sizeof(led_num_bmp) + 1;
	write_or_clear( IS_HOST_LED_ON(USB_LED_CAPS_LOCK), index, led_caps_bmp, sizeof(led_caps_bmp) );
	index += sizeof(led_caps_bmp) + 1;
	write_or_clear( IS_HOST_LED_ON(USB_LED_SCROLL_LOCK), index, led_scroll_bmp, sizeof(led_scroll_bmp) );
}

void render_mod_state( uint16_t index ) {
	// Should check passed index has enough room left to fit all the lines..?
	
	uint8_t mods = get_mods() | get_oneshot_mods();
	write_or_clear( mods & MOD_BIT(KC_LEFT_SHIFT), index, shift_bmp, sizeof(shift_bmp) );
	write_or_clear( mods & MOD_BIT(KC_RIGHT_SHIFT), index+32-sizeof(shift_bmp), shift_bmp, sizeof(shift_bmp) );
	write_or_clear( mods & MOD_BIT(KC_LEFT_CTRL), index+32, ctrl_bmp, sizeof(ctrl_bmp) );
	write_or_clear( mods & MOD_BIT(KC_RIGHT_CTRL), index+64-sizeof(ctrl_bmp), ctrl_bmp, sizeof(ctrl_bmp) );
	write_or_clear( mods & MOD_BIT(KC_LEFT_ALT), index+64, alt_bmp, sizeof(alt_bmp) );
	write_or_clear( mods & MOD_BIT(KC_RIGHT_ALT), index+96-sizeof(alt_bmp), alt_bmp, sizeof(alt_bmp) );
	write_or_clear( mods & MOD_MASK_GUI, index+64+sizeof(alt_bmp)+1, gui_bmp, sizeof(gui_bmp) );
}
#endif  // OLED_ENABLE
