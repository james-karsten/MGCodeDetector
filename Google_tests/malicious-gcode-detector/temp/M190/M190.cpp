/**
 * The tests aim to test the methods M190()
 * NOTE: most tests were created with the help of GPT4o
 */
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"
#include <gtest/gtest.h>

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M190_I3) {
    char gcode[] = "M190 I3";
    EXPECT_TRUE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_S80) {
    char gcode[] = "M190 S80";
    EXPECT_TRUE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_S830) {
    char gcode[] = "M190 S830";
    EXPECT_FALSE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_S0) {
    char gcode[] = "M190 S0";
    EXPECT_FALSE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_R40) {
    char gcode[] = "M190 R40";
    EXPECT_TRUE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_R9000) {
    char gcode[] = "M190 R9000";
    EXPECT_FALSE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_R0) {
    char gcode[] = "M190 R0";
    EXPECT_FALSE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_R0_T600) {
    char gcode[] = "M190 R0 T600";
#if (ENABLED(BED_ANNEALING_GCODE))
    EXPECT_TRUE(dispatcher.M190(gcode));
#else
    EXPECT_FALSE(dispatcher.M190(gcode));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M190_R39_T600) {
    char gcode[] = "M190 R39 T600";
#if (ENABLED(BED_ANNEALING_GCODE))
    EXPECT_TRUE(dispatcher.M190(gcode));
#else
    EXPECT_FALSE(dispatcher.M190(gcode));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M190_R39_X10_T600) {
    char gcode[] = "M190 R39 X10 T600";
    EXPECT_FALSE(dispatcher.M190(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M190_Z0_X10) {
    char gcode[] = "M190 Z0 X10";
    EXPECT_FALSE(dispatcher.M190(gcode));
}
