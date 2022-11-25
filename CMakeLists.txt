cmake_minimum_required(VERSION 3.22)
project(mvne_wet1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mvne_wet1
        Tree.cpp
        Tree.h cmake-build-debug/PlayerRank.h PlayerRank.h Team.cpp PlayerRank.cpp)
