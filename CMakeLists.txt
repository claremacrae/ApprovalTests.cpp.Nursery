cmake_minimum_required(VERSION 3.8)

# disable testsuite if used via add_subdirectory()
if(NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif()

set(ApprovalTestsDir "third_party/ApprovalTests.cpp")
add_subdirectory(${ApprovalTestsDir}/ApprovalTests  build_approvals EXCLUDE_FROM_ALL)
# TODO Improve how Catch.hpp is found - ApprovalTests.cpp/ApprovalTests/Catch2Approvals.h requires a file call Catch.hpp
include_directories(${ApprovalTestsDir}/lib)

project(ApprovalTests.cpp.Nursery)
add_subdirectory(ApprovalTestsNursery)

if (NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(ApprovalTestsNursery_Catch2_Tests)
endif()
