#include QMK_KEYBOARD_H

#define BASE 0
#define _FN1 1
#define _FN2 2
#define GAME 3

#define _FN1SPC LT(_FN1, KC_SPC)

#define _______ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [BASE] = LAYOUT_DGB(
          KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
          KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
          KC_LCTL, KC_A,    KC_S,    KC_D,     KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
          KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN1),
          KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1), MO(_FN2), KC_SPC,  MO(_FN1), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

     [_FN1] = LAYOUT_DGB(
          KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
          _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, KC_DEL,
          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

     [_FN2] = LAYOUT_DGB(
          _______, M(1),    M(2),    M(3),    M(4),    M(5),     M(6),    M(7),    M(8),    M(9),    M(10),    M(11),  M(12),   _______, _______,
          _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,  RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
          _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,   BL_STEP, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, TG(GAME), _______, _______, _______, _______, _______),

     [GAME] = LAYOUT_DGB(
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
          _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______, _______),
};

int rgbmode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     //rgbmode += 1;
     //rgbmode %= 255;
     //rgblight_mode(rgbmode);
     return 1;
}

uint32_t layer_state_set_user(uint32_t state) {
     switch (biton32(state)) {
          case BASE:
               rgblight_setrgb(0x00, 0xFF, 0x00);
               break;

          case _FN1:
               rgblight_setrgb(0x00, 0x00, 0xFF);
               break;

          case _FN2:
               rgblight_setrgb(0xFF, 0xFF, 0x00);
               break;

          case GAME:
               rgblight_setrgb(0xFF, 0x00, 0x00);
               break;

          default:
               rgblight_setrgb (0xFF,  0xFF, 0xFF);
               break;
     }
     return state;
}
