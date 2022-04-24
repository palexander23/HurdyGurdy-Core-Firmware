/**
 * @file    src_name.cpp
 * @author  Author Name (author@email.com)
 * @brief   Source brief
 * @copyright Copyright (c) YEAR
 */

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "tusb.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

void cdc_task();

void midi_task();

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

void cdc_task()
{
    static char received_str[64] = "Chars Received: ";

    if (tud_cdc_available()) {
        char buf[64];
        uint32_t count = tud_cdc_read(buf, sizeof(buf));

        (void)count;

        tud_cdc_write(received_str, sizeof(received_str));
        tud_cdc_write(buf, count);
        tud_cdc_write("\n\r", 2);
        tud_cdc_write_flush();
    }

    return;
}

void midi_task()
{
    vTaskDelay(1);
}

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

/**
 * @brief FreeRTOS task containing all USB functionality
 *
 * @param param Empty parameter required for FreeRTOS
 */
void usbTask(void* param)
{
    tusb_init();

    while (1) {
        tud_task();
        midi_task();
        cdc_task();

        vTaskDelay(1);
    }
}

//-----------------------------------------------------------------

#ifdef __cplusplus
}
#endif

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------