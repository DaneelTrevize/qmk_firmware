#pragma once

enum layer_number {
  _COLEMAK = 0,
  _FN_NAV_KEYS,
  _NUMS_MIRROR
};

#ifdef OLED_ENABLE
  #ifdef OLED_FONT_ENABLE
  void render_layer_state(void);
  void render_host_led_state(void);
  void render_mod_state(void);
  #endif // OLED_FONT_ENABLE
void render_layer_state2( uint16_t index );
void render_host_led_state2( uint16_t index );
void render_mod_state2( uint16_t index );
#endif // OLED_ENABLE