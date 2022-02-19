#!/bin/bash

let errors=0

for file in src/*.c* src/*.h*;
do 
    case $file in *FreeRTOS*) continue;; esac
    echo "Checking $file..."
    clang-format --Werror --dry-run $file || let errors=1
done;

exit $errors