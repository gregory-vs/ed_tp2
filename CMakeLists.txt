cmake_minimum_required(VERSION 3.23)
project(ed_tp2)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(ed_tp2
        src/main.cpp
        include/Sorting.h
        src/Sorting.cpp
        include/List.h
        src/List.cpp
        include/graph.h
        src/graph.cpp)
