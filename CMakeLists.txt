cmake_minimum_required(VERSION 3.8)
set(CMAKE_VERBOSE_MAKEFILE ON)

# disable testsuite if used via add_subdirectory()
if(NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif()

set(ApprovalTestsDir ${CMAKE_SOURCE_DIR}/third_party/ApprovalTests.cpp)
add_subdirectory(${ApprovalTestsDir}/ApprovalTests  build_approvals EXCLUDE_FROM_ALL)

project(ApprovalTests.cpp.Nursery)
add_subdirectory(ApprovalTestsNursery)

if (NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(ApprovalTestsNursery_Catch2_Tests)
endif()
