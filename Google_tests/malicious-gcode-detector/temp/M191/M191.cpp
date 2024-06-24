/**
 * The tests aim to test the methods M191()
 * NOTE: most tests were created with the help of GPT4o
 */
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
#include <gtest/gtest.h>

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M191_I3) {
    char gcode[] = "M191 I3";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_S80_3) {
    char gcode[] = "M191 S80.3";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_S830) {
    char gcode[] = "M191 S830";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_S0) {
    char gcode[] = "M191 S0";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_R40) {
    char gcode[] = "M191 R40";
    EXPECT_TRUE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_R9000) {
    char gcode[] = "M191 R9000";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_R0) {
    char gcode[] = "M191 R0";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_R0_0) {
    char gcode[] = "M191 R0,0";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_R_minus_1000) {
    char gcode[] = "M191 R-1000";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_Rxxx) {
    char gcode[] = "M191 Rxxx";
    EXPECT_FALSE(dispatcher.M191(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M191_S40) {
    char gcode[] = "M191 S40";
    EXPECT_TRUE(dispatcher.M191(gcode));
}