#include QMK_KEYBOARD_H

#include "oled.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * .-----------------------------------------.                    .-----------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |                    |   0  |   9  |   8  |   7  |   6  | Pause|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift|   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Layer2|      |      |      |      |      |------.      .------|      |      |      |      |      |  Alt |
 * | BkSp |   A  |   R  |   S  |   T  |   G  | AltGr|      |Layer1|   M  |   N  |   E  |   I  |   O  |   `  |
 * |------+------+------+------+------+------|  Tab |      |   /  |------+------+------+------+------+------|
 * |Layer1|   Z  |   X  |   C  |   D  |   V  |------|      |------|   K  |   H  |   .  |   ,  |   ;  | Ctrl |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |Layer3| / Space/        \ Space\ |Layer2|      |      |
 *                   | Print| LGUI | Enter|/ Ctrl /          \ Shift\| BkSp |Layer3|Browsr|
 *                   `---------------------------´            `---------------------------´
 */
[_COLEMAK] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_0, KC_9, KC_8, KC_7, KC_6, KC_PAUS,
  KC_CAPS, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO,
  LT(2,KC_BSPC), KC_A, KC_R, KC_S, KC_T, RALT_T(KC_G), KC_M, KC_N, KC_E, KC_I, KC_O, LT(2,KC_BSPC),
  KC_PSCR, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_TAB, KC_DEL, KC_K, KC_H, KC_DOT, KC_COMM, KC_SCLN, KC_RCTL,
  TG(1), KC_LGUI, LT(3,KC_SPC), LCTL_T(KC_ENT), LT(1,KC_TAB), RSFT_T(KC_SPC), TG(3), KC_WHOM
  ),

/* _FUNCT
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Layer2|  F11 |  F12 |  F13 |  F14 |  F15 |------.      .------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Tab |      |      |------+------+------+------+------+------|
 * |      |  F16 |  F17 |  F18 |  F19 |  F20 |------|      |------|      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |      | /      /        \      \ |      |      |      |
 *                   |      | Enter|Layer3|/ Ctrl /          \      \|      |      |      |
 *                   `---------------------------´            `---------------------------´
 */
[_FUNCT] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_INS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RALT(KC_3), RALT(KC_2), RSA(KC_4), KC_DLR, KC_CIRC, KC_TRNS,
  MO(2), KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_AT, KC_AMPR, KC_RPRN, KC_LPRN, KC_QUES, RCTL(KC_BSPC),
  KC_TRNS, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS, KC_TRNS, RSA(KC_SCLN), KC_EXLM, KC_PLUS, KC_MINS, KC_COLN, KC_TRNS,
  KC_TRNS, KC_SPC, MO(3), KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* _NAV_SYM
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SCROLL| PgUp | Home |  Up  |  End | PgDn |                    |   %  |   $  |   )  |   (  |   ´  | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Alt | Left | Down | Right|  Tab |------.      .------|   \  |   =  |   ]  |   [  |   -  |      |
 * |------+------+------+------+------+------|      |      |   !  |------+------+------+------+------+------|
 * |      |      | BkSp | Ctrl |  Del | Space|------|      |------|   @  |   #  |   *  |   &  |   ;  |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |      | /      /        \      \ |      |      |      |
 *                   |      |      |      |/ Shift/          \      \|      |      |Insert|
 *                   `---------------------------´            `---------------------------´
 */
[_NAV_SYM] = LAYOUT(
  KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLCK,
  KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, RALT(KC_6), RALT(KC_7), RALT(KC_0), RALT(KC_9), KC_GRV, KC_TRNS,
  KC_TRNS, KC_F21, KC_LEFT, KC_DOWN, KC_RGHT, LSFT(KC_TAB), RALT(KC_EQL), KC_HASH, KC_RBRC, KC_LBRC, KC_F23, KC_TRNS,
  KC_TRNS, KC_F22, KC_MINS, KC_LCTL, KC_EQL, KC_APP, KC_TRNS, KC_TRNS, RALT(KC_BSLS), KC_ASTR, KC_SLSH, KC_BSLS, KC_F24, KC_TRNS,
  KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  
/* _MIRR_NUM
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   *  |   7  |   8  |   9  |   =  |  NUM |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |------.      .------|   +  |   4  |   5  |   6  |   0  |   .  |
 * |------+------+------+------+------+------|      |      |   /  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |------|      |------|   -  |   1  |   2  |   3  | Calc |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |      | /      /        \      \ |      |      |      |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `---------------------------´            `---------------------------´
 */
[_MIRR_NUM] = LAYOUT(
  KC_PAUS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK,
  KC_QUOT, KC_Y, KC_U, KC_L, KC_J, KC_PCMM, KC_P7, KC_P8, KC_P9, KC_PENT, KC_TRNS,
  KC_TRNS, KC_O, KC_I, KC_E, KC_N, KC_M, KC_PAST, KC_P4, KC_P5, KC_P6, KC_P0, KC_PDOT,
  KC_RCTL, KC_SCLN, KC_COMM, KC_DOT, KC_H, KC_K, KC_DEL, KC_TRNS, KC_PSLS, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_PPLS, KC_TRNS, KC_CALC
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    #ifdef OLED_FONT_ENABLE
    // face the logo inward on the slave side
    return is_keyboard_master() ? OLED_ROTATION_270 : ( is_keyboard_left() ? rotation : rotation ^ OLED_ROTATION_180 );
	#else
	return OLED_ROTATION_270;
    #endif // OLED_FONT_ENABLE
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
	
    #ifdef OLED_FONT_ENABLE
	// 5 chars x 16 lines when using strings and default font
    write_layer_state();
    oled_advance_page(true);
    write_host_led_state();
    oled_advance_page(true);
	write_mod_state();
    //oled_advance_page(true);
	//oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_timelog(), false);
	#else
	render_layer_state( 0 );
	render_host_led_state( 32 );
	render_mod_state( 64 );
    #endif // OLED_FONT_ENABLE
  } else {
    #ifdef OLED_FONT_ENABLE
    oled_write(read_logo(), false);
    #endif // OLED_FONT_ENABLE
  }
    return false;
}
#endif // OLED_ENABLE
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    //set_keylog(keycode, record);
#endif
    // set_timelog();
  }
}
*/