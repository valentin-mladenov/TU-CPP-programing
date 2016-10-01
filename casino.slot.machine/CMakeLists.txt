cmake_minimum_required(VERSION 3.5)
project(casino_slot_machine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(casino_slot_machine ${SOURCE_FILES})