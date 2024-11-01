cmake_minimum_required(VERSION 3.29)
project(cv04_kod)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(insertion_sort.exe insertion_sort.cpp)
add_executable(merge_sort.exe merge_sort.cpp)
