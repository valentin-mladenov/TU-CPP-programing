cmake_minimum_required(VERSION 3.6)
project(laptop_ood)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CLaptop.cpp CLaptop.h CLaptopShop.cpp CLaptopShop.h)
add_executable(laptop_ood ${SOURCE_FILES})
