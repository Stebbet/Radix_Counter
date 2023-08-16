cmake_minimum_required(VERSION 3.26)
project(Radix_Counter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Radix_Counter main.cpp
        radix.cpp)
