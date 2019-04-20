cmake_minimum_required(VERSION 3.8)

# disable testsuite if used via add_subdirectory()
if(NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif()

add_subdirectory(../ApprovalTests.cpp/ApprovalTests  build_approvals EXCLUDE_FROM_ALL)
# TODO Improve how Catch is found
include_directories(../ApprovalTests.cpp/lib)

project(ApprovalTests.cpp.Nursery)
add_subdirectory(ApprovalTestsNursery)

if (NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(ApprovalTestsNursery_Catch2_Tests)
endif()
