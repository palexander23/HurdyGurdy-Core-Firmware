/**
 * @file    status_led.h
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Interface for controlling status LED
 * @copyright Copyright (c) 2022
 */

#ifndef STATUS_LED_H_
#define STATUS_LED_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------
#include "hal_gpio.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

/**
 * @brief The pin number for the status LED
 *
 */
#define STATUS_LED_PIN 25

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------
/**
 * @brief Initialize the status LED
 *
 */
void status_led_init();

/**
 * @brief Set the status led high
 *
 */
void status_led_set_high();

/**
 * @brief Set the status led low
 *
 */
void status_led_set_low();

//-----------------------------------------------------------------

#endif // STATUS_LED_H_

#ifdef __cplusplus
}
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
