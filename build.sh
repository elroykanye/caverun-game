#!/bin/bash

ARG=$1
mkdir ./build/
rm ./build/main.css
rm ./build/caverun
cp ./src/styles/main.css ./build

conan install . --output-folder=build --build=missing
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build .

if [ "$ARG" = "debug" ]
then
    gdb --directory="../src" ./caverun
else
    ./caverun
fi

cd ..
echo "Thanks for playing?"
