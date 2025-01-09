#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

void matrix_scan_user(void) {
  achordion_task();
}

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,          
    KC_ESCAPE,      KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_RALT, KC_L),KC_SCLN,        MO(3),          
    KC_NO,          MT(MOD_LGUI, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RGUI, KC_SLASH),KC_NO,          
                                                    KC_BSPC,        MO(1),                                          MO(2),          KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PLUS,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_NO,          
    KC_NO,          LCTL(KC_A),     KC_NO,          LSFT(KC_TAB),   KC_TAB,         KC_UNDS,                                        KC_MINUS,       KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_NO,          
    KC_NO,          LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_NO,                                          KC_DOT,         KC_1,           KC_2,           KC_3,           KC_SLASH,       KC_NO,          
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_ENTER,       KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_NO,          KC_LCBR,        KC_RCBR,        KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_QUOTE,       KC_DQUO,                                        KC_NO,          KC_LPRN,        KC_RPRN,        KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_BSLS,        KC_PIPE,        RALT(KC_COMMA), KC_TILD,        KC_GRAVE,                                       KC_NO,          KC_LBRC,        KC_RBRC,        KC_NO,          KC_NO,          KC_NO,          
                                                    KC_DELETE,      MO(4),                                          KC_TRANSPARENT, KC_NO
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,          KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          LCTL(KC_D),     LCTL(KC_U),     KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    LCTL(KC_P),     KC_NO,                                          KC_ENTER,       LCTL(KC_N)
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_MEDIA_STOP,  KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO,                                          KC_NO,          KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_NO,          KC_NO,          
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,                                          KC_NO,          KC_F11,         KC_F12,         RGB_VAD,        RGB_VAI,        KC_NO,          
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_NO,          KC_NO
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, KC_S):
            return g_tapping_term + 10;
        case MT(MOD_LCTL, KC_D):
            return g_tapping_term + 10;
        case MT(MOD_LSFT, KC_F):
            return g_tapping_term + 10;
        case MT(MOD_RSFT, KC_J):
            return g_tapping_term + 10;
        case MT(MOD_RCTL, KC_K):
            return g_tapping_term + 10;
        case MT(MOD_RALT, KC_L):
            return g_tapping_term + 10;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,0}, {0,0,206}, {0,0,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {132,225,253}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,206}, {0,0,0}, {0,0,206}, {0,0,206}, {0,0,206}, {0,0,0}, {26,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,206}, {0,0,206}, {87,247,224}, {0,0,0} },

    [1] = { {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {108,237,255}, {108,237,255}, {43,239,210}, {132,225,182}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {132,225,182}, {43,239,210}, {0,0,255}, {0,0,255}, {0,0,255}, {43,239,210}, {132,225,182}, {43,239,210}, {0,0,255}, {0,0,255}, {0,0,255}, {132,225,182}, {0,0,0}, {132,225,182}, {0,0,255}, {0,0,255}, {0,0,255}, {43,239,210}, {132,225,182}, {132,225,182}, {0,0,255} },

    [2] = { {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {89,244,213}, {89,244,213}, {89,244,213}, {89,244,213}, {89,244,213}, {0,0,0}, {89,244,213}, {89,244,213}, {89,244,213}, {89,126,255}, {89,126,255}, {87,248,153}, {89,126,255}, {89,126,255}, {43,239,210}, {89,126,255}, {89,126,255}, {0,245,245}, {186,169,255}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {87,248,153}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {87,248,153}, {0,0,0}, {45,216,253}, {45,216,253}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {87,248,153}, {0,0,0}, {0,0,0} },

    [3] = { {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {234,255,255}, {234,255,255}, {0,0,0}, {26,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {186,169,255}, {0,0,0}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {26,235,226}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {0,0,0}, {26,235,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {26,235,226}, {0,0,0}, {186,169,255} },

    [4] = { {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {153,223,244}, {153,223,244}, {153,223,244}, {153,223,244}, {0,0,0}, {0,0,0}, {43,239,210}, {43,239,210}, {43,239,210}, {43,239,210}, {43,239,210}, {186,169,255}, {0,0,0}, {0,221,221}, {0,221,221}, {0,221,221}, {0,0,0}, {0,0,0}, {0,0,0}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {186,169,255}, {0,0,0}, {153,223,244}, {153,223,244}, {153,223,244}, {0,0,0}, {186,169,255}, {43,239,210}, {43,239,210}, {43,239,210}, {43,239,210}, {43,239,210}, {0,0,0}, {0,0,0}, {43,239,210}, {43,239,210}, {0,0,255}, {0,0,255}, {186,169,255}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



