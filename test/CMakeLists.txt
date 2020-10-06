cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(
    15PuzzleTest
    GridTest.cc
    PanelTest.cc
    BoardTest.cc
)
target_link_libraries(
    15PuzzleTest
    15Puzzle
    GTest::GTest
    GTest::Main
)
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${GTEST_INCLUDE_DIRS}
)
gtest_add_tests(
    TARGET
    15PuzzleTest
)
