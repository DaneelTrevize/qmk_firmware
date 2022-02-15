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
void render_border(void) {
	for( uint8_t x = 0; x < OLED_DISPLAY_HEIGHT; x++ ) {
		oled_write_pixel( x, 0, true );
		oled_write_pixel( x, OLED_DISPLAY_WIDTH-1, true );
	}
	for( uint8_t y = 0; y < OLED_DISPLAY_WIDTH; y++ ) {
		oled_write_pixel( 0, y, true );
		oled_write_pixel( OLED_DISPLAY_HEIGHT-1, y, true );
	}
}

void render_host_led_state2(void) {
	if( IS_HOST_LED_ON(USB_LED_NUM_LOCK) ) {
		// Num
		oled_write_raw_byte( 0b00111111, 0 );
		oled_write_raw_byte( 0b00000100, 1 );
		oled_write_raw_byte( 0b00001000, 2 );
		oled_write_raw_byte( 0b00111111, 3 );
		
		oled_write_raw_byte( 0b00111100, 5 );
		oled_write_raw_byte( 0b00100000, 6 );
		oled_write_raw_byte( 0b00111100, 7 );
		
		oled_write_raw_byte( 0b00111100, 9 );
		oled_write_raw_byte( 0b00000100, 10 );
		oled_write_raw_byte( 0b00111100, 11 );
		oled_write_raw_byte( 0b00000100, 12 );
		oled_write_raw_byte( 0b00111100, 13 );
	} else {
		oled_write_raw_byte( 0, 0 );
		oled_write_raw_byte( 0, 1 );
		oled_write_raw_byte( 0, 2 );
		oled_write_raw_byte( 0, 3 );
		
		oled_write_raw_byte( 0, 5 );
		oled_write_raw_byte( 0, 6 );
		oled_write_raw_byte( 0, 7 );
		
		oled_write_raw_byte( 0, 9 );
		oled_write_raw_byte( 0, 10 );
		oled_write_raw_byte( 0, 11 );
		oled_write_raw_byte( 0, 12 );
		oled_write_raw_byte( 0, 13 );
	}
	if( IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ) {
		// Cap
		oled_write_raw_byte( 0b00111111, 15 );
		oled_write_raw_byte( 0b00100001, 16 );
		oled_write_raw_byte( 0b00110011, 17 );
		
		oled_write_raw_byte( 0b00111100, 19 );
		oled_write_raw_byte( 0b00010100, 20 );
		oled_write_raw_byte( 0b00111100, 21 );
		
		oled_write_raw_byte( 0b00111100, 23 );
		oled_write_raw_byte( 0b00010100, 24 );
		oled_write_raw_byte( 0b00011100, 25 );
	} else {
		oled_write_raw_byte( 0, 15 );
		oled_write_raw_byte( 0, 16 );
		oled_write_raw_byte( 0, 17 );
		
		oled_write_raw_byte( 0, 19 );
		oled_write_raw_byte( 0, 20 );
		oled_write_raw_byte( 0, 21 );
		
		oled_write_raw_byte( 0, 23 );
		oled_write_raw_byte( 0, 24 );
		oled_write_raw_byte( 0, 25 );
	}
	if( IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ) {
		// SL
		oled_write_raw_byte( 0b00100111, 27 );
		oled_write_raw_byte( 0b00111001, 28 );
		
		oled_write_raw_byte( 0b00111111, 30 );
		oled_write_raw_byte( 0b00100000, 31 );
	} else {
		oled_write_raw_byte( 0, 27 );
		oled_write_raw_byte( 0, 28 );
		
		oled_write_raw_byte( 0, 30 );
		oled_write_raw_byte( 0, 31 );
	}
}
#endif  // OLED_ENABLE
