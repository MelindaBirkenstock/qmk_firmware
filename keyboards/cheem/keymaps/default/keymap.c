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

// short.
#define KC_QUES LSFT(KC_SLSH)
#define KC_UNDR LSFT(KC_MINS)
#define MU_UP   KC_MS_UP
#define MU_DN   KC_MS_DOWN
#define MU_LFT  KC_MS_LEFT
#define MU_RGHT KC_MS_RIGHT
#define MU_BTN1 KC_MS_BTN1
#define MU_BTN2 KC_MS_BTN2
#define MU_WD   KC_MS_WH_DOWN
#define MU_WU   KC_MS_WH_UP

// thumb keys.
#define ALT_ENT   ALT_T(KC_ENT)
#define SFT_ESC   SFT_T(KC_ESC)

// home row mods.
#define CT_O RCTL_T(KC_O)
#define CT_N RCTL_T(KC_N)
#define SH_A RSFT_T(KC_A)
#define SH_S RSFT_T(KC_S)
#define AL_E RALT_T(KC_E)
#define AL_T RALT_T(KC_T)
#define GU_U RGUI_T(KC_U)
#define GU_H RGUI_T(KC_H)

// layer toggle.
#define LW_BSPC  LT(_LOWER, KC_BSPC)
#define RS_SPC   LT(_RAISE, KC_SPC)
#define RS_D     LT(_RAISE, KC_D)
#define LW_I     LT(_LOWER, KC_I)
#define MU_QUOT  LT(_MUIS, KC_QUOT)
#define MU_Z     LT(_MUIS, KC_Z)

// idk, man. not used, i guess.
#define RAISE    MO(_RAISE)
#define LOWER    MO(_LOWER)
#define ADDDD    MO(_ADJUST)
#define MUIS     MO(_MUIS)

// common shortcuts for windows and linux that i use.
#define NEXTTAB  LCTL(KC_PGDN)
#define PREVTAB  LCTL(KC_PGUP)
#define UPTAB    LCTL(LSFT(KC_PGUP))
#define DNTAB    LCTL(LSFT(KC_PGDN))
#define NEXTWIN  LALT(KC_TAB)
#define PREVWIN  LALT(LSFT(KC_TAB))
#define CALTDEL  LCTL(LALT(KC_DELT))
#define TASKMGR  LCTL(LSFT(KC_ESC))
#define EXPLORER LGUI(KC_E)
#define LOCKGUI  LGUI(KC_L)
#define CONPASTE LSFT(KC_INS)

#define CLOSEGUI LALT(KC_F4)

enum combos {
  COLON_COMMA,
  COMMA_DOT,
  DOT_P,
  L_R,
  R_C,
  C_G,
  Q_J,
  J_K,
  V_W,
  W_M
};

const uint16_t PROGMEM colon_comma_combo[] = {KC_SCLN, KC_COMM, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[]   = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_p_combo[]       = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM l_r_combo[]         = {KC_L, KC_R, COMBO_END};
const uint16_t PROGMEM r_c_combo[]         = {KC_R, KC_C, COMBO_END};
const uint16_t PROGMEM c_g_combo[]         = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM q_j_combo[]         = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM j_k_combo[]         = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM v_w_combo[]         = {KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM w_m_combo[]         = {KC_W, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COLON_COMMA] = COMBO(colon_comma_combo, KC_TAB),
  [COMMA_DOT]   = COMBO(comma_dot_combo,   KC_QUES),
  [DOT_P]       = COMBO(dot_p_combo,       KC_UNDR),
  [L_R]         = COMBO(l_r_combo,         KC_BSPC),
  [R_C]         = COMBO(r_c_combo,         KC_SLSH),
  [C_G]         = COMBO(c_g_combo,         KC_MINS),
  [Q_J]         = COMBO(q_j_combo,         LCTL(KC_W)),
  [J_K]         = COMBO(j_k_combo,         KC_DELT),
  [V_W]         = COMBO(v_w_combo,         KC_APP),
  [W_M]         = COMBO(w_m_combo,         KC_DELT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_SCLN, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L,
  SH_A,    CT_O,    AL_E,    GU_U, LW_I,                                     RS_D, GU_H, AL_T,    CT_N,   SH_S,
  MU_QUOT, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   MU_Z,
                                         LW_BSPC, SFT_ESC,  ALT_ENT, RS_SPC
),

[_RAISE] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                             KC_BSLS, KC_7, KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                              KC_EQL,  KC_4, KC_5,   KC_6, KC_ENT  ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                             KC_GRV,  KC_1, KC_2,   KC_3, KC_PLUS ,
                                               ADDDD,   ____,    ____, ____
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

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
