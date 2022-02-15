cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(hurdygurdy_core_firmware)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} INTERFACE
    src
)

# enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)


add_subdirectory(src)

pico_add_extra_outputs(${PROJECT_NAME})

## FreeRTOS ##
FILE(GLOB FreeRTOS_src FreeRTOS-Kernel/*.c)

add_library( FreeRTOS STATIC
    ${FreeRTOS_src}
    FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c
    FreeRTOS-Kernel/portable/MemMang/heap_4.c
)

target_include_directories( FreeRTOS PUBLIC
    FreeRTOS-Kernel/include
    src/
    FreeRTOS-Kernel/portable/GCC/ARM_CM0
)

## Link All Libraries ## 
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    FreeRTOS
)
