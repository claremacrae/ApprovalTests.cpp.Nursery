#!/bin/sh

cd ..

# clang first, as it's stricter, and I don't build it on windows
cd       cmake-clang-release
make $*
cd ..

cd       cmake-gcc-release
make $*
cd ..


