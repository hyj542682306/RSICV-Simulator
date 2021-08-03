cmake_minimum_required(VERSION 3.16)
project(code)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Ofast")
add_executable(code main.cpp)