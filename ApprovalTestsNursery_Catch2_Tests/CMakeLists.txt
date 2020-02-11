project(ApprovalTestsNursery_Catch2_Tests)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
        main.cpp
        CatchReporterTests.cpp
        TextDiffReporterTests.cpp
        CatchGeneratorExperiments.cpp
        )
target_link_libraries(${PROJECT_NAME} ApprovalTestsNursery Catch2::Catch2)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

include(WarningsAsErrors)
