/**
 * @file    hal_status_led.h
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Interface for controlling status LED
 * @copyright Copyright (c) 2022
 */

#ifndef HAL_STATUS_LED_H_
#define HAL_STATUS_LED_H_

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
#define PIN_STATUS_LED 25

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
void hal_status_led_init();

/**
 * @brief Set the status led high
 *
 */
void hal_status_led_set_high();

/**
 * @brief Set the status led low
 *
 */
void hal_status_led_set_low();

//-----------------------------------------------------------------

#endif // HAL_STATUS_LED_H_

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
