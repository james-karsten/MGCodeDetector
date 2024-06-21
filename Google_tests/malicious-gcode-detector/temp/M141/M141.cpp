/**
 * The tests aim to test the methods M141()
 * NOTE: most tests were created with the help of GPT4o
 */

#include <gtest/gtest.h>
#include "../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M141_correct_temp) {
    char gcode[] = "M141 S60";
    EXPECT_TRUE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_correct_format) {
    char gcode[] = "M141 S51";
    EXPECT_TRUE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_incorrect_temp) {
    char gcode[] = "M141 S1";
    EXPECT_FALSE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_incorrect_temp_2) {
    char gcode[] = "M141 S80";
    EXPECT_FALSE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_incorrect_format) {
    char gcode[] = "M141 S-400";
    EXPECT_FALSE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_incorrect_format_2) {
    char gcode[] = "M141 P-1";
    EXPECT_FALSE(dispatcher.M141(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M141_incorrect_format_3) {
    char gcode[] = "M141 S5.5";
    EXPECT_FALSE(dispatcher.M141(gcode));
}
