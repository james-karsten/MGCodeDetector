/**
 * The tests aim to test the methods M107() whether a warning output is given
 * NOTE: most tests were created with the help of GPT4o
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
#include "../../../../src/gcode-file-reader/GCodeFileReader.h"
#include <string>

using testing::HasSubstr;

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M107GeneratesWarning) {
    // Capture stdout
    testing::internal::CaptureStdout();

    // Test command
    char command[] = "M107";

    // Dispatch command
    dispatcher.M107(command);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Warning]: Command [M107] is invoked which turns off the fans.\n"));
}

TEST_F(GCodeSecurityDispatcherTest, M107ValidGcode106FansOn) {

    testing::internal::CaptureStdout();
    GCodeFileReader::read_gcode_file(R"(C:\Users\james\CLionProjects\untitled\files\gcode\tests\M107\M107_valid_gcode.gcode)");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Warning]: Command [M107 ; turn off fans] is invoked which turns off the fans.\n");

}

TEST_F(GCodeSecurityDispatcherTest, M107InValidGcode106FansOff) {

    testing::internal::CaptureStdout();
    GCodeFileReader::read_gcode_file(R"(C:\Users\james\CLionProjects\untitled\files\gcode\tests\M107\M107_invalid_gcode.gcode)");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Warning]: Command [M107 ; turn off fans] is invoked which turns off the fans.\n[Danger]: Command [M107] contains subsequent commands that require cooling\n");
}

TEST_F(GCodeSecurityDispatcherTest, TestVariablesM107) {

#if ENABLED(LASER_SYNCHRONOUS_M106_M107)
    char gcode[] = "M107";
    // Capture stdout
    testing::internal::CaptureStdout();

    // Dispatch command
    dispatcher.M107(gcode);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_EQ(output, "[Warning]: Command [M107] is invoked which turns off the laser.\n");

#endif
}

