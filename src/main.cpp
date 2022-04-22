/**
 * @file    main.cpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Main file for project, contains entry point and FreeRTOS Tasks
 * @copyright Copyright (c) 2022
 */

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include <stdio.h>

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "status_led.h"
#include "usb_interface.hpp"

#include "extra.hpp"

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

/**
 * @brief A FreeRTOS task to flash the on-board LED periodically
 *
 * @param param An Empty pointer as required by FreeRTOS
 */
void heartbeatTask(void* param);

/**
 * @brief A FreeRTOS task to test USB operations from within a FreeRTOS task
 *
 * @param param An Empty pointer as required by FreeRTOS
 */
void serialTask(void* param);

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

// FreeRTOS Tasks

void heartbeatTask(void* param)
{
    status_led_init();

    while (1) {
        status_led_set_high();
        vTaskDelay(1000);

        status_led_set_low();
        vTaskDelay(1000);
    }
}

/**
 * @brief Initializes FreeRTOS tasks and starts scheduler
 *
 * @return int Should never return
 */
int main()
{
    TaskHandle_t heartbeatTaskHdl = NULL;
    TaskHandle_t usbTaskHdl = NULL;

    uint32_t status;

    status = xTaskCreate(
        heartbeatTask,
        "Heartbeat",
        1024,
        NULL,
        tskIDLE_PRIORITY,
        &heartbeatTaskHdl);

    status = xTaskCreate(
        usbTask,
        "USB",
        1024,
        NULL,
        tskIDLE_PRIORITY + 1,
        &usbTaskHdl);

    vTaskStartScheduler();

    // SHOULD NOT REACH HERE
    // Flash status LED in obvious way

    uint32_t delay_counter = 0;

    status_led_init();

    for (;;) {
        status_led_set_high();

        // Short Delay
        while (delay_counter < 1000000) {
            delay_counter++;
        }

        status_led_set_low();

        // Short Delay
        while (delay_counter > 0) {
            delay_counter--;
        }
    }

    return 0;
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
