#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    FNCT,  // Function keys
    MDIA,  // Media keys + Arrows
    GAME,  // Gaming
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4   |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |   ]    |
 * |--------+------+------+------+-------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R   |   T  |~FNCT~|           |~GAME~|   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+-------+------|      |           |      |------+------+------+------+------+--------|
 * | RCtl   |   A  |   S  |   D  |   F   |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / Cmd |
 * |--------+------+------+------+-------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift | Z/Ctl|   X  |   C  |   V   |   B  |      |           |      |   N  |   M  |   ,  |   .  |//RCtl| RShift |
 * `--------+------+------+------+-------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/FN|  '"  | LAlt | LAlt |Cmd/Esc|                                       | RAlt |   [  |   ]  |   \  |~FNCT~|
 //  `-----------------------------------'                                       `----------------------------------'
 //                                       ,-------------.       ,-------------.
 //                                       | App  | LGui |       | Alt  |Ctl/Esc|
 //                                ,------|------|------|       |------+--------+------.
 //                                |      |      | Home |       | PgUp |        |      |
 //                                | BSpc |  Tab |------|       |------|  Enter | Spc  |
 //                                |      |~MDIA~| End  |       | PgDn | ~MDIA~ |      |
 //                                `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
//,-----------------------------------------------------------------------------------------.      ,-----------------------------------------------------------------------------------.
  KC_GRAVE,        KC_1,        KC_2,          KC_3,          KC_4,    KC_5,    KC_6,                 KC_7,         KC_8,   KC_9,    KC_0,   KC_MINS,  KC_EQL,          KC_RBRC,
//|--------------+------------+------------+----------+--------------+-------+--------------|      |-------------+--------+--------+--------+--------+----------------+----------------|
  KC_DEL,          KC_Q,        KC_W,          KC_E,          KC_R,    KC_T,    TG(FNCT),             TG(GAME),     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC,
//|--------------+------------+------------+----------+--------------+-------+--------------|      |-------------+--------+--------+--------+--------+----------------+----------------|
  KC_RCTL,         KC_A,        KC_S,          KC_D,          KC_F,    KC_G,                                        KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,         GUI_T(KC_QUOT),
//|--------------+------------+------------+----------+--------------+-------|              |      |             |--------+--------+--------+--------+----------------+----------------|
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,          KC_V,    KC_B,  ALL_T(KC_NO),         MEH_T(KC_NO),   KC_N,   KC_M,   KC_COMM,  KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
//|--------------+------------+------------+----------+--------------+-------+--------------'      `-------------+--------+--------+--------+--------+----------------+----------------|
  LT(FNCT,KC_GRV), KC_QUOT,     KC_LALT,       KC_LALT, GUI_T(KC_ESC),                                                     KC_RALT, KC_LBRC, KC_RBRC,  KC_BSLS,          MO(FNCT),
//`--------------+------------+------------+----------+--------------'                                                   `------------------------------------------------------------'

//                                                         ,---------------------------.     ,--------------------------.
                                                              ALT_T(KC_APP),  KC_LGUI,         KC_LALT,  CTL_T(KC_ESC),
//                                                 ,-------+----------------+----------|     |---------+----------------+--------.
                                                                              KC_HOME,         KC_PGUP,
//                                                 |       |                |----------|     |---------|                |        |
                                                    KC_BSPC, LT(MDIA, KC_TAB), KC_END,          KC_PGDN, LT(MDIA, KC_ENT),  KC_SPC
//                                                 `-------+----------------+----------'     `---------+----------------+--------'
),
/* Keymap 1: Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      | Version|
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |   0  |    . |   ±  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      | ***  |       | Hue+ |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  *   |       | Hue- |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FNCT] = LAYOUT_ergodox_pretty(
//,--------------------------------------------------------------.   ,------------------------------------------------------------.
    KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,   KC_TRNS,
//|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+------+-------+-------+--------+-----------|
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_7,  KC_8,   KC_9,  KC_TRNS,  KC_TRNS,
//|--------+--------+--------+--------+--------+--------+--------|   |-------+--------+------+-------+-------+--------+-----------|
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_4,  KC_5,   KC_6,  KC_TRNS,   VRSN,
//|--------+--------+--------+--------+--------+--------|        |   |       |--------+------+-------+-------+--------+-----------|
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_1,  KC_2,   KC_3,  KC_TRNS,  KC_TRNS,
//|--------+--------+--------+--------+--------+--------+--------'   `-------+--------+-------+------+-------+--------+-----------'
    EE_CLR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0, KC_DOT,KC_PMNS, KC_TRNS,  KC_TRNS,
// `-------------------------------------------'                                      `------------------------------------------'

//                                          ,--------+-----------.   ,---------+---------.
                                              RGB_MOD,  KC_TRNS,       RGB_TOG,  RGB_M_P,
//                                  ,-------+--------+-----------|   |---------+---------+-------.
                                                        RGB_VAI,       RGB_HUI,
//                                  |       |        |-----------|   |---------|         |       |
                                     KC_TRNS, KC_TRNS,  RGB_VAD,       RGB_HUD,  KC_TRNS, KC_TRNS
//                                  `-------+--------+-----------'   `---------+---------+-------'
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Home |  Up  |  End |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
//,-------------------------------------------------------------.   ,--------------------------------------------------------------.
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//|-------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
   KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_HOME,  KC_UP,  KC_END,  KC_TRNS, KC_TRNS,
//|-------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
   KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_LEFT, KC_DOWN,KC_RIGHT, KC_TRNS, KC_MPLY,
//|-------+--------+--------+--------+--------+--------|        |   |        |--------+--------+--------+--------+--------+--------|
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
//|-------+--------+--------+--------+--------+--------+--------'   `--------+--------+--------+--------+--------+--------+--------'
   KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
// `-------------------------------------------'                                      `-------------------------------------------'

//                                           ,------------------.   ,----------------.
                                              KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
//                                   ,-------+--------+---------|   |-------+--------+--------.
                                                        KC_TRNS,     KC_TRNS,
//                                   |       |        |---------|   |-------|        |        |
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
//                                   `-------+--------+---------'   `---------+------+--------'
),
/* Keymap 3: Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |   ]    |
// |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   7  |           |      |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   8  |           | Play |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//RCtl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   h  |   j  |   k  |   l  | LAlt |                                       | RAlt |   [  |   ]  |   \  |~FNCT~|
 //  `----------------------------------'                                       `----------------------------------'
 //                                       ,-------------.       ,-------------.
 //                                       |   9  |   0  |       | RAlt |  Esc |
 //                                ,------|------|------|       |------+--------+------.
 //                                |      |      | Home |       | PgUp |        |      |
 //                                | Space| Enter|------|       |------|  Tab   | Bspc |
 //                                |      |      | End  |       | PgDn |        |      |
 //                                `--------------------'       `----------------------'
 */
[GAME] = LAYOUT_ergodox_pretty(
//,--------------------------------------------------------.      ,----------------------------------------------------------------.
  KC_ESC,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,  KC_6,          KC_7,    KC_8,   KC_9,   KC_0,  KC_MINS,  KC_EQL,    KC_RBRC,
//|---------+-------+-------+-------+-------+------+-------|      |--------+-------+-------+-------+--------+----------+-----------|
  KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_7,         KC_TRNS,  KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,      KC_LBRC,
//|---------+-------+-------+-------+-------+------+-------|      |--------+-------+-------+-------+--------+----------+-----------|
  KC_LCTL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,   KC_QUOT,
//|---------+-------+-------+-------+-------+------|       |      |        |-------+-------+-------+--------+----------+-----------|
  KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_8,         KC_MPLY,  KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
//|---------+-------+-------+-------+--------+-----+-------'      `--------+-------+-------+-------+--------+----------+-----------|
     KC_H,    KC_J,   KC_K,   KC_L,  KC_LALT,                                       KC_RALT, KC_LBRC, KC_RBRC, KC_BSLS,  MO(FNCT),
//`---------+-------+-------+-------+--------'                                     `-----------------------------------------------'

//                                    ,--------------------.      ,------------------.
                                         KC_9,      KC_0,           KC_RALT,  KC_ESC,
//                            ,-------+--------+-----------|      |---------+--------+--------.
                                                  KC_HOME,          KC_PGUP,
//                            |       |        |-----------|      |---------|        |        |
                               KC_SPC,  KC_END,    KC_END,          KC_PGDN,  KC_ENT,  KC_BSPC
//                            `-------+--------+-----------'      `---------+--------+--------'
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
