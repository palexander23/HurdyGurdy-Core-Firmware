/**
 * @file    tusb_config.h
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   A file used to configure the TinyUSB library.
 *          Contains constant definitions and preprocessor switches to configure library and interface.
 * @copyright Copyright (c) 2022
 */

#ifndef TUSB_CONFIG_H_
#define TUSB_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

#define BOARD_DEVICE_RHPORT_SPEED OPT_MODE_HIGH_SPEED
#define CFG_TUSB_RHPORT0_MODE (OPT_MODE_DEVICE | BOARD_DEVICE_RHPORT_SPEED)
#define CFG_TUD_ENDPOINT0_SIZE 64

#define CFG_TUD_CDC 1
#define CFG_TUD_MSC 0
#define CFG_TUD_HID 0
#define CFG_TUD_MIDI 1
#define CFG_TUD_VENDOR 0

#define CFG_TUD_CDC_RX_BUFSIZE (TUD_OPT_HIGH_SPEED ? 512 : 64)
#define CFG_TUD_CDC_TX_BUFSIZE (TUD_OPT_HIGH_SPEED ? 512 : 64)

#define CFG_TUD_MIDI_RX_BUFSIZE (TUD_OPT_HIGH_SPEED ? 512 : 64)
#define CFG_TUD_MIDI_TX_BUFSIZE (TUD_OPT_HIGH_SPEED ? 512 : 64)

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // TUSB_CONFIG_H_

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
