#include QMK_KEYBOARD_H

#include "../../atarifont.h"

#define FRAME_TIMEOUT (1000 / 20)

enum emu_modes { ATARI800_EMU, ALTIRRA, END_OF_EMU_LIST };

typedef union {
    uint32_t raw;
    struct {
        unsigned int emu_mode : 3;
        bool         rgb_layer_change : 1;
    };
} user_config_t;

user_config_t user_config;

static void at_writestr(char *str, bool rev);
static void at_writechar(int ch, bool rev);
static void at_home(void);
static void render_logo(void);
bool        render_frame(void);
bool        run_max = false;
bool        process_record_atari800_emu(uint16_t keycode, keyrecord_t *record);
bool        process_record_altirra_emu(uint16_t keycode, keyrecord_t *record);

/*
    Known issue: I can't find any way to send a CTRL-< (CLEAR) key code.
    But in every program I know of, it acts exactly the same as SHIFT-< (CLEAR)
    So I doubt it really matters, but I can tell the difference in a 1:1 key
    comparision to my 130XE
*/

enum layer_names { _NORM, _SHIFTED, _CTRL, _ALT };

// clang-format off
enum custom_keycodes {
    LOWER = SAFE_RANGE,

    AT_MENU,   // Atari MENU key
    AT_TURBO,  // Non-standard TURBO key, used by some emulators
    AT_RESET,  // Atari RESET key
    AT_OPTION, // Atari OPTION key
    AT_SELECT, // Atari SELECT key
    AT_START,  // Atari START key
    AT_HELP,   // Atari HELP key (XL/XE models)
    AT_BREAK,  // Atari BREAK key
    AT_FT,     // Function key for programming keyboard
    AT_PWR,    // Power key -- console dependent
    AT_CAPS,   // Atari CAPS key
    AT_INV,    // Atari INVERSE key
    AT_POWER,  // Atari/system power?
    KB_EMU,    // Change which emulator to target

    JS1_UP,
    JS1_DOWN,
    JS1_LEFT,
    JS1_RIGHT
};
// clang-format on

#define AT_CTRL MO(_CTRL)
#define AT_SFT MO(_SHIFTED) // The Atari shift key
#define FN_KEY MO(_ALT)
#define JS1_TRIG JS_0

/*
    No idea why I have to specify BOTH control keys, but "Atari800" emulator
    wouldn't detect things unless I did.  Go figure.
*/
#define R(x) RCTL(LCTL(x))

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NORM] = LAYOUT(
/*0*/   KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,
/*1*/   KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,
/*2*/   AT_CTRL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,
/*3*/   AT_SFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,
/*4*/   KC_9,       KC_0,       KC_LT,      KC_GT,      KC_BSPC,    AT_BREAK,   KC_O,       KC_P,       KC_MINS,
/*5*/   AT_INV,     KC_UP,      AT_CAPS,    KC_ASTR,    KC_PLUS,    KC_SCLN,    KC_L,       KC_EQUAL,   KC_ENT,
/*6*/   KC_SPACE,   FN_KEY,     KC_DOT,     KC_SLASH,   AT_SFT,     KC_LEFT,    KC_DOWN,    KC_RIGHT,
/*7*/   AT_SELECT,  AT_OPTION,  AT_RESET,   AT_HELP,    AT_MENU,    AT_POWER,   AT_TURBO,   AT_START,
/*8*/   JS1_UP,     JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  JS1_TRIG
    ),

 [_SHIFTED] = LAYOUT(

/*0*/   S(KC_ESC),  KC_EXLM,    KC_DQT,     KC_HASH,    KC_DLR,     KC_PERC,    KC_AMPR,    KC_QUOT,    KC_AT,
/*1*/   S(KC_TAB),  S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),    S(KC_U),    S(KC_I),
/*2*/   S(AT_CTRL), S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),
/*3*/   _______,    S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),    KC_LBRC,
/*4*/   KC_LPRN,    KC_RPRN,    KC_HOME,    S(KC_INS),  S(KC_DEL),  AT_BREAK,   S(KC_O),    S(KC_P),    KC_UNDS,
/*5*/   S(AT_INV),  KC_UP,      AT_CAPS,    KC_CIRC,    KC_BSLS,    KC_COLN,    S(KC_L),    KC_PIPE,    S(KC_ENT),
/*6*/   S(KC_SPACE),   _______, KC_RBRC,    KC_QUES,    AT_SFT,     KC_LEFT,    KC_DOWN,    KC_RIGHT,
/*7*/   AT_SELECT,  AT_OPTION,  AT_RESET,   AT_HELP,    AT_MENU,    AT_POWER,   AT_TURBO,   AT_START,
/*8*/   JS1_UP,     JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  JS1_TRIG
),

 [_CTRL] = LAYOUT(


/*0*/   R(KC_ESC),  R(KC_1),    R(KC_2),    R(KC_3),    R(KC_4),    R(KC_5),    R(KC_6),    R(KC_7),    R(KC_8),
/*1*/   R(KC_TAB),  R(KC_Q),    R(KC_W),    R(KC_E),    R(KC_R),    R(KC_T),    R(KC_Y),    R(KC_U),    R(KC_I),
/*2*/   _______,    R(KC_A),    R(KC_S),    R(KC_D),    R(KC_F),    R(KC_G),    R(KC_H),    R(KC_J),    R(KC_K),
/*3*/   _______,    R(KC_Z),    R(KC_X),    R(KC_C),    R(KC_V),    R(KC_B),    R(KC_N),    R(KC_M),    R(KC_COMMA),
/*4*/   R(KC_9),    R(KC_0),    KC_HOME,    KC_INS,     KC_DEL,     _______,    R(KC_O),    R(KC_P),    KC_UP,
/*5*/   R(AT_INV),  KC_UP,      AT_CAPS,    KC_RIGHT,   KC_LEFT,    R(KC_SCLN), R(KC_L),    KC_DOWN,    R(KC_ENT),
/*6*/   R(KC_SPACE),   _______, R(KC_DOT),  R(KC_SLASH),_______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,
/*7*/   AT_SELECT,  AT_OPTION,  AT_RESET,   AT_HELP,    AT_MENU,    AT_POWER,   AT_TURBO,   AT_START,
/*8*/   JS1_UP,     JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  JS1_TRIG
),

[_ALT] = LAYOUT(


/*0*/   A(KC_ESC),  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,
/*1*/   A(KC_TAB),  A(KC_Q),    A(KC_W),    A(KC_E),    A(KC_R),    A(KC_T),    A(KC_Y),    A(KC_U),    A(KC_I),
/*2*/   _______,    A(KC_A),    A(KC_S),    A(KC_D),    A(KC_F),    A(KC_G),    A(KC_H),    A(KC_J),    A(KC_K),
/*3*/   _______,    A(KC_Z),    A(KC_X),    A(KC_C),    A(KC_V),    A(KC_B),    A(KC_N),    A(KC_M),    A(KC_COMMA),
/*4*/   KC_F9,      KC_F10,     KC_F11,     KC_F12,     A(KC_DEL),  _______,    A(KC_O),    A(KC_P),    A(KC_UP),
/*5*/   A(AT_INV),  KB_EMU,     AT_CAPS,    _______,   _______,    A(KC_SCLN), A(KC_L),    KC_DOWN,    A(KC_ENT),
/*6*/   A(KC_SPACE),   _______, A(KC_DOT),  A(KC_SLASH), _______,    _______, _______, _______,
/*7*/   AT_SELECT,  AT_OPTION,  AT_RESET,   AT_HELP,    AT_MENU,    AT_POWER,   AT_TURBO,   AT_START,
/*8*/   JS1_UP,     JS1_DOWN,   JS1_LEFT,   JS1_RIGHT,  JS1_TRIG

)

};
// clang-format on

void keyboard_post_init_user(void) {
    // Call the keymap level matrix init.

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();

    // Set default layer, if enabled
    if (user_config.rgb_layer_change) {
    }

// Some OLEDs take a painfully long time to boot up. Plugging in a keyboard often results
// in the screen not powering up.
#ifdef OLED_ENABLE
    wait_ms(2000);
    oled_init(OLED_ROTATION_0);
#endif
}

#ifdef OLED_ENABLE

uint16_t startup_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
}

bool oled_task_user(void) {
    static uint16_t anim_timer = 0;

    // time for the next frame?
    if (timer_elapsed(anim_timer) > FRAME_TIMEOUT) {
        anim_timer = timer_read();
        return render_frame();
    }
    return false;
}

bool render_frame(void) {
    if (startup_timer + (1 * 1000) > timer_read()) {
        oled_set_cursor(0, 0);
        oled_clear();
        render_logo();
        return false;
    }

    oled_clear();
    oled_set_cursor(0, 0);
    at_home();

    switch (user_config.emu_mode) {
        case ATARI800_EMU:
            at_writestr(" ATARI800 EMU \n", true);
            break;
        case ALTIRRA:
            at_writestr(" ALTIRRA \n", true);
            break;
    }

    // Host Keyboard Layer Status
    at_writestr("LAYER: ", false);

    switch (get_highest_layer(layer_state)) {
        case _NORM:
            at_writestr("NORMAL\n", false);
            break;
        case _SHIFTED:
            at_writestr("SHIFTED\n", false);
            break;
        case _CTRL:
            at_writestr("CONTROL\n", false);
            break;
        case _ALT:
            at_writestr("ALT\n", false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            at_writestr("Undefined", false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    at_writestr(" ", false);

    at_writestr(led_state.num_lock ? " NUM " : "     ", led_state.num_lock);
    at_writestr(led_state.caps_lock ? " CAP " : "     ", led_state.caps_lock);
    at_writestr(led_state.scroll_lock ? " SCR " : "     ", led_state.scroll_lock);

    return false;
}

#endif

#ifdef JOYSTICK_ENABLE
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // x
    JOYSTICK_AXIS_VIRTUAL, // y
};
#endif

void handle_key(uint8_t code, bool pressed) {
    if (pressed) {
        register_code(code);
    } else {
        unregister_code(code);
    }
}

void handle_key16(uint16_t code, bool pressed) {
    if (pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef JOYSTICK_ENABLE
    int16_t precision_val = 127;

    switch (keycode) {
        case JS1_UP:
            joystick_set_axis(1, record->event.pressed ? -precision_val : 0);
            return false;
        case JS1_DOWN:
            joystick_set_axis(1, record->event.pressed ? precision_val : 0);
            return false;
        case JS1_LEFT:
            joystick_set_axis(0, record->event.pressed ? -precision_val : 0);
            return false;
        case JS1_RIGHT:
            joystick_set_axis(0, record->event.pressed ? precision_val : 0);
            return false;
    }
#endif

    switch (keycode) {
        case KB_EMU:
            if (record->event.pressed) {
                user_config.emu_mode += 1;
                if (user_config.emu_mode == END_OF_EMU_LIST) {
                    user_config.emu_mode = 0;
                }
                eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
                return true;
            }
    }

    switch (user_config.emu_mode) {
        case ATARI800_EMU:
            return process_record_atari800_emu(keycode, record);
        case ALTIRRA:
            return process_record_altirra_emu(keycode, record);
    }
    return true;
}

bool process_record_atari800_emu(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AT_MENU:
            handle_key(KC_F1, record->event.pressed);
            return true;
        case AT_TURBO:
            handle_key(KC_F12, record->event.pressed);
            return true;
        case AT_RESET:
            handle_key(KC_F5, record->event.pressed);
            return true;
        case AT_OPTION:
            handle_key(KC_F2, record->event.pressed);
            return true;
        case AT_SELECT:
            handle_key(KC_F3, record->event.pressed);
            return true;
        case AT_START:
            handle_key(KC_F4, record->event.pressed);
            return true;
        case AT_HELP:
            handle_key(KC_F6, record->event.pressed);
            return true;
        case AT_BREAK:
            handle_key(KC_F7, record->event.pressed);
            return true;
        case AT_PWR:
            handle_key16(S(KC_F5), record->event.pressed);
            return true;
        case AT_CAPS:
            handle_key(KC_CAPS_LOCK, record->event.pressed);
            return true;
        case AT_INV:
            handle_key(KC_GRAVE, record->event.pressed);
            run_max = true;
            return true;
        case AT_FT:
        default:
            return true;
    }
}

bool process_record_altirra_emu(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AT_MENU:
            // handle_key(KC_F1, record->event.pressed);
            return true;
        case AT_TURBO:
            handle_key(KC_F1, record->event.pressed);
            return true;
        case AT_RESET:
            handle_key(KC_F5, record->event.pressed);
            return true;
        case AT_OPTION:
            handle_key(KC_F4, record->event.pressed);
            return true;
        case AT_SELECT:
            handle_key(KC_F3, record->event.pressed);
            return true;
        case AT_START:
            handle_key(KC_F2, record->event.pressed);
            return true;
        case AT_HELP:
            handle_key(KC_F6, record->event.pressed);
            return true;
        case AT_BREAK:
            handle_key(KC_F7, record->event.pressed);
            return true;
        case AT_PWR:
            handle_key16(S(KC_F5), record->event.pressed);
            return true;
        case AT_CAPS:
            handle_key(KC_CAPS_LOCK, record->event.pressed);
            return true;
        case AT_INV:
            handle_key(KC_GRAVE, record->event.pressed);
            run_max = true;
            return true;
        case AT_FT:
        default:
            return true;
    }
}

/*
F1 = Scroll quickly through a listing
F2 = Start Console key
F3 = Select Console key
F4 = Option Console key
F5 = Warm Reset
F7 = Break out of a listing
F8 = Pause a listing
F9 = Pause activity
F10 = Freeze listing
*/

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

#ifdef DOTHIS
uint8_t save_data_direction;
uint8_t save_port;

uint8_t ddrb;
uint8_t portb;

int  show_led(void);
void CS_HIGH(void);
void CS_LOW(void);
void INIT_PORT(void);
void enable_max7219_select(void);
void disable_max7219_select(void);
void max7219_clear(void);

void keyboard_post_init_kb(void) {}

void housekeeping_task_user(void) {
    if (run_max) {
        enable_max7219_select();
        show_led();
        disable_max7219_select();
        run_max = false;
    }
}

/*
  One MAX7219 connected to an 8x8 LED matrix.
 */

void enable_max7219_select() {
    save_data_direction = DDRF;
    save_port           = PORTF;

    ddrb  = DDRB;
    portb = PORTB;

    // Enable by sending them low
    PORTB &= ~(1 << PB1);
    PORTF &= ~(1 << PF7);
}

void disable_max7219_select() {
    PORTB |= (1 << PB1);
    PORTF |= (1 << PF7);

    PORTF = save_port;
    DDRF  = save_data_direction;

    PORTB = portb;
    DDRB  = ddrb;
}

void CS_HIGH() {
    PORTF |= (1 << PF6);
}

void CS_LOW() {
    PORTF &= ~(1 << PF6);
}

void INIT_PORT() {
    DDRF |= (1 << PF5) | (1 << PF4) | (1 << PF6) | (1 << PF7) | (1 << PF1);
    DDRB |= (1 << PB1);
}

#    define CLK_HIGH() PORTF |= (1 << PF4)
#    define CLK_LOW() PORTF &= ~(1 << PF4)
//#define CS_HIGH() cs_high()
//#define CS_LOW() PORTF &= ~(1 << PF1)
#    define DATA_HIGH() PORTF |= (1 << PF5)
#    define DATA_LOW() PORTF &= ~(1 << PF5)
// #define INIT_PORT() DDRF |= (1 << PF5) | (1 << PF4) | (1 << PF6)| (1 << PF7)

// clang-format off

uint8_t smile[8] = {
        0b00000000,
        0b01100110,
        0b01100110,
        0b00011000,
        0b00011000,
        0b10000001,
        0b01000010,
        0b00111100};

uint8_t sad[8] = {
        0b00000000,
        0b01100110,
        0b01100110,
        0b00011000,
        0b00011000,
        0b00000000,
        0b00111100,
        0b01000010,
};
// clang-format on

void spi_send(uint8_t data) {
    uint8_t i;

    for (i = 0; i < 8; i++, data <<= 1) {
        CLK_LOW();
        if (data & 0x80)
            DATA_HIGH();
        else
            DATA_LOW();
        CLK_HIGH();
    }
}

void max7219_writec(uint8_t high_byte, uint8_t low_byte) {
    CS_LOW();
    spi_send(high_byte);
    spi_send(low_byte);
    CS_HIGH();
}

void max7219_clear(void) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        max7219_writec(i + 1, 0);
    }
}

void max7219_init(void) {
    INIT_PORT();
    // Decode mode: none
    max7219_writec(0x09, 0);
    // Intensity: 3 (0-15)
    max7219_writec(0x0A, 1);
    // Scan limit: All "digits" (rows) on
    max7219_writec(0x0B, 7);
    // Shutdown register: Display on
    max7219_writec(0x0C, 1);
    // Display test: off
    max7219_writec(0x0F, 0);
    max7219_clear();
}

uint8_t display[8];

void update_display(void) {
    uint8_t i;

    for (i = 0; i < 8; i++) {
        max7219_writec(i + 1, display[i]);
    }
}

void image(uint8_t im[8]) {
    uint8_t i;

    for (i = 0; i < 8; i++)
        display[i] = im[i];
}

void set_pixel(uint8_t r, uint8_t c, uint8_t value) {
    switch (value) {
        case 0: // Clear bit
            display[r] &= (uint8_t) ~(0x80 >> c);
            break;
        case 1: // Set bit
            display[r] |= (0x80 >> c);
            break;
        default: // XOR bit
            display[r] ^= (0x80 >> c);
            break;
    }
}

int show_led(void) {
    static bool mood = true;
    mood             = !mood;

    //   uint8_t i;

    max7219_init();
    if (mood) {
        image(sad);
    } else {
        image(smile);
    }
    update_display();

    CS_HIGH();

    return 0;

    // while (1) {
    //     image(sad);
    //     update_display();
    //     _delay_ms(500);
    //     image(smile);
    //     update_display();
    //     _delay_ms(500);

    //     // Invert display
    //     //  for (i = 0 ; i < 8*8; i++)
    //     //  {
    //     //      set_pixel(i / 8, i % 8, 2);
    //     //      update_display();
    //     //      _delay_ms(10);
    //     //  }
    //     _delay_ms(500);
    // }
}
#endif

// Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

#if 0
static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}
#endif

static int atari_x = 0;
static int atari_y = 0;
#define ATARI_FONT_WIDTH 8
#define ATARI_FONT_HEIGHT 8
#define ATARI_FONT_END 167

static void at_home(void) {
    atari_x = 0;
    atari_y = 0;
}

static void at_writestr(char *str, bool rev) {
    while (*str != '\0') {
        at_writechar((int)*str, rev);
        str++;
    }
}

static void at_writechar(int ch, bool rev) {
    if (ch > ATARI_FONT_END) {
        return;
    }

    if (ch == '\n') {
        atari_x = 0;
        atari_y += ATARI_FONT_HEIGHT;
        return;
    }

    int b;
    int w;
    int h;
    int color;
    for (w = 0; w < ATARI_FONT_WIDTH; w++) {
        b = atari_font[(ch * ATARI_FONT_HEIGHT) + w];
        for (h = ATARI_FONT_WIDTH; h >= 0; h--) {
            color = rev ? !((b >> h) & 1) : ((b >> h) & 1);
            oled_write_pixel(atari_x + w, atari_y + h, color);
        }
    }
    atari_x += ATARI_FONT_WIDTH;
}
