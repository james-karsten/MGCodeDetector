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

