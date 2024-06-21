/**
 * The tests aim to test the methods M140()
 * NOTE: most tests were created with the help of GPT4o
 */

#include <gtest/gtest.h>
#include "../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M140_correct_temp) {
    char gcode[] = "M140 S100";
    EXPECT_TRUE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_correct_format) {
    char gcode[] = "M140 P1";
    EXPECT_TRUE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_incorrect_temp) {
    char gcode[] = "M140 S400";
    EXPECT_FALSE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_incorrect_temp_2) {
    char gcode[] = "M140 S0";
    EXPECT_FALSE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_incorrect_format) {
    char gcode[] = "M140 S-400";
    EXPECT_FALSE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_incorrect_format_2) {
    char gcode[] = "M140 P-1";
    EXPECT_FALSE(dispatcher.M140(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M140_incorrect_format_3) {
    char gcode[] = "M140 P1.1";
    EXPECT_FALSE(dispatcher.M140(gcode));
}
