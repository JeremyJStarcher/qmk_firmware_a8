#include QMK_KEYBOARD_H

enum layer_names {
    _NORM,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
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
#define AT_SFT XXXXXXX // The Atari shift key
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

    )
};
