cmake_minimum_required(VERSION 3.16)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${GTEST_INCLUDE_DIRS}
)

add_executable(
    15PuzzleTest
    PanelTest.cc
    BoardTest.cc
)
# gtest_add_tests(
#     TARGET
#     15PuzzleTest
# )

target_link_libraries(
    15PuzzleTest
    15Puzzle
    GTest::GTest
    GTest::Main
)
