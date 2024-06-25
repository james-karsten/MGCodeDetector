/**
 * The tests aim to test the methods M710()
 * NOTE: most tests were created with the help of GPT4o
 */
#include <gmock/gmock.h>
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
#include <gtest/gtest.h>

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

#if ENABLED(CONTROLLER_FAN_EDITABLE)
TEST_F(GCodeSecurityDispatcherTest, M710_A1_S255_I128) {
    char gcode[] = "M710 A1 S255 I128";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A0_S255) {
    char gcode[] = "M710 A0 S255";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_R) {
    char gcode[] = "M710 R";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A0_S2550) {
    char gcode[] = "M710 A0 S2550";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A1_S245_I1228) {
    char gcode[] = "M710 A1 S245 I1228";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A1_S2245_I28) {
    char gcode[] = "M710 A1 S2245 I28";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A1_S0_I20_8) {
    char gcode[] = "M710 A1 S0 I20.8";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A1_S2245_8_I28) {
    char gcode[] = "M710 A1 S2245.8 I28";
    EXPECT_FALSE(dispatcher.M710(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M710_A1_S255_I0) {
    char gcode[] = "M710 A1 S255 I0";
    EXPECT_FALSE(dispatcher.M710(gcode));
}
#else
using testing::HasSubstr;

TEST_F(GCodeSecurityDispatcherTest, M710_not_possible) {
    // Capture stdout
    testing::internal::CaptureStdout();

    // Test command
    char command[] = "M710 A0 S180 I180";

    // Dispatch command
    dispatcher.M710(command);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Error]: Command: [M710 A0 S180 I180] not possible due CONTROLLER_FAN_EDITABLE not enabled in configuration.\n"));
}
#endif
