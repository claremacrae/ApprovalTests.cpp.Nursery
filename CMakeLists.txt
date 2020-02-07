cmake_minimum_required(VERSION 3.11)

# disable testsuite if used via add_subdirectory()
if (NOT DEFINED PROJECT_NAME)
    set(NURSERY_NOT_SUBPROJECT ON)
endif ()

project(ApprovalTests.cpp.Nursery)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake/")

set(CMAKE_VERBOSE_MAKEFILE on)

add_subdirectory(dependencies)
add_subdirectory(ApprovalTestsNursery)

if (NURSERY_NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(ApprovalTestsNursery_Catch2_Tests)
endif ()
