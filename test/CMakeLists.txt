# Bring the Fake HAL into the project scope
add_subdirectory(fake_hal)

# For every new test suite add a new subdirectory below
add_subdirectory(unity_framework_tests)
add_subdirectory(status_led_tests)
add_subdirectory(extra_tests)
