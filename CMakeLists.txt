cmake_minimum_required(VERSION 3.10)
project(sbisolet)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE Sbisolet_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE Sbisolet_HEADERS "${PROJECT_SOURCE_DIR}/src/*.h")

set (Sbisolet_INCLUDE_DIRS "")
foreach (_headerFile ${Sbisolet_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Sbisolet_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Sbisolet_INCLUDE_DIRS)


add_executable(sbisolet ${Sbisolet_SOURCES} main.cpp)

target_link_libraries(sbisolet sfml-system sfml-window sfml-graphics sfml-audio)
target_include_directories(sbisolet PRIVATE ${Sbisolet_INCLUDE_DIRS})
