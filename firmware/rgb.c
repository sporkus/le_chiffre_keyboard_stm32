#ifdef RGB_MATRIX_ENABLE
// LED index
// 9    10    2    3
//         1
//         0
//   8 7   6   5 4

led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
         {9,     9,    9,   9,    9,            3, 3, 3,    3,     3 },
         {10,    10,   10,  10,   10,           2, 2, 2,    2,     2 },
         {8,     8,    8,   8,    8,            4, 4, 4,    4,     4 },
         {NO_LED, NO_LED, 7, NO_LED,      6,    6, 6, 5, NO_LED, NO_LED, }
    },
    // LED Index to Physical Positon
    {
        { 128, 40 },
        { 128, 30 },
        { 166, 0 },
        { 255, 0 },
        { 255, 48 },
        { 178, 64 },
        { 128, 64 },
        { 77, 64 },
        { 0, 48 },
        { 0, 0 },
        { 115, 0 }
    },
    //  LED Index to Flag
    //  https://docs.qmk.fm/#/feature_rgb_matrix?id=flags
    { 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};

// Layer and Mods indicator
#define LED_CENTER_TOP 1
#define LED_CENTER_BOTTOM 0

#define _FRONT_VAL ((uint8_t)((uint16_t)rgb_matrix_get_val() * RGB_FRONT_BRIGHTNESS_SCALE / 10))

#define LAYER_R layer_colors[layer][0] * _FRONT_VAL / 255
#define LAYER_G layer_colors[layer][1] * _FRONT_VAL / 255
#define LAYER_B layer_colors[layer][2] * _FRONT_VAL / 255

#define MODS_ACTIVE(mods) \
    ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? _FRONT_VAL:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? _FRONT_VAL/4:0)
#define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
#define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
#define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

const uint8_t PROGMEM layer_colors[][3] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};

bool rgb_matrix_indicators_user(void) {
    #if defined(RGB_LAYER_INDICATOR_ENABLE)
    int layer = get_highest_layer(layer_state|default_layer_state);
    rgb_matrix_set_color(LED_CENTER_TOP, LAYER_R, LAYER_G, LAYER_B);
    #else
    rgb_matrix_set_color(LED_CENTER_TOP, 0, 0, 0);
    #endif

    #if defined(RGB_MODS_INDICATOR_ENABLE)
    rgb_matrix_set_color(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    #else
    rgb_matrix_set_color(LED_CENTER_BOTTOM, 0, 0, 0);
    #endif
    return true;
}

#endif
