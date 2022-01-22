#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK = 0,
  _FN_NAV_KEYS,
  _NUMS_MIRROR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   0  |   9  |   8  |   7  |   6  |Pause |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BkSp |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  | BkSp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |`AltGr|
 * |------+------+------+------+------+------|  Del  |    | Enter |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |MO(2) |MO(1) | /Space  /       \ Tab  \  |MO(1) |MO(2) |      |
 *                   |      |      |      |/ LCtrl /         \Shift \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_COLEMAK] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_0, KC_9, KC_8, KC_7, KC_6, KC_PAUS,
  KC_BSPC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC,
  KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, RALT_T(KC_GRV),
  KC_LGUI, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_DEL, KC_ENT, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
  KC_NO, MO(2), MO(1), MT(MOD_LCTL, KC_SPC), MT(MOD_RSFT, KC_TAB), MO(1), MO(2), KC_NO
  ),

/* _FN_NAV_KEYS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------|    |-------|  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |MO(2) |MO(1) | /       /       \      \  |MO(1) |MO(2) |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FN_NAV_KEYS] = LAYOUT(
  KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F20, KC_F19, KC_F18, KC_F17, KC_F16, KC_SLCK,
  KC_WHOM, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, KC_CAPS, KC_EQL, KC_RBRC, KC_LBRC, KC_INS, KC_TRNS,
  KC_TRNS, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_BSLS, KC_MINS, KC_0, KC_9, KC_SCLN, KC_TRNS,
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
 *                   |      |MO(2) |MO(1) | /       /       \      \  |MO(1) |MO(2) |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMS_MIRROR] = LAYOUT(
  KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_TRNS, KC_QUOT, KC_Y, KC_U, KC_L, KC_J, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_PAST, KC_TRNS,
  KC_TRNS, KC_O, KC_I, KC_E, KC_N, KC_M, KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PSLS, KC_TRNS,
  KC_TRNS, KC_SLSH, KC_DOT, KC_COMM, KC_H, KC_K, KC_TRNS, KC_PENT, KC_NLCK, KC_P1, KC_P2, KC_P3, KC_CALC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS
  )
};
/*
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/
//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // face the logo inward on the slave side
    return is_keyboard_master() ? OLED_ROTATION_270 : ( is_keyboard_left() ? rotation : rotation ^ OLED_ROTATION_180 );
}

// When you add source files to SRC in rules.mk, you can use functions.
//const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void render_layer_state(void) {
    char layer_name[17];
    //oled_write_P(PSTR("Layer: "), false);
    //oled_write("Layer", false);

    switch (biton32(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Cole   mak"), false);
            break;
        case _FN_NAV_KEYS:
            oled_write_ln_P(PSTR("Func   Nav"), false);
            break;
        case _NUMS_MIRROR:
            oled_write_ln_P(PSTR("Num    Pad"), false);
            break;
        default:
            snprintf(layer_name, sizeof(layer_name), "Und-%ld", layer_state);
            oled_write_ln(layer_name, false);
    }
}

void render_host_led_state(void) {
    char    led_state_str[6];
    snprintf(led_state_str, sizeof(led_state_str), "%c %c %c",
            (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) ? 'N' : ' ',
            (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) ? 'C' : ' ',
            (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) ? 'S' : ' ');
    
    oled_write_ln(led_state_str, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
    render_layer_state();
    render_host_led_state();
	oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
