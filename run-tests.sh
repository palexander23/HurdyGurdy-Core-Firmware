#!/bin/bash

# Clear build directory if it exists
rm -r build

# Configure output 
cmake -S . -B build/ -DTARGET_GROUP=test

# Build the configuired test suites
./build.sh

# Run CTest
echo ""
echo "-------------------------------"
echo ""
cd build && ctest
