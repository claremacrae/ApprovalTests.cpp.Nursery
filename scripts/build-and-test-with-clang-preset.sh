#!/bin/sh

# Must be run from the root of the project

PRESET=$1
#/Applications/CMake.app/Contents/bin/cmake --list-presets
/Applications/CMake.app/Contents/bin/cmake -S `pwd` --preset=$PRESET
/Applications/CMake.app/Contents/bin/cmake --build  --preset=$PRESET
/Applications/CMake.app/Contents/bin/ctest          --preset=$PRESET
