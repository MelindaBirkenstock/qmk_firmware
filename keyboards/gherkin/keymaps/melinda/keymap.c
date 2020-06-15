#include QMK_KEYBOARD_H



enum combos_events {
  COMDOT_ESC,
  MW_SPACE,
  JK_BSPC,
  BM_ENTER,
  AO_SHIFT,
  NS_SHIFT,
  QJ_LCTRL,
  TAB_TJBAD,
  SLASH_RL,
  ZC_COPY,
  XV_PASTE,
  PUCK,
  MUHFUGGIN
};

const uint16_t PROGMEM com_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mw_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM bm_combo[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM ns_combo[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM qj_combo[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM tj_combo[] = {KC_DOT, KC_Y, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM puck_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_I, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM muh_combo[] = {KC_X, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMDOT_ESC] = COMBO(com_combo, KC_ESC),
  [MW_SPACE] = COMBO(mw_combo, KC_SPC),
  [JK_BSPC] = COMBO(jk_combo, KC_BSPC),
  [BM_ENTER] = COMBO(bm_combo, KC_ENT),
  [AO_SHIFT] = COMBO(ao_combo, KC_LSFT),
  [NS_SHIFT] = COMBO(ns_combo, KC_RSFT),
  [QJ_LCTRL] = COMBO(qj_combo, KC_LCTL),
  [TAB_TJBAD] = COMBO(tj_combo, KC_TAB),
  [SLASH_RL] = COMBO(slsh_combo, KC_SLSH),
  [PUCK] = COMBO(puck_combo, KC_QUES),
  [ZC_COPY] = COMBO_ACTION(copy_combo),
  [XV_PASTE] = COMBO_ACTION(paste_combo),
  [XB_PASTE] = COMBO_ACTION(muh_combo, KC_EQL)

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
  }

}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_3x10(LT(1,KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, LT(2,KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z),
	[1] = LAYOUT_ortho_3x10(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_7, KC_8, KC_9, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_TRNS),
	[2] = LAYOUT_ortho_3x10(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_MINUS, KC_PLUS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, SGUI_T(KC_PSCR), KC_LGUI, KC_Q, KC_D, KC_TRNS, KC_TRNS, KC_SLSH, KC_LCBR, KC_RCBR)
};
