/**
 * @file    hal_gpio.h
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Interface matching the real HAL_GPIO hardware
 * @copyright Copyright (c) 2022
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include <stdint.h>

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

#define NUM_GPIO 29

extern const char FAKE_HAL_GPIO_DESCRIPTOR_ARR[NUM_GPIO][256];

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

typedef enum _gpio_pin_mode_t {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_ANALOG_IN,
    GPIO_ANALOG_OUT,
    GPIO_UNINITIALIZED,
} gpio_pin_mode_t;

//-----------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------

extern gpio_pin_mode_t fake_hal_gpio_pin_mode_arr[NUM_GPIO];

extern float fake_hal_gpio_pin_val_arr[NUM_GPIO];

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
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
