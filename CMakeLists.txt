cmake_minimum_required(VERSION 3.11)

# disable testsuite if used via add_subdirectory()
if (NOT DEFINED PROJECT_NAME)
    set(NURSERY_NOT_SUBPROJECT ON)
else()
    set(NURSERY_NOT_SUBPROJECT OFF)
endif ()

project(ApprovalTests.cpp.Nursery)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake/")

set(CMAKE_VERBOSE_MAKEFILE off)

add_subdirectory(dependencies)
add_subdirectory(ApprovalTestsNursery)
add_subdirectory(doc)

if (NURSERY_NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(ApprovalTestsNursery_Catch2_Tests)
endif ()

message("CMAKE_VERSION = ${CMAKE_VERSION}")
message("CMAKE_GENERATOR = ${CMAKE_GENERATOR}")
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
message("CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message("CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message("CMAKE_UNITY_BUILD = ${CMAKE_UNITY_BUILD}")
