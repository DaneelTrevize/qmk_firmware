#include QMK_KEYBOARD_H

#include "oled.h"

// Aliases
#define KC_MO_L4 MO(4)
#define KC_TG_1 TG(1)
#define KC_RA_T_CA RALT_T(KC_CAPS)
#define KC_RA_T_TA RALT_T(KC_TAB)
#define KC_L4_PSCR LT(4,KC_PSCR)
#define KC_L3_SPC LT(3,KC_SPC)
#define KC_L2_BSPC LT(2,KC_BSPC)
#define KC_RC_T_EN RCTL_T(KC_ENT)

#define KC_ KC_TRNS

#define KC_EURO RALT(KC_5)
#define KC_GBP RSA(KC_4)

#define KC_ACUT RALT(KC_QUOT)
#define KC_MULT RALT(KC_EQL)
#define KC_NEGT RALT(KC_BSLS)
#define KC_TG_2 TG(2)

#define KC_HALF RALT(KC_7)
#define KC_BKSQUO RALT(KC_0)
#define KC_FWSQUO RALT(KC_9)
#define KC_DEGREE RSA(KC_SCLN)
#define KC_SUP_1 RSA(KC_1)
#define KC_SUP_2 RALT(KC_2)
#define KC_SUP_3 RALT(KC_3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
       NO,     0   ,   1   ,   2   ,   3   ,   4   ,                        9   ,   8   ,   7   ,   6   ,    5  ,   NO  ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      ESC  ,   Q   ,   W   ,   F   ,   P   ,   B   ,                        J   ,   L   ,   U   ,   Y   ,  QUOT ,  PAUS ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      LALT ,   A   ,   R   ,   S   ,   T   ,   G   ,                        M   ,   N   ,   E   ,   I   ,   O   , MO_L4 ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      TG_1 ,   Z   ,   X   ,   C   ,   D   ,   V   ,RA_T_CA,     RA_T_TA,   K   ,   H   ,  DOT  ,  COMM ,  MINS ,  WHOM ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                           NO  ,L4_PSCR, L3_SPC,L2_BSPC,             RC_T_EN,  RSFT ,  RGUI ,   NO  
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),
  
[_QWERTY] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   1   ,   2   ,   3   ,   4   ,   5   ,                        6   ,   7   ,   8   ,   9   ,   0   ,       ,
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
           ,  PCMM ,   F1  ,   F2  ,   F3  ,   F4  ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  INS  ,   F5  ,   F6  ,   F7  ,   F8  ,                       EURO ,   P7  ,   P8  ,   P9  ,  PERC ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  LSFT ,   F9  ,  F10  ,  F11  ,  F12  ,                       GBP  ,   P4  ,   P5  ,   P6  ,   P0  ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,  PMNS ,  PPLS ,  PSLS ,  PAST ,  PENT ,  NUM  ,            ,  DLR  ,   P1  ,   P2  ,   P3  ,  PDOT ,  CALC ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_NAV_CODE] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   5   ,   6   ,   7   ,   8   ,   9   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  PGUP ,  HOME ,   UP  ,  END  ,  PGDN ,                       CIRC ,  GRV  ,  RPRN ,  LPRN ,  ACUT ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      LGUI ,  LSFT ,  LEFT ,  DOWN ,  RGHT ,  TAB  ,                        AT  ,  HASH ,  RBRC ,  LBRC ,  SCLN ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,  MINS ,  EQL  ,  LCTL ,  DEL  ,  ENT  ,  SLCK ,            ,  MULT ,  ASTR ,  SLSH ,  BSLS ,  NEGT ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,                    ,       ,  TG_2 ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_MIRR_SYM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   5   ,   6   ,   7   ,   8   ,   9   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      PAUS ,  QUOT ,   Y   ,   U   ,   L   ,   J   ,                            ,  HALF , BKSQUO, FWSQUO,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   O   ,   I   ,   E   ,   N   ,   M   ,                            ,  AMPR ,  EXLM ,  QUES , DEGREE,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      WHOM ,  MINS ,  COMM ,  DOT  ,   H   ,   K   ,RA_T_TA,            ,       , SUP_1 , SUP_2 , SUP_3 ,       ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,  LSFT ,  LCTL ,                    ,       ,       ,
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