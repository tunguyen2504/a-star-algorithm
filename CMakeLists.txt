cmake_minimum_required(VERSION 3.10)
project(PathFinder C)

set(CMAKE_C_STANDARD 99)

add_executable(PathFinder City.c
        City.h
        FRANCE.MAP
        List.c
        List.h
        main.c
        status.c
        status.h
        tList.c)