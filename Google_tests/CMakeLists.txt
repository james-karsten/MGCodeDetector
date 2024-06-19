project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/src)

# adding the Google_Tests_run target
add_executable(Google_Tests_run InvalidGCodeParser.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
# target_link_libraries(Google_Tests_run include src)

target_link_libraries(Google_Tests_run gtest gtest_main)