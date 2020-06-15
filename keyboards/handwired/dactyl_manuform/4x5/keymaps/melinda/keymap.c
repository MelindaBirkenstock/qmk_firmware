#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _CUNT 3
#define _LMAO 4
// Fillers to make layering more clear

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [   |   ]  |                                                         |   -  |   =  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | ESC  |  BS  |                             | SPACE|ENTER |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | TAB  | HOME | | END  | DEL  |
 *                                    '------+------' '------+------'
 *                                    | Raise|  ~   | | GUI  | Lower|
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_QUOT, KC_COMM, KC_DOT,    KC_P,    KC_Y,                                       KC_F, KC_G,    KC_C,    KC_R,   KC_L,    \
  KC_A, KC_O, KC_E,    KC_U,    KC_I,                                       KC_D, KC_H,    KC_T,    KC_N,   KC_S, \
  KC_SCLN, KC_Q, KC_J,    KC_K,    KC_X,                                       KC_B, KC_M,    KC_W, KC_V, KC_Z, \
              KC_MINUS, KC_GRAVE,                                                   KC_SLSH, KC_EQL,                   \
                                      KC_BSPC, LT(2, KC_TAB),  LT(1, KC_ENT), KC_SPC,                                          \
                                      KC_ESC,  KC_LSFT,   TG(4),  KC_LGUI,                                           \
                                      SGUI(KC_Q),   KC_LCTL,  RGUI(KC_D), TG(3)
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  ____, ____,  KC_TRNS, KC_LALT,  ____,                          KC_TRNS, ____,    KC_TRNS,   ____,     KC_TRNS,   \
  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_UNDS, KC_PLUS,  ____,  ____,  KC_LT,                          KC_GT, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        ____,  ____,                                                          KC_TRNS,  KC_TRNS,              \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_TRNS,                            KC_TRNS,   KC_7,    KC_8,   KC_9,   KC_TRNS,  \
  KC_F5,    KC_F6,   KC_F7,    KC_F8,   KC_TRNS,                             KC_TRNS,    KC_4,     KC_5,    KC_6,    KC_TRNS,    \
  KC_F9, KC_F10,  KC_F11, KC_F12, KC_PERC,                          KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, \
           KC_TRNS, KC_TRNS,                                                               ____,    ____,             \
                                             ____, ____,  ____, KC_0,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
),

[_CUNT] = LAYOUT( \
  ____, ____,  KC_MS_UP, ____,  RESET,                          KC_TRNS, ____,    KC_TRNS,   KC_UP,     KC_TRNS,   \
  KC_EXLM, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_PERC,                          KC_CIRC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RPRN, \
  KC_UNDS, KC_PLUS,  ____,  ____,  KC_LT,                          KC_GT, KC_SLSH, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3,   \
        ____,  ____,                                                          KC_TRNS,  KC_TRNS,              \
                                   KC_MS_BTN1, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_BTN2,                                                 \
                                   ____, ____,  ____, ____,                                               \
                                   ____, ____,  ____, ____                                                  \
),
[_LMAO] = LAYOUT( \
  KC_Q, KC_D,  KC_R, KC_W,  KC_B,                          KC_J, KC_F,    KC_U,   KC_P,     KC_SCLN,   \
  KC_A, KC_S, KC_H, KC_T, KC_G,                          KC_Y, KC_N, KC_E, KC_O, KC_I, \
  KC_Z, KC_X,  KC_M,  KC_C,  KC_V,                          KC_K, KC_L, KC_QUOT, KC_COMM,  KC_DOT,   \
        ____,  ____,                                                          KC_TRNS,  KC_TRNS,              \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                               \
                                   ____, ____,  ____, ____                                                  \
)

};




void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
