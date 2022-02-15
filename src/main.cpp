#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "extra.hpp"

#define ONBOARD_LED_PIN 25

//******************************************//
//              FreeRTOS Tasks              //
//******************************************//

void heartbeatTask(void *param)
{
    gpio_init(ONBOARD_LED_PIN);
    gpio_set_dir(ONBOARD_LED_PIN, GPIO_OUT);

    while (1)
    {
        gpio_put(ONBOARD_LED_PIN, 1);
        vTaskDelay(1000);
        gpio_put(ONBOARD_LED_PIN, 0);
        vTaskDelay(1000);
    }
}

void serialTask(void *param)
{
    stdio_init_all();

    while (1)
    {
        printf("Hello World!\n");
        extra_print();
        vTaskDelay(200);
    }
}

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
    for (;;)
    {
        sleep_ms(1000);
    }
}