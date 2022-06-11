#pragma once

enum layer_number {
  _COLEMAK = 0,
  _FUNCT,
  _NAV_SYM,
  _MIRR_NUM
};

#ifdef OLED_ENABLE
void render_layer_state(void);
void render_host_led_state(void);
void render_mod_state(void);
void render_border(void);
#endif // OLED_ENABLE