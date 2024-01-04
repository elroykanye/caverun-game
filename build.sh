#!/bin/bash

conan install . --output-folder=build --build=missing
cd build
rm escapegame
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build .
cd ..

./build/escapegame
