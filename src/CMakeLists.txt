cmake_minimum_required(VERSION 3.16)
set(
    SOURCE
    ./Grid.cc
    ./Panel.cc
    ./BoardManager.cc
)
add_library(
    15Puzzle STATIC
    ${SOURCE}
)
