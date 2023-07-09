#include QMK_KEYBOARD_H

enum layer_names {
    _NORM,
    _SHIFTED
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,

    AT_MENU,
    AT_TURBO,
    AT_RESET,
    AT_OPTION,
    AT_SELECT,
    AT_START,
    AT_HELP,
    AT_BREAK,
    AT_FT,     // The function key
    AT_PWR     // Power
};


//_______, KC_HOME, XXXXXXX, 

#define AT_MENU XXXXXXX
#define AT_TURBO XXXXXXX
#define AT_RESET XXXXXXX
#define AT_OPTION XXXXXXX
#define AT_SELECT XXXXXXX
#define AT_START XXXXXXX
#define AT_HELP XXXXXXX
#define AT_BREAK XXXXXXX
#define AT_FT XXXXXXX     // The function key
#define AT_PWR XXXXXXX     // Power




#define AT_CTRL KC_LCTL // 
#define AT_SFT MO(_SHIFTED) // The Atari shift key
#define AT_UP XXXXXXX // Up arrow
#define AT_CAPS XXXXXXX // 
#define AT_INV XXXXXXX // 

#define JS1_UP XXXXXXX
#define JS1_DOWN XXXXXXX
#define JS1_LEFT XXXXXXX
#define JS1_RIGHT XXXXXXX
#define JS1_TRIG XXXXXXX

#define JS2_UP XXXXXXX
#define JS2_DOWN XXXXXXX
#define JS2_LEFT XXXXXXX
#define JS2_RIGHT XXXXXXX
#define JS2_TRIG XXXXXXX

#define FN_KEY XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NORM] = LAYOUT(

/*0*/   KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,
/*1*/   KC_9,       KC_0,       KC_LT,      KC_GT,      KC_BSPC,    KC_UP,      KC_LEFT,    KC_DOWN,    KC_RIGHT,
/*2*/   KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,
/*3*/   KC_O,       KC_P,       KC_MINS,    KC_EQUAL,   KC_ENT,     AT_HELP,    AT_RESET,   AT_OPTION,  AT_SELECT,
/*4*/   AT_CTRL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,
/*5*/   KC_L,       KC_SCLN,    KC_PLUS,    KC_PAST,    AT_CAPS,    AT_SELECT,  AT_PWR,     AT_MENU,    AT_TURBO,
/*6*/   AT_FT,      AT_SFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,
/*7*/   JS2_UP,     JS2_TRIG,   JS2_DOWN,   JS2_LEFT,   JS2_RIGHT,  KC_COMMA,   KC_DOT,     KC_SLASH,   AT_SFT,
/*8*/   JS1_UP,     JS1_TRIG,   JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  AT_INV,     AT_BREAK,   KC_SPACE

    ),

[_SHIFTED] = LAYOUT(

/*0*/   KC_ESC,     KC_EXLM,    KC_DQT,     KC_HASH,    KC_DLR,     KC_PERC,    KC_AMPR,    KC_QUOT,    KC_AT,
/*1*/   KC_LPRN,    KC_RPRN,    KC_HOME,    KC_INS,     KC_DEL,     KC_UP,      KC_LEFT,    KC_DOWN,    KC_RIGHT,
/*2*/   S(KC_TAB),  S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),    S(KC_U),    S(KC_I),
/*3*/   S(KC_O),    S(KC_P),    KC_UNDS,    KC_PIPE,    S(KC_ENT),  _______,    _______,    _______,    _______,
/*4*/   AT_CTRL,    S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),
/*5*/   S(KC_L),    KC_COLN,    KC_BSLS,    KC_CIRC,    AT_CAPS,    _______,    _______,    _______,    _______,
/*6*/   AT_FT,      _______,    S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),
/*7*/   _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_QUES,    _______,
/*8*/   _______,    _______,    _______,    _______,    _______,    S(AT_INV),  S(AT_BREAK), S(KC_SPACE)

    )

};


#ifdef OLED_ENABLE
uint16_t startup_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
}


bool oled_task_user(void) {
    oled_set_cursor(0, 0);

    // Host Keyboard Layer Status
    oled_write_P(PSTR(" Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _NORM:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SHIFTED:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif