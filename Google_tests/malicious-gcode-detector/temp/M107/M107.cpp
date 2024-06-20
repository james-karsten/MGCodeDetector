/**
 * The tests aim to test the methods M107() whether a warning output is given
 * NOTE: most tests were created with the help of GPT4o
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
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
    EXPECT_THAT(output, HasSubstr("[Warning]: M107 is invoked which turns off the fans."));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
