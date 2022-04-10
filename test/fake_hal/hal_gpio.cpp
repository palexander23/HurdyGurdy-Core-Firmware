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

#include <stdio.h>

#include "unity.h"

#include "hal_gpio.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

// None

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

// None

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
    printf("GPIO PIN %d Initialised", pin);
}

/**
 * @brief Set the specified pin as an output
 *
 * @param pin The pin to set as an output
 */
void hal_gpio_set_pin_output(uint32_t pin)
{
    printf("GPIO PIN %d set as OUTPUT", pin);
}

/**
 * @brief Set the specified pin HIGH
 *
 * @param pin The pin to set HIGH
 */
void hal_gpio_pin_high(uint32_t pin)
{
    printf("GPIO PIN %d set HIGH", pin);
}

/**
 * @brief Set the specified pin LOW
 *
 * @param pin The pin to set LOW
 */
void hal_gpio_pin_low(uint32_t pin)
{
    printf("GPIO PIN %d set LOW", pin);
}

#ifdef __cplusplus
}
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
