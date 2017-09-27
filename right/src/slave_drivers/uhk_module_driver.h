#ifndef __SLAVE_DRIVER_UHK_MODULE_H__
#define __SLAVE_DRIVER_UHK_MODULE_H__

// Includes:

    #include "fsl_common.h"
    #include "crc16.h"

// Macros:

    #define UHK_MODULE_MAX_COUNT 3
    #define KEY_STATE_SIZE (LEFT_KEYBOARD_HALF_KEY_COUNT/8 + 1)
    #define MAX_PWM_BRIGHTNESS 0x64

// Typedefs:

    typedef enum {
        UhkModuleId_LeftKeyboardHalf,
        UhkModuleId_LeftAddon,
        UhkModuleId_RightAddon,
    } uhk_module_id_t;

    typedef enum {
        UhkModulePhase_RequestKeyStates,
        UhkModulePhase_ReceiveKeystates,
        UhkModulePhase_ProcessKeystates,
        UhkModulePhase_SetLedPwmBrightness,
        UhkModulePhase_SetTestLed,
    } uhk_module_phase_t;

    typedef struct {
        uint8_t ledPwmBrightness;
        bool isTestLedOn;
    } uhk_module_state_t;

// Variables:

    extern uhk_module_state_t UhkModuleStates[UHK_MODULE_MAX_COUNT];

// Functions:

    extern void UhkModuleSlaveDriver_Init(uint8_t uhkModuleId);
    extern status_t UhkModuleSlaveDriver_Update(uint8_t uhkModuleId);

#endif
