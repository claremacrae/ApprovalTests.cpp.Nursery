#!/bin/sh

cd ..

cd       cmake-gcc-release
ctest $*
cd ..

cd       cmake-clang-release
ctest $*
cd ..


