#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum combos_events {
  ZC_COPY,
  XV_PASTE,
  ZV_GAMER

};

const uint16_t PROGMEM copy_combo[] = {KC_I, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM gamer_combo[] = {KC_V, KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZC_COPY] = COMBO_ACTION(copy_combo),
  [XV_PASTE] = COMBO_ACTION(paste_combo),
  [ZV_GAMER] = COMBO_ACTION(gamer_combo)
};
void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case ZC_COPY:
      if (pressed) {
        tap_code16(SGUI(KC_Q));
      }
      break;
    case XV_PASTE:
      if (pressed) {
        tap_code16(LGUI(KC_D));
      }
      break;
    case ZV_GAMER:
      if (pressed) {
        layer_invert(_ADJUST);
      }
  }

}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    \
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
  KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W, KC_V,  KC_Z, \
                    KC_BSPC, LT(2, KC_TAB), KC_LSFT,         KC_LCTL, LT(1, KC_ENT), KC_SPC                 \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  RESET,    KC_TRNS,    KC_TRNS,    KC_LALT,    KC_ESC,         KC_TRNS,    KC_TRNS,    KC_BSLS,    KC_9,    RESET,    \
  KC_EXLM,    KC_AT, KC_HASH, KC_DLR,   KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, \
  KC_UNDS, KC_PLUS,  KC_MINUS, KC_GRAVE, KC_LT,      KC_GT, KC_SLSH, KC_EQUAL, KC_QUES,  KC_PIPE, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------|      |    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_F1, KC_F2,   KC_F3, KC_F4,  KC_PERC,      KC_CIRC, KC_7, KC_8, KC_9, KC_RPRN, \
  KC_F5,  KC_F6, KC_F7, KC_F8, _______,      _______, KC_4, KC_5, KC_6, KC_RCBR, \
  KC_F9, KC_F10, KC_F11, KC_F12, _______,            SGUI_T(KC_SLSH), KC_1, KC_2, KC_3,  KC_DQT, \
                    _______, _______, _______,      RGUI(KC_D),  SGUI(KC_Q), KC_0                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_UP,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, \
  RESET,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};



