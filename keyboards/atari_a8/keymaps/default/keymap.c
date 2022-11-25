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
/*0*/   AT_MENU,    AT_TURBO,   AT_RESET,   AT_OPTION,  AT_SELECT,  AT_START,   AT_HELP,    KC_ESC,     AT_SFT,
/*1*/   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_UP,       
/*2*/   KC_9,       KC_0,       KC_LT,      KC_GT,      KC_BSPC,    AT_BREAK,   KC_TAB,     KC_Q,       KC_DOWN,
/*3*/   KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_LEFT,
/*4*/   KC_P,       KC_MINS,    KC_EQUAL,   KC_ENT,     AT_CTRL,    KC_A,       KC_S,       KC_D,       KC_RIGHT,
/*5*/   KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_PLUS,    KC_N,
/*6*/   KC_PAST,    AT_CAPS,    AT_SFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_M,
/*7*/   JS2_UP,     JS2_TRIG,   JS2_DOWN,   JS2_LEFT,   JS2_RIGHT,  FN_KEY,     AT_INV,     KC_SPACE,   KC_COMMA,
/*8*/   JS1_UP,     JS1_TRIG,   JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  KC_DOT,     KC_SLASH

    )
};
