cmake_minimum_required(VERSION 3.16)
project(15Puzzle)

set(CMAKE_CXX_FLAGS "-std=c++20")
add_compile_options(-Wall -O3)

# deprecatedな宣言の警告無効化（macOSではOpenGLが非推奨になっているため）
add_definitions(-Wno-deprecated-declarations)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory(src)
add_subdirectory(test)

add_executable(
    a.out
    src/main.cc
)
target_include_directories(
    a.out
    PRIVATE
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
)
target_link_libraries(
    a.out
    15Puzzle
    ${OPENGL_LIBRARIES}
    glfw # ${GLFW_LIBRARIES}だとfind_packageでうまく設定されてないようでエラーする
)
