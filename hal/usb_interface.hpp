/**
 * @file    usb_interface.hpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Interface for USB Code taken from USB examples.
 * @copyright Copyright (c) 2022
 */

#ifndef USB_INTERFACE_H_
#define USB_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------

/**
 * @brief FreeRTOS task containing all USB functionality
 *
 * @param param Empty parameter required for FreeRTOS
 */
void usbTask(void* param);

//-----------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // USB_INTERFACE_H_

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
