cmake_minimum_required(VERSION 3.18)
set(
    SOURCE
    ./grid.cc
    ./panel.cc
    ./grid.cc
)
add_library(
    15Puzzle STATIC ${SOURCE}
)
