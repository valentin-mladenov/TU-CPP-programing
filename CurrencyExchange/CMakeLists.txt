cmake_minimum_required(VERSION 3.6)
project(CurrencyExchange)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp CFXDayData.cpp CFXDayData.h stdafx.cpp stdafx.h CFXMonthData.cpp CFXMonthData.h)
add_executable(CurrencyExchange ${SOURCE_FILES})
