/**
 * The tests aim to test the methods M303()
 * NOTE: most tests were created with the help of GPT4o
 */
#include <gmock/gmock.h>
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
#include <gtest/gtest.h>

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;


};

#if ENABLED(PIDTEMP) and ENABLED(PIDTEMPBED)
TEST_F(GCodeSecurityDispatcherTest, M303_E0_C8_S210) {
    char gcode[] = "M303 E0 C8 S210";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E_minus1_C8_S210) {
    char gcode[] = "M303 E-1 C8 S210";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E10_C8_S210) {
    char gcode[] = "M303 E10 C8 S210";
    EXPECT_FALSE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E0_C8_S2100) {
    char gcode[] = "M303 E0 C8 S2100";
    EXPECT_FALSE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E_minus1_C8_S210_Duplicate) {
    char gcode[] = "M303 E-1 C8 S210";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E0_C8_S210_5) {
    char gcode[] = "M303 E0 C8 S210.5";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_D_E_minus1_C8_S21_5) {
    char gcode[] = "M303 D E-1 C8 S21.5";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_C8_S210_U) {
    char gcode[] = "M303 C8 S210 U";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_S210) {
    char gcode[] = "M303 S210";
    EXPECT_TRUE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_S0_U) {
    char gcode[] = "M303 S0 U";
    EXPECT_FALSE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_S5210) {
    char gcode[] = "M303 S5210";
    EXPECT_FALSE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E3_C8_S21) {
    char gcode[] = "M303 E3 C8 S21";
    EXPECT_FALSE(dispatcher.M303(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M303_E3_C2_S21) {
    char gcode[] = "M303 E3 C2 S21";
    EXPECT_FALSE(dispatcher.M303(gcode));
}
#else

using testing::HasSubstr;

TEST_F(GCodeSecurityDispatcherTest, M303_not_possible) {
    // Capture stdout
        testing::internal::CaptureStdout();

        // Test command
        char command[] = "M303 S100";

        // Dispatch command
        dispatcher.M303(command);

        // snapshot the captured output
        std::string output = testing::internal::GetCapturedStdout();

        // Verify the output
        EXPECT_THAT(output, HasSubstr("[Warning]: Incorrect formatting of command [M303 S100]\n"));
}
#endif