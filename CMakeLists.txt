cmake_minimum_required(VERSION 3.30)
project(calendars)

set(CMAKE_CXX_STANDARD 26)

add_library(calendars STATIC src/calendar.cpp
        src/calendar.h
        src/gregorian_calendar.cpp
        src/gregorian_calendar.h)

add_subdirectory(tests)