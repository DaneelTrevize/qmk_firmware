#include QMK_KEYBOARD_H

#include "oled.h"

// Aliases
#define KC_MO_L3 MO(3)
#define KC_MO_L4 MO(4)
#define KC_RA_T_CA RALT_T(KC_CAPS)
#define KC_L4_SPC LT(4,KC_SPC)
#define KC_L2_BSPC LT(2,KC_BSPC)
#define KC_RC_T_EN RCTL_T(KC_ENT)

#define KC_ KC_TRNS

#define KC_MULT RALT(KC_EQL)

#define KC_EURO RALT(KC_5)
#define KC_GBP RSA(KC_4)
#define KC_NEGT RALT(KC_BSLS)
#define KC_LC_T_EN LCTL_T(KC_ENT)

#define KC_ACUT RALT(KC_QUOT)
#define KC_DEGREE RSA(KC_SCLN)
#define KC_TG_1 TG(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
       NO,     1   ,   2   ,   3   ,   4   ,   5   ,                        0   ,   9   ,   8   ,   7   ,   6   ,   NO  ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      ESC  ,   Q   ,   W   ,   F   ,   P   ,   B   ,                        J   ,   L   ,   U   ,   Y   ,  QUOT ,  PAUS ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     MO_L3 ,   A   ,   R   ,   S   ,   T   ,   G   ,                        M   ,   N   ,   E   ,   I   ,   O   , MO_L4 ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      PSCR ,   Z   ,   X   ,   C   ,   D   ,   V   ,RA_T_CA,       RALT ,   K   ,   H   ,  DOT  ,  COMM ,  SCLN ,  WHOM ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                           NO  ,  LALT , L4_SPC,L2_BSPC,             RC_T_EN,  RSFT ,  RGUI ,   NO  
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),
  
[_QWERTY] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,       ,       ,       ,       ,       ,                        6   ,   7   ,   8   ,   9   ,   0   ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   Q   ,   W   ,   E   ,   R   ,   T   ,                        Y   ,   U   ,   I   ,   O   ,   P   ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   A   ,   S   ,   D   ,   F   ,   G   ,                        H   ,   J   ,   K   ,   L   ,  SCLN ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,   Z   ,   X   ,   C   ,   V   ,   B   ,       ,            ,   N   ,   M   ,  COMM ,  DOT  ,  SLSH ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_FUNC_NUM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,       ,       ,       ,       ,       ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   F1  ,   F2  ,   F3  ,   F4  ,  BSPC ,                       MULT ,   P7  ,   P8  ,   P9  ,  PCMM ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      LCTL ,   F5  ,   F6  ,   F7  ,   F8  ,  PPLS ,                       PAST ,   P4  ,   P5  ,   P6  ,   P0  ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,   F9  ,  F10  ,  F11  ,  F12  ,  PMNS ,  NUM  ,            ,  PSLS ,   P1  ,   P2  ,   P3  ,  PDOT ,  CALC ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_NAV_CODE] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   6   ,   7   ,   8   ,   9   ,   0   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,       ,  HOME ,   UP  ,  END  ,  INS  ,                       EURO ,  GBP  ,  RPRN ,  LPRN ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,       ,  LEFT ,  DOWN ,  RGHT ,  TAB  ,                        AT  ,  DLR  ,  RBRC ,  LBRC ,       ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,       ,  PGUP ,  LCTL ,  PGDN ,  DEL  ,  SLCK ,            ,  NEGT ,  ASTR ,  SLSH ,  BSLS ,       ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,  LGUI ,  LSFT ,LC_T_EN,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_MIRR_SYM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   6   ,   7   ,   8   ,   9   ,   0   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      PAUS ,  QUOT ,   Y   ,   U   ,   L   ,   J   ,                       BSPC ,  PERC ,  ACUT ,  GRV  ,  CIRC ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   O   ,   I   ,   E   ,   N   ,   M   ,                       TAB  ,  AMPR ,  EQL  ,  MINS , DEGREE,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      WHOM ,  SCLN ,  COMM ,  DOT  ,   H   ,   K   ,  RALT ,       TG_1 ,       ,  HASH ,  EXLM ,  QUES ,       ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,  LGUI ,       ,       ,                    ,       ,       ,
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
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
	//render_logo( 0 );
	render_layer_state( 0 );
	render_host_led_state( 32 );
	render_mod_state( 64 );
    #endif // OLED_FONT_ENABLE
  } else {
    #ifdef OLED_FONT_ENABLE
    oled_write(read_logo(), false);
	#else
	render_logo( 0 );
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