cmake_minimum_required(VERSION 3.17)
project(skip_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(skip_list src/main.cpp src/skip_list.h src/linked_list.h)