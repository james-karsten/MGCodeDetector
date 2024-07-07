/**
 * The tests aim to test the methods M104_M109(), m109_wait_cooling() and m104_m109_autotemp()
 * of the M104_M109 instructions.
 * NOTE: most tests were created with the help of GPT4o
 */
#include <gtest/gtest.h>
#include "../../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M104_M109_ValidCooling) {

    char gcode[] = "M109 R150";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_ValidAutotemp) {
    char gcode[] = "M104 F S150 B180";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_InvalidAutotemp) {
    // S is below threshold HEATER_0_MINTEMP
    char gcode[] = "M104 F S4 B180";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_ValidTempSetting) {
    char gcode[] = "M104 S200";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_InvalidTempSetting) {
    // S is below threshold HEATER_0_MINTEMP
    char gcode[] = "M104 S1";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M109_WaitCooling_Valid) {
    char gcode[] = "M109 R200";
    int rParam = 0;

    EXPECT_TRUE(dispatcher.m109_wait_cooling(gcode, rParam));
    EXPECT_EQ(rParam, 200);
}

TEST_F(GCodeSecurityDispatcherTest, M109_WaitCooling_Invalid) {
    // R is below threshold HEATER_0_MINTEMP
    char gcode[] = "M109 R4";
    int rParam = 0;

    EXPECT_FALSE(dispatcher.m109_wait_cooling(gcode, rParam));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_Autotemp_Valid) {
    char gcode[] = "M104 F S180 B220";
    int sParam = 0, bParam = 0;

    EXPECT_TRUE(dispatcher.m104_m109_autotemp(gcode, sParam, bParam));
    EXPECT_EQ(sParam, 180);
    EXPECT_EQ(bParam, 220);
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_Autotemp_Invalid) {
    // S is below threshold HEATER_0_MINTEMP
    char gcode[] = "M104 F S3 B220";
    int sParam = 0, bParam = 0;

    EXPECT_FALSE(dispatcher.m104_m109_autotemp(gcode, sParam, bParam));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_Valid) {
    char gcode[] = "M109 S100 X10 Y432";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_Invalid) {
    char gcode[] = "M104 S500 X10 Y432";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_InvalidCommand) {
    char gcode[] = "M104_M109 X10 Y432";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_R1000) {
    char gcode[] = "M109 R1000";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_T1_R10) {
    char gcode[] = "M109 T1 R10";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_T1_R200) {
    char gcode[] = "M109 T1 R200";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_T1_R2300) {
    char gcode[] = "M109 T1 R2300";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_R130) {
    char gcode[] = "M109 R130";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_F1_B100_S200) {
    char gcode[] = "M104 F1 B100 S200";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_F_S180_B1) {
    char gcode[] = "M104 F S180 B1";
    int sParam = 0, bParam = 0;

    EXPECT_FALSE(dispatcher.m104_m109_autotemp(gcode, sParam, bParam));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_F_B2000_S100) {
    char gcode[] = "M104 F B2000 S100";
    int sParam = 0, bParam = 0;


    EXPECT_FALSE(dispatcher.m104_m109_autotemp(gcode, sParam, bParam));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_F_B0_S1) {
    char gcode[] = "M104 F B0 S1";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_S180) {
    char gcode[] = "M109 S180";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_R120) {
    char gcode[] = "M109 R120";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_T1_R120) {
    char gcode[] = "M109 T1 R120";

    EXPECT_TRUE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_T1_R420) {
    char gcode[] = "M109 T1 R420";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_R420) {
    char gcode[] = "M109 R420";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_S420) {
    char gcode[] = "M109 S420";

    EXPECT_FALSE(dispatcher.M104_M109(gcode));
}

TEST_F(GCodeSecurityDispatcherTest, M104_M109_F_B4_S100) {
    char gcode[] = "M109 F B4 S100";
    int sParam = 0, bParam = 0;
    EXPECT_FALSE(dispatcher.m104_m109_autotemp(gcode, sParam, bParam));
}


