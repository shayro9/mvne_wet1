cmake_minimum_required(VERSION 3.22)
project(mvne_wet1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mvne_wet1
        Team.h
        Team.cpp
        Player.h
        Player.cpp
        PlayerRank.h
        PlayerRank.cpp
        PlayerId.h
        PlayerId.cpp
        Tree.h
        worldcup23a1.h
        worldcup23a1.cpp
        main.cpp)

