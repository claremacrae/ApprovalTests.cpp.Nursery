project(ApprovalTestsNursery)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME}
    ApprovalTestReporters.cpp
    ApprovalTestReporters.h
    AutoApproveIfMissingReporter.cpp
    AutoApproveIfMissingReporter.h
    AutoApproveReporter.cpp
    AutoApproveReporter.h
    ConsoleDiffReporter.cpp
    ConsoleDiffReporter.h
    ExtendApprovalTestName.cpp
    ExtendApprovalTestName.h
    FileUtilsAdditions.cpp
    FileUtilsAdditions.h
    FirstNFailuresReporter.cpp
    FirstNFailuresReporter.h
    ForegroundSystemLauncher.cpp
    ForegroundSystemLauncher.h
    ParallelFilesTestNamer.cpp
    ParallelFilesTestNamer.h
    )

target_link_libraries(${PROJECT_NAME} ApprovalTests)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /WX
        )
endif()
