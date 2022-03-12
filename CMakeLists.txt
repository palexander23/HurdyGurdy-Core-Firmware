#######################################
## CMake Version 
#######################################
cmake_minimum_required(VERSION 3.13)

set(TARGET_GROUP production CACHE STRING "Group to build")

if(TARGET_GROUP STREQUAL production)
    message("####################################")
    message("## Setting Up Production Firmware...")
    message("####################################")

    #######################################
    ## Raspberry Pi Pico Setup
    #######################################

    # initialize pico-sdk from submodule
    # note: this must happen before project()
    include(pico-sdk/pico_sdk_init.cmake)

    project(hurdygurdy_core_firmware)

    # initialize the Raspberry Pi Pico SDK
    pico_sdk_init()

    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    #######################################
    ## Project Executable/SRC Definition 
    #######################################
    # Define project's main executable
    add_executable(${PROJECT_NAME} 
        src/main.cpp
    )

    target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/hal
    )

    add_subdirectory(src)
    add_subdirectory(hal)

    pico_add_extra_outputs(${PROJECT_NAME})

    # enable usb output, disable uart output
    pico_enable_stdio_usb(${PROJECT_NAME} 1)
    pico_enable_stdio_uart(${PROJECT_NAME} 0)

    #######################################
    ## FreeRTOS Definitions
    #######################################
    add_library( FreeRTOS STATIC
        FreeRTOS-Kernel/tasks.c
        FreeRTOS-Kernel/timers.c
        FreeRTOS-Kernel/queue.c
        FreeRTOS-Kernel/croutine.c
        FreeRTOS-Kernel/list.c
        FreeRTOS-Kernel/croutine.c
        FreeRTOS-Kernel/stream_buffer.c
        FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c
        FreeRTOS-Kernel/portable/MemMang/heap_4.c
    )

    target_include_directories( FreeRTOS PUBLIC
        FreeRTOS-Kernel/include
        src/
        FreeRTOS-Kernel/portable/GCC/ARM_CM0
    )

    #######################################
    ## Link libraries to executable
    #######################################
    target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        FreeRTOS
    )

elseif(TARGET_GROUP STREQUAL test)
    message("####################################")
    message("## Setting Up Testing...")
    message("####################################")

    project(hurdygurdy_core_firmware_tests)

    # Set a compile flag so files can switch off platform specific features
    add_compile_definitions(TEST)

    # Enable CTest for automatic gathering of test executables
    include(CTest)

    # Add the subdirectory containing the tests
    # A CMakeLists file in that directory will handle adding the tests
    add_subdirectory(test)

    # Make Unity source files available as a static library
    # This is accessible from all subdirectories
    add_library(Unity STATIC
        Unity/src/unity.c
    )

    target_include_directories(Unity PUBLIC
        Unity/src
    )

else()
    message(FATAL_ERROR "Geven TARGET_GROUP unknown")

endif()
