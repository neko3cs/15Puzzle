cmake_minimum_required(VERSION 3.16)
project(15Puzzle)

set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall")

add_subdirectory(src)
add_subdirectory(test)
add_executable(
    a.out
    src/main.cc
)

target_link_libraries(
    a.out
    15Puzzle
)
