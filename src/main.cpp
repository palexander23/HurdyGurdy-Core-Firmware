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

#include "hardware/gpio.h"
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "extra.hpp"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

/// The GPIO pin number corresponding to the on-board LED
#define ONBOARD_LED_PIN 25

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
    gpio_init(ONBOARD_LED_PIN);
    gpio_set_dir(ONBOARD_LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(ONBOARD_LED_PIN, 1);
        vTaskDelay(1000);

        gpio_put(ONBOARD_LED_PIN, 0);
        vTaskDelay(1000);
    }
}

void serialTask(void* param)
{
    stdio_init_all();

    while (1) {
        printf("Hello World!\n");
        extra_print();
        vTaskDelay(200);
    }
}

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

/**
 * @brief The entry point to the firmware
 *
 * Initializes FreeRTOS tasks and starts the scheduler.
 *
 * @return int Standard Return value for main.
 */
int main()
{
    TaskHandle_t heartbeatTaskHdl = NULL;
    TaskHandle_t serialTaskHdl = NULL;

    uint32_t status;

    status = xTaskCreate(
        heartbeatTask,
        "Heartbeat",
        1024,
        NULL,
        tskIDLE_PRIORITY,
        &heartbeatTaskHdl);

    status = xTaskCreate(
        serialTask,
        "Serial",
        1024,
        NULL,
        tskIDLE_PRIORITY + 1,
        &serialTaskHdl);

    vTaskStartScheduler();

    // SHOULD NOT REACH HERE
    for (;;) {
        sleep_ms(1000);
    }

    return 0;
}

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
