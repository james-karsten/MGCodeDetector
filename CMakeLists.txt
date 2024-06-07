cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(untitled src/main.cpp src/parser.cpp
        include/types.h include/macros.h include/language.h include/Conditionals_LCD.h include/Configuration_adv.h
include/Configuration.h include/millis_t.h)
