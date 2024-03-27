cmake_minimum_required(VERSION 3.26)
project(consoleapp)

set(CMAKE_CXX_STANDARD 17)

add_executable(consoleapp main.cpp
        Interface.cpp
        Interface.h
        Admin.cpp
        Admin.h
        User.cpp
        User.h
        Menu.cpp
        Menu.h
        Ordering.cpp
        Ordering.h)
