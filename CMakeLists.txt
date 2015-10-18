cmake_minimum_required(VERSION 3.3)
project(CPS305A2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    path.c
    path.h
    pathfinder.c
    README.md
    vector.c
    vector.h)

add_executable(CPS305A2 ${SOURCE_FILES})