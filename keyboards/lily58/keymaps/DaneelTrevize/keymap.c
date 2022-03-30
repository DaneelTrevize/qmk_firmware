#include QMK_KEYBOARD_H

#include "oled.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   0  |   9  |   8  |   7  |   6  | Pause|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | AltGr|   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  |Browsr|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BkSp |   A  |   R  |   S  |   T  |   G  |------.      .------|   M  |   N  |   E  |   I  |   O  |  Alt |
 * |------+------+------+------+------+------|   `  |      |   /  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |------|      |------|   K  |   H  |   .  |   ,  |   ;  |  Del |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |Layer3| / Space/        \      \ |Layer2|      |      |
 *                   |Layer1| LGUI | Enter|/ Ctrl /          \ Shift\| BkSp |Layer3| Ctrl |
 *                   `---------------------------´            `---------------------------´
 */
[_COLEMAK] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_0, KC_9, KC_8, KC_7, KC_6, KC_PAUS,
  OSM(MOD_RALT), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_WHOM,
  LT(2,KC_BSPC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_LALT,
  OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_GRV, KC_SLSH, KC_K, KC_H, KC_DOT, KC_COMM, KC_SCLN, KC_DEL,
  TT(1), KC_LGUI, LT(3,KC_ENT), LCTL_T(KC_SPC), KC_RSFT, LT(2,KC_BSPC), TT(3), KC_RCTL
  ),

/* _FUNCT
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Alt |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |------.      .------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| Space|      |      |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |------|      |------|      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |      | /      /        \      \ |      |      |      |
 *                   |      | BkSp |      |/ Ctrl /          \      \|      |      |      |
 *                   `---------------------------´            `---------------------------´
 */
[_FUNCT] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LALT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  MO(2), KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LSFT, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_BSPC, MO(3), KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* _NAV_SYM
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SCROLL| PgUp | Home |  Up  |  End | PgDn |                    |   %  |   $  |   )  |   (  |   ´  | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Right|PrintS|------.      .------|   \  |   =  |   ]  |   [  |   -  |      |
 * |------+------+------+------+------+------|      |      |   !  |------+------+------+------+------+------|
 * |      |      |  Alt | Shift|  Tab |      |------|      |------|   @  |   #  |   *  |   &  |   ;  |Insert|
 * `-----------------------------------------/      /      \      \-----------------------------------------´
 *                   |      |      |      | /      /        \      \ |      |      |      |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `---------------------------´            `---------------------------´
 */
[_NAV_SYM] = LAYOUT(
  KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_SLCK, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, KC_PERC, KC_DLR, KC_RPRN, KC_LPRN, RALT(KC_QUOT), KC_CAPS,
  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_BSLS, KC_EQL, KC_RBRC, KC_LBRC, KC_MINS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_LALT, KC_LSFT, KC_TAB, KC_TRNS, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_ASTR, KC_AMPR, RALT(KC_SCLN), KC_INS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
  KC_PAUS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_WHOM, KC_QUOT, KC_Y, KC_U, KC_L, KC_J, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PEQL, KC_NLCK,
  KC_LALT, KC_O, KC_I, KC_E, KC_N, KC_M, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_P0, KC_PCMM,
  KC_DEL, KC_SCLN, KC_COMM, KC_DOT, KC_H, KC_K, KC_SLSH, KC_PSLS, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_CALC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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