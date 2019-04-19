cmake_minimum_required(VERSION 3.14)
project(sbisolet)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE Foo_SOURCES "src/*.cpp")
file(GLOB_RECURSE Foo_HEADERS "src/*.h")

set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable(sbisolet ${Foo_SOURCES} main.cpp)
target_link_libraries(sbisolet sfml-system sfml-window sfml-graphics sfml-audio)
target_include_directories(sbisolet PRIVATE ${Foo_INCLUDE_DIRS})