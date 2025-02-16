cmake_minimum_required(VERSION 3.30)
project(calendars)

set(CMAKE_CXX_STANDARD 26)

add_library(calendars STATIC src/calendar.cpp)

add_subdirectory(tests)