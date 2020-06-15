/* Copyright 2020 Richard Head
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap

#define _BASE    0
#define _LOWER   1
#define _RAISE   2
#define _ADJUST  3
#define _MUIS    4

#define ____ KC_TRNS


enum combos {
  COMDOT_ESC,
  QJ_LCTRL,
  TAB_TJBAD,
  SLASH_RL,
  ZC_COPY,
  XV_PASTE,
  PUCK,
  MUHFUGGIN,
  M
};

const uint16_t PROGMEM com_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM qj_combo[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM tj_combo[] = {KC_DOT, KC_Y, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM puck_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_I, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM muh_combo[] = {KC_X, KC_B, COMBO_END};
const uint16_t PROGMEM m_combo[] = {KC_O, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMDOT_ESC] = COMBO(com_combo, KC_ESC),
  [QJ_LCTRL] = COMBO(qj_combo, KC_LCTL),
  [TAB_TJBAD] = COMBO(tj_combo, KC_TAB),
  [SLASH_RL] = COMBO(slsh_combo, KC_SLSH),
  [PUCK] = COMBO(puck_combo, KC_QUES),
  [ZC_COPY] = COMBO_ACTION(copy_combo),
  [XV_PASTE] = COMBO_ACTION(paste_combo),
  [XB_PASTE] = COMBO_ACTION(muh_combo, KC_EQL),
  [M] = COMBO_ACTION(m_combo)

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_QUOTE, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L,
  KC_A,    CT_O,    AL_E,    GU_U, LW_I,                                     RS_D, GU_H, AL_T,    CT_N,   SH_S,
  KC_SCLN, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   MU_Z,
                                         KC_BSPC, LT(_RAISE, KC_TAB),  LT(_LOWER, KC_ENT), MT(LSFT, KC_SPC)
),

[_RAISE] = LAYOUT(
    KC_F1, KC_F2,   KC_F3,   KC_F4, KC_RCBR,                             KC_BSLS, KC_7, KC_8,   KC_9, KC_ASTR ,
    KC_F5, KC_F6, KC_F7, KC_F8, KC_DLR,                              KC_EQL,  KC_4, KC_5,   KC_6, KC_ENT  ,
    KC_F9, KC_10, KC_F11, KC_F12, KC_AMPR,                             KC_GRV,  KC_1, KC_2,   KC_3, KC_PLUS ,
                                               KC_TRNS,   KC_TRNS,    KC_TRNS, KC_0
),
[_LOWER] = LAYOUT(
    KC_ESC,  KC_QUES, KC_UNDR, KC_F1, KC_F2,                              KC_F3,  KC_F4,  KC_MINS, KC_SLSH, KC_BSPC ,
    KC_LSFT, KC_TAB,  KC_PGUP, KC_F5, KC_F6,                              KC_F7,  KC_F8,  KC_HOME, KC_LALT, KC_ENT  ,
    KC_CLCK, KC_SLCK, KC_PGDN, KC_F9, KC_F10,                             KC_F11, KC_F12, KC_END,  KC_INS,  KC_SLSH ,
                                             ____, ____,  KC_DELT, ADDDD
),
[_ADJUST] = LAYOUT(
    ____,    EXPLORER, KC_UP,   PREVTAB,  PREVWIN,                         NEXTWIN, NEXTTAB, ____,    ____, LOCKGUI,
    TASKMGR, KC_LEFT,  KC_DOWN, KC_RGHT,  UPTAB,                           DNTAB,   ____,    KC_LGUI, ____, CALTDEL,
    ____,    CLOSEGUI, ____,    CONPASTE, RESET,                           ____,    ____,    ____,    ____, ____,
                                                  ____, ____,  ____, ____
),
[_MUIS] = LAYOUT(
    ____, MU_BTN2, MU_UP, MU_BTN1, ____,                        ____, MU_BTN1, MU_UP, MU_BTN2, ____,
    ____, MU_LFT,  MU_DN, MU_RGHT, ____,                        ____, MU_LFT,  MU_DN, MU_RGHT, ____,
    ____, ____,    MU_WD, MU_WU,   ____,                        ____, MU_WU,   MU_WD, ____,   ____,
                                        ____, ____,  ____, ____
),
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
    case M:
      if (pressed) {
        layer_invert(_MOVE);
      }
      break;
  }

}
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
