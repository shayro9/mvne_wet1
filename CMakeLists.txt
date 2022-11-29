cmake_minimum_required(VERSION 3.22)
project(mvne_wet1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mvne_wet1
        Tree.h
        main.cpp
        LinkedList.h
        Team.h
        Team.cpp
        worldcup23a1.h
        worldcup23a1.cpp
        Player.h
        Player.cpp
        PlayerId.h
        PlayerId.cpp)

