#include QMK_KEYBOARD_H

#include "oled.h"

// Aliases
#define KC_L2_BSPC LT(2,KC_BSPC)
#define KC_RA_T_G RALT_T(KC_G)
#define KC_TG_L1 TG(1)
#define KC_L3_SPC LT(3,KC_SPC)
#define KC_L1_TAB LT(1,KC_TAB)
#define KC_LCT_ENT LCTL_T(KC_ENT)
#define KC_RSF_SPC RSFT_T(KC_SPC)
#define KC_TG_L3 TG(3)

#define KC_ KC_TRNS
#define KC_RALT_3 RALT(KC_3)
#define KC_RALT_2 RALT(KC_2)
#define KC_RSFAL_3 RSA(KC_4)
#define KC_MO_L2 MO(2)
#define KC_RCT_BSP RCTL(KC_BSPC)
#define KC_RSA_SCL RSA(KC_SCLN)
#define KC_MO_L3 MO(3)

#define KC_RALT_6 RALT(KC_6)
#define KC_RALT_7 RALT(KC_7)
#define KC_RALT_0 RALT(KC_0)
#define KC_RALT_9 RALT(KC_9)
#define KC_LSF_TAB LSFT(KC_TAB)
#define KC_RAL_EQL RALT(KC_EQL)
#define KC_RAL_BSL RALT(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
      ESC  ,   1   ,   2   ,   3   ,   4   ,   5   ,                        0   ,   9   ,   8   ,   7   ,   6   ,  PAUS ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      CAPS ,   Q   ,   W   ,   F   ,   P   ,   B   ,                        J   ,   L   ,   U   ,   Y   ,  QUOT ,   NO  ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    L2_BSPC,   A   ,   R   ,   S   ,   T   , RA_T_G,                        M   ,   N   ,   E   ,   I   ,   O   ,L2_BSPC,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      PSCR ,   Z   ,   X   ,   C   ,   D   ,   V   ,  TAB  ,       DEL  ,   K   ,   H   ,  DOT  ,  COMM ,  SCLN ,  RCTL ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                         TG_L1 ,  LGUI , L3_SPC,LCT_ENT,              L1_TAB,RSF_SPC, TG_L3 ,  WHOM
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_FUNCT] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   F1  ,   F2  ,   F3  ,   F4  ,   F5  ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      INS  ,   F6  ,   F7  ,   F8  ,   F9  ,  F10  ,                      RALT_3, RALT_2,RSFAL_3,  DLR  ,  CIRC ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     MO_L2 ,  F11  ,  F12  ,  F13  ,  F14  ,  F15  ,                        AT  ,  AMPR ,  RPRN ,  LPRN ,  QUES ,RCT_BSP,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,  F16  ,  F17  ,  F18  ,  F19  ,  F20  ,       ,            ,RSA_SCL,  EXLM ,  PLUS ,  MINS ,  COLN ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,  SPC  , MO_L3 ,  LCTL ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_NAV_SYM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
           ,   1   ,   2   ,   3   ,   4   ,   5   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      SLCK ,  PGUP ,  HOME ,   UP  ,  END  ,  PGDN ,                      RALT_6, RALT_7, RALT_0, RALT_9,  GRV  ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,  F21  ,  LEFT ,  DOWN ,  RGHT ,LSF_TAB,                     RAL_EQL,  HASH ,  RBRC ,  LBRC ,  F23  ,       ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
           ,  F22  ,  MINS ,  LCTL ,  EQL  ,  APP  ,       ,            ,RAL_BSL,  ASTR ,  SLSH ,  BSLS ,  F24  ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,  LGUI ,  LALT ,  LSFT ,                    ,       ,       ,       
//                     `-------^-------^-------^-------´            `-------^-------^-------^-------´
  ),

[_MIRR_NUM] = LAYOUT_KC(
// .-------.-------.-------.-------.-------.-------.                    .-------.-------.-------.-------.-------.-------.
      PAUS ,   6   ,   7   ,   8   ,   9   ,   0   ,                            ,       ,       ,       ,       ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
      NLCK ,  QUOT ,   Y   ,   U   ,   L   ,   J   ,                       PCMM ,   P7  ,   P8  ,   P9  ,  PENT ,       ,
// |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
           ,   O   ,   I   ,   E   ,   N   ,   M   ,                       PAST ,   P4  ,   P5  ,   P6  ,   P0  ,  PDOT ,
// |-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
      RCTL ,  SCLN ,  COMM ,  DOT  ,   H   ,   K   ,  DEL  ,            ,  PSLS ,   P1  ,   P2  ,   P3  ,  PEQL ,       ,
// `-------^-------^---.---^---.---^---.---^---.---^---.---´    `---.---^---.---^---.---^---.---^---.---^-------^-------´
                               ,       ,       ,       ,               PMNS ,  PPLS ,       ,  CALC
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