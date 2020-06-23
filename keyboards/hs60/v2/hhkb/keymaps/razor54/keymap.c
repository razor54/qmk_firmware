/* Copyright 2018 Yiancar
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

enum {
    CT_CLN = 0,
    TD_ONE_EXC,
    TD_SPC_ENT,
    TD_BACKSPACE,
    TD_SEVEN,
    TD_FOUR,
    TD_EIGHT,
    TD_NINE,
    TD_ZERO
};

void dance_finished_back_space (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        register_code (KC_RGUI);
        register_code (KC_BSPACE);
    } else if (state->count == 2) {
        register_code (KC_RALT);
        register_code (KC_BSPACE);
    } else {
        register_code (KC_BSPACE);
    }
}

void dance_reset_back_space (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        unregister_code (KC_RGUI);
        unregister_code (KC_BSPACE);
    } else if (state->count == 2) {
        unregister_code (KC_RALT);
        unregister_code (KC_BSPACE);
    } else {
        unregister_code (KC_BSPACE);
    }

}

void dance_finished_shift (qk_tap_dance_state_t *state, void *user_data, uint16_t kc) {
    if (state->count == 2) { 
        register_code (KC_RSFT);
        register_code (kc);
    } else {
        register_code (kc);
    }
}

void dance_reset_shift (qk_tap_dance_state_t *state, void *user_data, uint16_t kc) {
    if (state->count == 2) {
        unregister_code (KC_RSFT);
        unregister_code (kc);
    } else {
        unregister_code (kc);
    }
}

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_SCLN);
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_SCLN);
}

void dance_one_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_1);
}

void dance_one_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_1);
}

void dance_four_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_4);
}

void dance_four_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_4);
}
void dance_seven_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_7);
}

void dance_seven_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_7);
}
void dance_eight_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_8);
}

void dance_eight_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_8);
}
void dance_nine_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_9);
}

void dance_nine_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_9);
}
void dance_zero_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_finished_shift (state, user_data, KC_0);
}

void dance_zero_reset (qk_tap_dance_state_t *state, void *user_data) {
    dance_reset_shift (state, user_data, KC_0);
}

// All tap dance functions go here.
qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
    [TD_ONE_EXC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_one_finished, dance_one_reset),
    [TD_SEVEN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_seven_finished, dance_seven_reset),
    [TD_FOUR] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_four_finished, dance_four_reset),
    [TD_EIGHT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_eight_finished, dance_eight_reset),
    [TD_NINE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_nine_finished, dance_nine_reset),
    [TD_ZERO] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_zero_finished, dance_zero_reset),

    [TD_BACKSPACE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_finished_back_space, dance_reset_back_space),
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE (KC_SPC, KC_ENT)
};

//This is the HHKB version of the PCB

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_hhkb( /* Base */
            KC_ESC,   TD(TD_ONE_EXC),     KC_2,  KC_3,  TD(TD_FOUR),  KC_5,  KC_6,  TD(TD_SEVEN),  TD(TD_EIGHT),  TD(TD_NINE),     TD(TD_ZERO),        KC_MINS,                            KC_EQL,  KC_GRV,  KC_BSLS,\
            KC_TAB,   KC_Q,     KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,     KC_P,        KC_LBRC,                            KC_RBRC,          TD(TD_BACKSPACE),\
            KC_LCTL,  KC_A,     KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,     TD(CT_CLN),  KC_QUOT,                            KC_ENT,          \
            KC_LSFT,            KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,      KC_SLSH,                            KC_RSFT,            MO(1),\
            KC_LCTL,  KC_LGUI,  KC_LALT,                TD(TD_SPC_ENT),                                 KC_RCTL,     KC_RALT,               KC_RCTL          ),

    [1] = LAYOUT_60_hhkb( /* FN */
            RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_TRNS,  KC_TRNS,\
            KC_TRNS, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,   ES_DEC,  ES_INC,   KC_UP,    KC_TRNS,           KC_DEL, \
            KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,  KC_PGUP, KC_LEFT,  KC_RGHT,  KC_TRNS,         \
            KC_TRNS,          TG(2),   S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS,  KC_END,  KC_PGDN,  KC_DOWN,  KC_TRNS,           KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,                                        KC_TRNS,  KC_LOCK,  KC_TRNS         ),

    [2] = LAYOUT_60_hhkb( /* VIM Mode */
            TG(2),   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,  KC_TRNS,  KC_ENT,   KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN,  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,          \
            KC_TRNS,          KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,                                         KC_TRNS,  KC_TRNS,            KC_TRNS          ),

    [3] = LAYOUT_60_hhkb( /* Empty for dynamic keymaps */
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,            KC_TRNS,          \
            KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
            KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,                                        KC_TRNS,  KC_TRNS,            KC_TRNS          ),
};

void matrix_init_user(void) {
    //user initialization
}

void matrix_scan_user(void) {
    //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
