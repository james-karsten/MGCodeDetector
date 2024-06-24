project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run InvalidGCodeParser.cpp
        ../src/malicious-gcode-detector/GCodeSecurityDispatcher.cpp
        ../src/malicious-gcode-detector/GCodeSecurityDispatcher.h
        ../src/malicious-gcode-detector/temp/M104_M109/M104_M109.cpp
        ../src/malicious-gcode-detector/temp/M107/M107.cpp
        ../src/malicious-gcode-detector/temp/M106/M106.cpp
        ../src/malicious-gcode-detector/temp/M140/M140.cpp
        ../src/malicious-gcode-detector/temp/M141/M141.cpp
        ../src/malicious-gcode-detector/temp/M143_M193/M143_M193.cpp
        ../src/malicious-gcode-detector/temp/M190/M190.cpp
        ../src/malicious-gcode-detector/temp/M191/M191.cpp
        ../src/malicious-gcode-detector/temp/TemperatureSecurity.cpp
        ../src/malicious-gcode-detector/temp/TemperatureSecurity.h
        ../src/malicious-gcode-detector/temp/thermal-state/ThermalState.cpp
        ../src/malicious-gcode-detector/temp/thermal-state/ThermalState.h
        ../src/gcode-file-reader/GCodeFileReader.cpp
        ../src/gcode-file-reader/GCodeFileReader.h
        malicious-gcode-detector/temp/M104_M109/M104_M109.cpp
        malicious-gcode-detector/temp/M107/M107.cpp
        malicious-gcode-detector/temp/M106/M106.cpp
        malicious-gcode-detector/temp/M140/M140.cpp
        malicious-gcode-detector/temp/M141/M141.cpp
        malicious-gcode-detector/temp/M143_M193/M143_M193.cpp
        malicious-gcode-detector/temp/M190/M190.cpp
        gcode-file-reader/GCodeFileReader.cpp
        malicious-gcode-detector/temp/M191/M191.cpp
)

# linking Google_Tests_run with DateConverter_lib which will be tested
# target_link_libraries(Google_Tests_run include src)

target_link_libraries(Google_Tests_run gtest gtest_main gmock)