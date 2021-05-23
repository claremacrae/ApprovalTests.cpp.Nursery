#!/bin/sh

# Must be run from the root of the project

CMAKE_DIR=/Applications/CMake.app/Contents/bin

PRESET=$1
#$CMAKE_DIR/cmake --list-presets
$CMAKE_DIR/cmake -S `pwd` --preset=$PRESET
$CMAKE_DIR/cmake --build  --preset=$PRESET
$CMAKE_DIR/ctest          --preset=$PRESET
