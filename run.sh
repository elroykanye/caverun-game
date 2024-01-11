#!/bin/bash

cd build

if [ "$1" = "debug" ]
then
    gdb --directory="../src" ./caverun
else
    ./caverun
fi

cd ..
