cmake_minimum_required(VERSION 3.10)
project(AStarAlgorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(AStarAlgorithm Graph.c
        Graph.h
        FRANCE.MAP
        List.c
        List.h
        main.c
        status.c
        status.h
        tList.c)