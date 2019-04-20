#!/bin/sh

cd ..

mkdir -p cmake-gcc-release
cd       cmake-gcc-release
cmake -DCMAKE_C_COMPILER=/usr/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/bin/g++-7 ..
cd ..

mkdir -p cmake-clang-release
cd       cmake-clang-release
cmake -DCMAKE_C_COMPILER=/usr/bin/clang-6.0 -DCMAKE_CXX_COMPILER=/usr/bin/clang++-6.0 ..
cd ..


