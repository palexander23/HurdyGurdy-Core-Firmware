# Package the Fake HAL into a library that can be imported into tests
add_library(Fake_HAL
    fake_hal_gpio.cpp
)

target_include_directories(Fake_HAL PUBLIC
    .
)
