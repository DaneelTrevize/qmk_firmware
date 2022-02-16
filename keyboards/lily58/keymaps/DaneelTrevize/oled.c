#include QMK_KEYBOARD_H

#include "oled.h"

#ifdef OLED_FONT_ENABLE
void render_layer_state(void) {
    //char layer_name[11];

    switch (biton32(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Cole   mak"), false);
            break;
        case _FN_NAV_KEYS:
            oled_write_P(PSTR("Func   Nav"), false);
            break;
        case _NUMS_MIRROR:
            oled_write_P(PSTR("Num    Pad"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            //snprintf(layer_name, sizeof(layer_name), "%5X", layer_state);	// l in %5lX should instead depend on sizeof(layer_state_t)?
            oled_write_ln(get_u8_str(layer_state, ' '), false);
    }
}

void render_host_led_state(void) {
    oled_write_char((IS_HOST_LED_ON(USB_LED_NUM_LOCK) ? 'N' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ? 'C' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ? 'S' : ' '), false);
}

void render_mod_state(void) {
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

const char colemak[] PROGMEM = {
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
	0b00100100,
};

const char fn_nav[] PROGMEM = {
	// Func Nav
	0b00111111,
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
	0x00,
	0x00,
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
	0b00011100,
	0b00100000,
	0b00011100,
};

const char num_pad[] PROGMEM = {
	// Num Pad
	0b00111111,
	0b00000100,
	0b00001000,
	0b00111111,
	0x00,
	0b00011100,
	0b00100000,
	0b00100000,
	0b00011100,
	0x00,
	0b00111000,
	0b00000100,
	0b00111000,
	0b00000100,
	0b00111000,
	0x00,
	0x00,
	0x00,
	0b00111111,
	0b00001001,
	0b00001001,
	0b00000110,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00111100,
	0x00,
	0b00011000,
	0b00100100,
	0b00100100,
	0b00111111,
};

const char led_num_on[] PROGMEM = {
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

const char led_caps_on[] PROGMEM = {
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

const char led_scroll_on[] PROGMEM = {
	// Sc
	0b00100111,
	0b00111101,
	0x00,
	0b00111100,
	0b00100100
};

void clear_range(uint16_t index, uint16_t size) {
	for( uint16_t i = 0; i < size; i++) {
		oled_write_raw_byte( 0x00, index + i );
	}
}

void render_layer_state2(void) {
	uint16_t index = 0;
    switch (biton32(layer_state)) {
        case _COLEMAK:
			oled_write_data_P(colemak, index, sizeof(colemak));
            break;
        case _FN_NAV_KEYS:
			oled_write_data_P(fn_nav, index, sizeof(fn_nav));
            break; 
        case _NUMS_MIRROR:
			oled_write_data_P(num_pad, index, sizeof(num_pad));
            break;
        default:
			// Could display the layer number binary as a grid of 2x3 bits
			clear_range( index, 32 );
    }
}

void render_host_led_state2(void) {
	uint16_t index = 32;
	if( IS_HOST_LED_ON(USB_LED_NUM_LOCK) ) {
		oled_write_data_P(led_num_on, index, sizeof(led_num_on));
	} else {
		clear_range( index, sizeof(led_num_on) );
	}
	index += sizeof(led_num_on) + 1;
	if( IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ) {
		oled_write_data_P(led_caps_on, index, sizeof(led_caps_on));
	} else {
		clear_range( index, sizeof(led_caps_on) );
	}
	index += sizeof(led_caps_on) + 1;
	if( IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ) {
		oled_write_data_P(led_scroll_on, index, sizeof(led_scroll_on));
	} else {
		clear_range( index, sizeof(led_scroll_on) );
	}
}
#endif  // OLED_ENABLE
