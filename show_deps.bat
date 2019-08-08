REM Taken from https://github.com/claremacrae/project_dependencies_viz#alternative-approaches---if-you-use-cmake
mkdir cmake-build-dot
cd    cmake-build-dot
cmake --graphviz=test.dot ..
dot -Tsvg test.dot -o test.svg
cd ..
