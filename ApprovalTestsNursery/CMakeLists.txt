project(ApprovalTestsNursery)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME}
        reporters/ApprovalTestReporters.cpp
        reporters/ApprovalTestReporters.h
        reporters/CatchReporter.h
        reporters/ConsoleDiffReporter.h
        FileUtilsAdditions.h
        reporters/FirstNFailuresReporter.h
        ForegroundSystemLauncher.h
        reporters/TextDiffReporter.h
        )

# TODO Improve how Catch.hpp is found - ApprovalTests.cpp/ApprovalTests/Catch2Approvals.h requires a file call Catch.hpp
target_include_directories(${PROJECT_NAME} PUBLIC . ${ApprovalTestsDir}/ApprovalTests)

target_link_libraries(${PROJECT_NAME} ApprovalTests)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wno-unused-function
            )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            /WX
            /wd4505 # unreferenced local function has been removed
            )
endif ()
