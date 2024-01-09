cmake_minimum_required(VERSION 3.16)
project(15Puzzle)

add_compile_options(-Wall -O3 -std=c++20)

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
