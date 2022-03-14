/**
 * @file    fake_hal_gpio.cpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Implementation of fake GPIO interface for unit testing
 * @copyright Copyright (c) YEAR
 */

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include "unity.h"

#include "hal_gpio.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

const char FAKE_HAL_GPIO_DESCRIPTOR_ARR[NUM_GPIO][256] = {
    "GPIO 00 - NOT ASSIGNED",
    "GPIO 01 - NOT ASSIGNED",
    "GPIO 02 - NOT ASSIGNED",
    "GPIO 03 - NOT ASSIGNED",
    "GPIO 04 - NOT ASSIGNED",
    "GPIO 05 - NOT ASSIGNED",
    "GPIO 06 - NOT ASSIGNED",
    "GPIO 07 - NOT ASSIGNED",
    "GPIO 08 - NOT ASSIGNED",
    "GPIO 09 - NOT ASSIGNED",
    "GPIO 10 - NOT ASSIGNED",
    "GPIO 11 - NOT ASSIGNED",
    "GPIO 12 - NOT ASSIGNED",
    "GPIO 13 - NOT ASSIGNED",
    "GPIO 14 - NOT ASSIGNED",
    "GPIO 15 - NOT ASSIGNED",
    "GPIO 16 - NOT ASSIGNED",
    "GPIO 17 - NOT ASSIGNED",
    "GPIO 18 - NOT ASSIGNED",
    "GPIO 19 - NOT ASSIGNED",
    "GPIO 20 - NOT ASSIGNED",
    "GPIO 21 - NOT ASSIGNED",
    "GPIO 22 - NOT ASSIGNED",
    "GPIO 23 - UNUSABLE",
    "GPIO 24 - UNUSABLE",
    "GPIO 25 - UNUSABLE",
    "GPIO 26 - NOT ASSIGNED",
    "GPIO 27 - NOT ASSIGNED",
    "GPIO 28 - NOT ASSIGNED",
};

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

gpio_pin_mode_t fake_hal_gpio_pin_mode_arr[NUM_GPIO] = { GPIO_UNINITIALIZED };

float fake_hal_gpio_pin_val_arr[NUM_GPIO] = { 0 };

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

/**
 * @ Initialize the specified GPIO pin.
 *
 * @param pin The number of the GPIO pin to initialize.
 */
void hal_gpio_init_pin(uint32_t pin)
{
    fake_hal_gpio_pin_mode_arr[pin] = GPIO_INPUT;
}

/**
 * @brief Set the specified pin as an output
 *
 * @param pin The pin to set as an output
 */
void hal_gpio_set_pin_output(uint32_t pin)
{
    fake_hal_gpio_pin_mode_arr[pin] = GPIO_OUTPUT;
}

/**
 * @brief Set the specified pin HIGH
 *
 * @param pin The pin to set HIGH
 */
void hal_gpio_pin_high(uint32_t pin)
{
    if (fake_hal_gpio_pin_mode_arr[pin] == GPIO_OUTPUT) {
        fake_hal_gpio_pin_val_arr[pin] = 1;
    } else {
        TEST_FAIL_MESSAGE("Attempt was made to set pin high when it was not set as GPIO_OUTPUT\n");
    }
}

/**
 * @brief Set the specified pin LOW
 *
 * @param pin The pin to set LOW
 */
void hal_gpio_pin_low(uint32_t pin)
{
    if (fake_hal_gpio_pin_mode_arr[pin] == GPIO_OUTPUT) {
        fake_hal_gpio_pin_val_arr[pin] = 0;
    } else {
        TEST_FAIL_MESSAGE("Attempt was made to set pin high when it was not set as GPIO_OUTPUT\n");
    }
}

#ifdef __cplusplus
}
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
