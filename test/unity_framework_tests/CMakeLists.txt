add_executable(unity_framework_tests_exe
    test_unity_framework.c
)

target_link_libraries(unity_framework_tests_exe
    Unity
)

add_test(unity_framework_tests unity_framework_tests_exe)
