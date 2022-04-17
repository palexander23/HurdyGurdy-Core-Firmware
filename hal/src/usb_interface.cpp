/**
 * @file    usb_interface.cpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Implementation of tasks for USB activities.
 *          Currently just a place for the example USB Code.
 * @copyright Copyright (c) 2022
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
#include "usb_interface.hpp"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"

#include "task.h"
#include "tusb.h"

#include "bsp/board.h"
#include "tusb_config.h"
#include "usb_descriptors.h"

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

/**
 * @brief Send a set of USB HID instructions to the host
 *
 * @param report_id TUSB PARAM
 * @param btn       TUSB PARAM
 */
static void send_hid_report(uint8_t report_id, uint32_t btn)
{
    // skip if hid is not ready yet
    if (!tud_hid_ready())
        return;

    switch (report_id) {
    case REPORT_ID_KEYBOARD: {
        // use to avoid send multiple consecutive zero report for keyboard
        static bool has_keyboard_key = false;

        if (btn) {
            uint8_t keycode[6] = { 0 };
            keycode[0] = HID_KEY_A;

            tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);
            has_keyboard_key = true;
        } else {
            // send empty key report if previously has key pressed
            if (has_keyboard_key)
                tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
            has_keyboard_key = false;
        }
    } break;

    case REPORT_ID_MOUSE: {
        int8_t const delta = 5;

        // no button, right + down, no scroll, no pan
        tud_hid_mouse_report(REPORT_ID_MOUSE, 0x00, delta, delta, 0, 0);
    } break;

    case REPORT_ID_CONSUMER_CONTROL: {
        // use to avoid send multiple consecutive zero report
        static bool has_consumer_key = false;

        if (btn) {
            // volume down
            uint16_t volume_down = HID_USAGE_CONSUMER_VOLUME_DECREMENT;
            tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &volume_down, 2);
            has_consumer_key = true;
        } else {
            // send empty key report (release key) if previously has key pressed
            uint16_t empty_key = 0;
            if (has_consumer_key)
                tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &empty_key, 2);
            has_consumer_key = false;
        }
    } break;

    case REPORT_ID_GAMEPAD: {
        // use to avoid send multiple consecutive zero report for keyboard
        static bool has_gamepad_key = false;

        hid_gamepad_report_t report = {
            .x = 0, .y = 0, .z = 0, .rz = 0, .rx = 0, .ry = 0, .hat = 0, .buttons = 0
        };

        if (btn) {
            report.hat = GAMEPAD_HAT_UP;
            report.buttons = GAMEPAD_BUTTON_A;
            tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));

            has_gamepad_key = true;
        } else {
            report.hat = GAMEPAD_HAT_CENTERED;
            report.buttons = 0;
            if (has_gamepad_key)
                tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));
            has_gamepad_key = false;
        }
    } break;

    default:
        break;
    }
}

// Every 10ms, we will sent 1 report for each HID profile (keyboard, mouse etc ..)
// tud_hid_report_complete_cb() is used to send the next report after previous one is complete
/**
 * @brief Every 10ms, we will sent 1 report for each HID profile (keyboard, mouse etc ..)
 *        tud_hid_report_complete_cb() is used to send the next report after previous one is complete
 *
 */
void hid_task(void)
{
    // Poll every 10ms
    const uint32_t interval_ms = 10;
    static uint32_t start_ms = 0;

    if (board_millis() - start_ms < interval_ms)
        return; // not enough time
    start_ms += interval_ms;

    uint32_t const btn = board_button_read();

    // Remote wakeup
    if (tud_suspended() && btn) {
        // Wake up host if we are in suspend mode
        // and REMOTE_WAKEUP feature is enabled by host
        tud_remote_wakeup();
    } else {
        // Send the 1st of report chain, the rest will be sent by tud_hid_report_complete_cb()
        send_hid_report(REPORT_ID_KEYBOARD, btn);
    }
}

// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
/**
 * @brief   Invoked when received GET_REPORT control request
 *          Application must fill buffer report's content and return its length.
 *          Return zero will cause the stack to STALL request
 * @param instance      TUSB Param
 * @param report_id     TUSB Param
 * @param report_type   TUSB Param
 * @param buffer        TUSB Param
 * @param reqlen        TUSB Param
 */

/**
 * @brief Invoked when sent REPORT successfully to host
 *        Application can use this to send the next report
 *        Note: For composite reports, report[0] is report ID
 * @param instance
 * @param report
 * @param len
 */
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const* report, uint8_t len)
{
    (void)instance;
    (void)len;

    uint8_t next_report_id = report[0] + 1;

    if (next_report_id < REPORT_ID_COUNT) {
        send_hid_report(next_report_id, board_button_read());
    }
}

/**
 * @brief   Invoked when received GET_REPORT control request
 *          Application must fill buffer report's content and return its length.
 *          Return zero will cause the stack to STALL request
 * @param instance      TUSB Param
 * @param report_id     TUSB Param
 * @param report_type   TUSB Param
 * @param buffer        TUSB Param
 * @param reqlen        TUSB Param
 * @return uint16_t     Returns 0
 */
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
    // TODO not Implemented
    (void)instance;
    (void)report_id;
    (void)report_type;
    (void)buffer;
    (void)reqlen;

    return 0;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
}

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

/**
 * @brief Invoked when device is mounted
 *
 */
void tud_mount_cb(void)
{
}

/**
 * @brief Invoked when device is unmounted
 *
 */
void tud_umount_cb(void)
{
}

/**
 * @brief Invoked when USB Bus is suspended
 *
 * @param remote_wakeup_en if host allow us  to perform remote wakeup
 */
void tud_suspend_cb(bool remote_wakeup_en)
{
}

/**
 * @brief Evoked when the bus is resumed
 *
 */
void tud_resume_cb()
{
}

/**
 * @brief FreeRTOS task containing all USB functionality
 *
 * @param param Empty parameter required for FreeRTOS
 */
void usbTask(void* param)
{
    tusb_init();

    while (1) {
        tud_task(); // tinyusb device task
        hid_task();
        vTaskDelay(1);
    }

    return;
}

#ifdef __cplusplus
}
#endif

//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------