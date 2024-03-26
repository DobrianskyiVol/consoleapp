cmake_minimum_required(VERSION 3.26)
project(consoleapp)

set(CMAKE_CXX_STANDARD 17)

add_executable(consoleapp main.cpp
        Interface.cpp
        Interface.h)
