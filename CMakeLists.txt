cmake_minimum_required(VERSION 3.16)
project(15Puzzle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -O3)

find_package(Qt6 REQUIRED COMPONENTS
  Core
  Quick
  QuickControls2
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/views/qml.qrc
  src/view_models/MainWindow.cpp
  src/models/Board.cpp
  src/models/Panel.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::QuickControls2
)
