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
