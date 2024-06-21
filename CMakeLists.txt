cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(untitled
        src/main.cpp
        src/parser.cpp
        include/types.h
        include/macros.h
        include/language.h
        include/Conditionals_LCD.h
        include/Configuration_adv.h
        include/Configuration.h
        include/millis_t.h
        src/malicious-gcode-detector/GCodeSecurityDispatcher.cpp
        src/malicious-gcode-detector/GCodeSecurityDispatcher.h
        src/malicious-gcode-detector/temp/M104_M109/M104_M109.cpp
        src/malicious-gcode-detector/temp/TemperatureSecurity.cpp
        src/malicious-gcode-detector/temp/TemperatureSecurity.h
        src/malicious-gcode-detector/temp/M107/M107.cpp
        src/malicious-gcode-detector/temp/M106/M106.cpp
        src/malicious-gcode-detector/temp/M140/M140.cpp)

add_subdirectory(Google_tests)
#add_subdirectory(Google_tests/lib)