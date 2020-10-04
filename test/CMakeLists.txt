cmake_minimum_required(VERSION 3.18)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(
    GridTest grid_test.cc
)
target_link_libraries(
    GridTest 15Puzzle GTest::GTest GTest::Main
)
include_directories(
    ${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS}
)
gtest_add_tests(
    TARGET GridTest
)
