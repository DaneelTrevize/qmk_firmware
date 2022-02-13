#include QMK_KEYBOARD_H

#include "oled.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   0  |   9  |   8  |   7  |   6  |Pause |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BkSp |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  | BkSp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------|  Del  |    | Enter |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Space  /       \      \  |      |      |      |
 *                   |      |      |      |/ LCtrl /         \Shift \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_COLEMAK] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_0, KC_9, KC_8, KC_7, KC_6, KC_PAUS,
  KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT,
  RALT_T(KC_BSPC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, RALT_T(KC_BSPC),
  KC_LGUI, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_DEL, KC_ENT, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_WHOM,
  TO(0), MO(2), MO(1), LCTL_T(KC_SPC), KC_RSFT, LT(1,KC_TAB), TO(2), TO(0)
  ),

/* _FN_NAV_KEYS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------|    |-------|  F10 |  F9  |  F8  |  F7  |  F6  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FN_NAV_KEYS] = LAYOUT(
  KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F20, KC_F19, KC_F18, KC_F17, KC_F16, KC_INS,
  KC_SLCK, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, KC_NO, KC_EQL, KC_RPRN, KC_LPRN, KC_TRNS, KC_CAPS,
  KC_TRNS, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_NO, KC_MINS, KC_RBRC, KC_LBRC, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_ENT, KC_TRNS, KC_F10, KC_F9, KC_F8, KC_F7, KC_F6, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* _NUMS_MIRROR
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMS_MIRROR] = LAYOUT(
  KC_PAUS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_QUOT, KC_SCLN, KC_Y, KC_U, KC_L, KC_J, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_NO, KC_NLCK,
  KC_TRNS, KC_O, KC_I, KC_E, KC_N, KC_M, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_TRNS,
  KC_TRNS, KC_SLSH, KC_DOT, KC_COMM, KC_H, KC_K, KC_ENT, KC_PENT, KC_NO, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_CALC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // face the logo inward on the slave side
    return is_keyboard_master() ? OLED_ROTATION_270 : ( is_keyboard_left() ? rotation : rotation ^ OLED_ROTATION_180 );
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
	
	// Could refactor to modify buffer, as each state has a dedicated area and most have majority static content
	// 5 chars x 16 lines when using strings and default font
    #ifdef OLED_FONT_ENABLE
    render_layer_state();
    oled_advance_page(true);
    render_host_led_state();
    oled_advance_page(true);
	render_mod_state();
    //oled_advance_page(true);
	//oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_timelog(), false);
    #endif
	render_border();
  } else {
    #ifdef OLED_FONT_ENABLE
    oled_write(read_logo(), false);
    #endif
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
  return true;
}
*/