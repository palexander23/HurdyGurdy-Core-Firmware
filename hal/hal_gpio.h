/**
 * @file    hal_gpio.h
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Interface for GPIO control
 * @copyright Copyright (c) 2022
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include <stdint.h>

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
 * @ Initialize the specified GPIO pin.
 *
 * @param pin The number of the GPIO pin to initialize.
 */
void hal_gpio_init_pin(uint32_t pin);

/**
 * @brief Set the specified pin as an output
 *
 * @param pin The pin to set as an output
 */
void hal_gpio_set_pin_output(uint32_t pin);

/**
 * @brief Set the specified pin HIGH
 *
 * @param pin The pin to set HIGH
 */
void hal_gpio_pin_high(uint32_t pin);

/**
 * @brief Set the specified pin LOW
 *
 * @param pin The pin to set LOW
 */
void hal_gpio_pin_low(uint32_t pin);

//-----------------------------------------------------------------

#endif // HAL_GPIO_H_

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
