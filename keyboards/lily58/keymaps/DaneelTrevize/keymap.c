#include QMK_KEYBOARD_H

#include "oled.h"

// Aliases
#define KC_L3_BSPC LT(3,KC_BSPC)
#define KC_RAL_T_G RALT_T(KC_G)
#define KC_RAL_T_M RALT_T(KC_M)
#define KC_TG_L1 TG(1)
#define KC_MO_L2 MO(2)
#define KC_LCT_SPC LCTL_T(KC_SPC)
#define KC_MO_L1 MO(1)

#define KC_ KC_TRNS
#define KC_RCTL_BS RCTL(KC_BSPC)

#define KC_SUP_1 RSA(KC_1)
#define KC_MULT RALT(KC_EQL)
#define KC_NEGT RALT(KC_BSLS)
#define KC_SUP_2 RALT(KC_2)
#define KC_LAL_PSC LALT(KC_PSCR)
#define KC_SUP_3 RALT(KC_3)

#define KC_BKSQUO RALT(KC_0)
#define KC_FWSQUO RALT(KC_9)
#define KC_ACUT RALT(KC_QUOT)
#define KC_EURO RALT(KC_5)
#define KC_DEGREE RSA(KC_SCLN)
#define KC_GBP RSA(KC_4)
#define KC_HALF RALT(KC_7)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
      ESC  ,   1   ,   2   ,   3   ,   4   ,   5   ,                        0   ,   9   ,   8   ,   7   ,   6   ,   NO  ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      NUM  ,   Q   ,   W   ,   F   ,   P   ,   B   ,                        J   ,   L   ,   U   ,   Y   ,  QUOT ,  PAUS ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    L3_BSPC,   A   ,   R   ,   S   ,   T   ,RAL_T_G,                     RAL_T_M,   N   ,   E   ,   I   ,   O   ,L3_BSPC,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      PSCR ,   Z   ,   X   ,   C   ,   D   ,   V   ,  WHOM ,       DEL  ,   K   ,   H   ,  DOT  ,  COMM ,  MINS ,  RCTL ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                           NO  , TG_L1 , MO_L2 ,LCT_SPC,              MO_L1 ,  RSFT ,  RGUI ,   NO 
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_FUNC_NUM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   F1  ,   F2  ,   F3  ,   F4  ,   F5  ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      CAPS ,   F6  ,   F7  ,   F8  ,   F9  ,  F10  ,                       PCMM ,   P7  ,   P8  ,   P9  ,  PDOT ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  F11  ,  F12  ,  F13  ,  F14  ,  F15  ,                       PAST ,   P4  ,   P5  ,   P6  ,   P0  ,RCTL_BS,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,  F16  ,  F17  ,  F18  ,  F19  ,  F20  ,  CALC ,       PSLS ,  PPLS ,   P1  ,   P2  ,   P3  ,  PMNS ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,  LCTL ,                    ,  PENT ,  PEQL ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_NAV_CODE] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   1   ,   2   ,   3   ,   4   ,   5   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      SLCK ,  PGUP ,  HOME ,   UP  ,  END  ,  PGDN ,                      SUP_1 ,  MULT ,  SLSH ,  BSLS ,  NEGT ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  LSFT ,  LEFT ,  DOWN ,  RGHT ,  ENT  ,                      SUP_2 ,  ASTR ,  RPRN ,  LPRN ,  HASH ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
    LAL_PSC,  LGUI ,  LALT ,  LCTL ,  TAB  ,  APP  ,  INS  ,            , SUP_3 ,  EQL  ,  RBRC ,  LBRC ,  SCLN ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_MIRR_SYM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   6   ,   7   ,   8   ,   9   ,   0   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      PAUS ,  QUOT ,   Y   ,   U   ,   L   ,   J   ,                      BKSQUO, FWSQUO,  GRV  ,  ACUT ,  CIRC ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   O   ,   I   ,   E   ,   N   ,   M   ,                        AT  ,  AMPR ,  EXLM ,  QUES ,  EURO ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      RCTL ,  SCLN ,  COMM ,  DOT  ,   H   ,   K   ,  DEL  ,            , DEGREE,  PERC ,  GBP  ,  DLR  ,  HALF ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,  LGUI ,  LSFT ,  LALT ,               LALT ,       ,       ,
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