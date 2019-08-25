project(ApprovalTestsNursery_Catch2_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
        main.cpp
        CatchReporterTests.cpp
        CIBuildOnlyReporterTests.cpp
        FileUtilsAdditionsTests.cpp
        TextDiffReporterTests.cpp
        CatchGeneratorExperiments.cpp
        )
target_include_directories(${PROJECT_NAME} PUBLIC ../third_party/ApprovalTests.cpp/ApprovalTests_Catch2_Tests)
target_link_libraries(${PROJECT_NAME} ApprovalTestsNursery)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            /WX
            )
endif ()
