/**
 * The tests aim to test the methods M106()
 * It also considers the EXTRA_FAN_SPEED option to check wheter
 * the temperature has valid bounds
 * NOTE: most tests were created with the help of GPT4o
 */

#include <gtest/gtest.h>
#include "../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, ExtractsAndChecksSpeedFromSingleValue) {
    char gcode[] = "M106 P2 T2";
    EXPECT_TRUE(dispatcher.M106(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, DoesNotMatchInvalidGcode) {
    char gcode[] = "M106 P1 T1";
    EXPECT_TRUE(dispatcher.M106(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, ExtractsTemperatureAndChecksRange) {
    char gcode[] = "M106 P1 T1-254";
    EXPECT_TRUE(dispatcher.M106(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, HandlesInvalidTemperature) {
    char gcode[] = "M106 P1 T1-300";
    EXPECT_FALSE(dispatcher.M106(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, TestVariablesM106) {
    /* if EXTRA_FAN_SPEED disabled Notify user  */
    #if DISABLED(EXTRA_FAN_SPEED)
    char gcode[] = "M106 P1 T3-255";
    // Capture stdout
    testing::internal::CaptureStdout();

    // Dispatch command
    dispatcher.M106(gcode);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_EQ(output, "EXTRA_FAN_SPEED should be defined in the configuration for instruction M106 P1 T3-255\n");

    #endif
}
