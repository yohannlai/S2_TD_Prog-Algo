cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(TD03)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(exo1_2 src/main.cpp src/display.cpp)
add_executable(exo3 src/exo3.cpp src/display.cpp)
add_executable(exo4 src/exo4.cpp)