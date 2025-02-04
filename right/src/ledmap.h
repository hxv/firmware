#ifndef __LEDMAP_H__
#define __LEDMAP_H__

// Includes:

    #include "key_action.h"

// Typedefs:
    typedef enum {
        BacklightStrategy_Functional,
        BacklightStrategy_ConstantRGB,
    } backlight_strategy_t;

    typedef enum {
        KeyActionColor_None,
        KeyActionColor_Scancode,
        KeyActionColor_Modifier,
        KeyActionColor_Shortcut,
        KeyActionColor_SwitchLayer,
        KeyActionColor_SwitchKeymap,
        KeyActionColor_Mouse,
        KeyActionColor_Macro,
    } key_action_color_t;

    typedef enum {
        LedMapIndex_LeftSlot_LeftShift = 21,
        LedMapIndex_LeftSlot_IsoKey = 22,
    } led_map_index_t;

    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } rgb_t;

// Variables:

    extern rgb_t LedMap_ConstantRGB;

// Functions:

    void UpdateLayerLeds(void);
    void InitLedLayout(void);
    void SetLedBacklightStrategy(backlight_strategy_t newStrategy);

#endif
