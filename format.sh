#!/bin/bash

for file in src/*.c* src/*.h*;
do 
    case $file in *FreeRTOS*) continue;; esac
    echo "Formatting $file..."
    clang-format -i $file
done;