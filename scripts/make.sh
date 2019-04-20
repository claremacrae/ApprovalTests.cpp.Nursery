#!/bin/sh

cd ..

# cmake first, as it's stricter
cd       cmake-clang-release
make $*
cd ..

cd       cmake-gcc-release
make $*
cd ..


