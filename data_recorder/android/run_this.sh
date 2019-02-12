#!/bin/bash

clear

echo "This is an automated script for buiding recored for android"

make clean

cmake ../ -DCMAKE_SYSTEM_NAME=Android -DCMAKE_TOOLCHAIN_FILE=/home/vishal/android_tools/android-ndk-r19/build/cmake/android.toolchain.cmake -DANDROID_CPP_FEATURES=exceptions -DANDROID_PLATFORM=28 -DANDROID_ABI=arm64-v8a

cmake --build .

rm CMakeCache.txt

rm -r CMakeFiles/

rm cmake_install.cmake

rm Makefile
