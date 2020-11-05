cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall")
project(15Puzzle)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
set(
    SOURCE
    src/Grid.cc
    src/Panel.cc
    src/BoardManager.cc
    src/GameManager.cc
    src/main.cc
)
add_executable(a.out ${SOURCE})
