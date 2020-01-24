project(ApprovalTestsNursery CXX)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE .)
target_link_libraries(${PROJECT_NAME} INTERFACE ApprovalTests::ApprovalTests)
