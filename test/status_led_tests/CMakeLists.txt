add_executable(status_led_tests_exe
    status_led_tests.c
    ../../src/status_led.cpp
)

target_include_directories(status_led_tests_exe PUBLIC
    ../../src
)

target_link_libraries(status_led_tests_exe
    Unity
    Fake_HAL
)

add_test(status_led_tests status_led_tests_exe)
