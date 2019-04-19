cmake_minimum_required(VERSION 3.14)
project(sbisolet)

set(CMAKE_CXX_STANDARD 14)

add_executable(sbisolet main.cpp src/Scene.cpp src/Scene.h)
target_link_libraries(sbisolet sfml-system sfml-window sfml-graphics sfml-audio)