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

#define LAYER_R layer_colors[layer][0] * RGB_MATRIX_DEFAULT_VAL / RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define LAYER_G layer_colors[layer][1] * RGB_MATRIX_DEFAULT_VAL / RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define LAYER_B layer_colors[layer][2] * RGB_MATRIX_DEFAULT_VAL / RGB_MATRIX_MAXIMUM_BRIGHTNESS

#define MODS_ACTIVE(mods) \
    ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_MATRIX_DEFAULT_VAL:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_MATRIX_DEFAULT_VAL/4:0)
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

void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #ifdef RGB_MATRIX_LAYER_INDICATOR
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);
    /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
    #endif

    #ifdef RGB_MATRIX_MODS_INDICATOR
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
    #endif
}

#ifndef VIAL_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
    return false;
}
#endif

#ifdef VIAL_ENABLE
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
}
#endif

#endif
