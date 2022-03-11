#!/bin/bash

set -e

# Configure output 
if [[ ! -d build_tests ]]
then
    cmake -S . -B build_tests/ -DTARGET_GROUP=test
fi

# Build the configuired test suites
cd build_tests && make -j9

# Run CTest
echo ""
echo "-------------------------------"
echo ""
ctest
