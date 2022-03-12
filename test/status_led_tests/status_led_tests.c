/**
 * @file    test_unity_config.cpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Tests to check correct operation of Unity Test Framework
 * @copyright Copyright (c) 2022
 */

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------
#include "unity.h"

#include "status_led.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

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

void setUp() { }

void tearDown() { }

void testLEDInitializedOFF() {
    status_led_init();

    TEST_ASSERT_MESSAGE(fake_hal_gpio_pin_mode_arr[STATUS_LED_PIN] == GPIO_OUTPUT, "Pin Mode Not correctly set");
    TEST_ASSERT_MESSAGE(fake_hal_gpio_pin_val_arr[STATUS_LED_PIN] == 0, "Output Not Initialized to Zero");
}

void testLEDSequence() {
    status_led_init();

    TEST_ASSERT_MESSAGE(fake_hal_gpio_pin_val_arr[STATUS_LED_PIN] == 0, "LED did not start LOW");
    
    status_led_set_high();
    TEST_ASSERT_MESSAGE(fake_hal_gpio_pin_val_arr[STATUS_LED_PIN] == 1, "LED did not go HIGH");

    status_led_set_low();
    TEST_ASSERT_MESSAGE(fake_hal_gpio_pin_val_arr[STATUS_LED_PIN] == 0, "LED did not return LOW");
}


int main()
{
    UNITY_BEGIN();
    RUN_TEST(testLEDInitializedOFF);
    RUN_TEST(testLEDSequence);
    return UNITY_END();
}
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------