cmake_minimum_required(VERSION 3.20)
project(cycle_code)

set(CMAKE_CXX_STANDARD 20)

add_executable(cycle_code main.cpp utilities/utilities.cpp headers/utilities.h utilities/coder.cpp headers/coder.h)
