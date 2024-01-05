#!/bin/bash

ARG=$1

conan install . --output-folder=build --build=missing
cd build
rm escapegame
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build .
cd ..

if [ "$ARG" = "debug" ]
then
    gdb --directory="./src" ./build/caverun
else
    ./build/escapegame
fi

echo "Thanks for playing?"
