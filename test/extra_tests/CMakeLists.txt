add_executable(extra_tests_exe
    test_extra.c
    ../../src/extra.cpp
)

target_include_directories(extra_tests_exe PUBLIC
    ../../src
)

target_link_libraries(extra_tests_exe
    Unity
)

link_directories(../../src)

add_test(extra_tests extra_tests_exe)
