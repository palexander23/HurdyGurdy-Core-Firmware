#!/bin/bash

set -e

# Configure output 
if [[ ! -d build_tests ]]
then
    cmake -S . -B build_tests/ -DTARGET_GROUP=test -GNinja
fi

# Build the configuired test suites
cd build_tests && ninja -j20

# Run CTest
echo ""
echo "-------------------------------"
echo ""
CTEST_OUTPUT_ON_FAILURE=1 ctest
