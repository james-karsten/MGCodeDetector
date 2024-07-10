/**
 * The tests aim to test the methods M306() whether a warning output is given
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

TEST_F(GCodeSecurityDispatcherTest, M306GeneratesWarning) {
    // Capture stdout
    testing::internal::CaptureStdout();

    // Test command
    char command[] = "M306";

    // Dispatch command
    dispatcher.M306(command);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Warning]: Command [M306] is invoked which tunes the Model Predictive Temperature Control.\n"));
}

