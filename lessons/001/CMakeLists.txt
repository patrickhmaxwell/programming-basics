cmake_minimum_required (VERSION 2.6)
project (Lesson01)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "output/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -g")

add_executable(upcase source/upcase.cpp)

