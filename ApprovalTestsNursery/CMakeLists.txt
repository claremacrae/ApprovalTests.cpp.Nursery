project(ApprovalTestsNursery)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME}
    reporters/ApprovalTestReporters.cpp
    reporters/ApprovalTestReporters.h
    reporters/AutoApproveIfMissingReporter.cpp
    reporters/AutoApproveIfMissingReporter.h
    reporters/AutoApproveReporter.cpp
    reporters/AutoApproveReporter.h
    reporters/CatchReporter.cpp
    reporters/CatchReporter.h
    reporters/CIBuildOnlyReporter.cpp
    reporters/CIBuildOnlyReporter.h
    reporters/ConsoleDiffReporter.cpp
    reporters/ConsoleDiffReporter.h
    ExtendApprovalTestName.cpp
    ExtendApprovalTestName.h
    FileUtilsAdditions.cpp
    FileUtilsAdditions.h
    reporters/FirstNFailuresReporter.cpp
    reporters/FirstNFailuresReporter.h
    ForegroundSystemLauncher.cpp
    ForegroundSystemLauncher.h
    reporters/ParallelFilesTestNamer.cpp
    reporters/ParallelFilesTestNamer.h
    reporters/TextDiffReporter.cpp
    reporters/TextDiffReporter.h
    )

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} ApprovalTests)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wno-unused-function
        )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /WX
        /wd4505 # unreferenced local function has been removed
        )
endif()
