/**
 * The tests aim to test the methods M143_M193()
 * NOTE: most tests were created with the help of GPT4o
 */


#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../../src/malicious-gcode-detector/GCodeSecurityDispatcher.h"

using testing::HasSubstr;

class GCodeSecurityDispatcherTest : public ::testing::Test {
protected:
    GCodeSecurityDispatcher dispatcher;
};

TEST_F(GCodeSecurityDispatcherTest, M143_M193_correct_temp) {
    #if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
        char gcode[] = "M143 S10";
        EXPECT_TRUE(dispatcher.M143_M193(gcode));
    #endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_correct_temp_2) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M193 S15";
    EXPECT_TRUE(dispatcher.M143_M193(gcode));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_incorrect_temp) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M143 S100";
    EXPECT_FALSE(dispatcher.M143_M193(gcode));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_incorrect_temp_2) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M193 S100";
    EXPECT_FALSE(dispatcher.M143_M193(gcode));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_incorrect_format) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M193 S-100";
    // Capture stdout
    testing::internal::CaptureStdout();

    // Dispatch command
    dispatcher.M143_M193(gcode);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Error] M143_M193 command: M193 S-100 not possible due incorrect formatting."));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_incorrect_format_2) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M143 S-100";
    // Capture stdout
    testing::internal::CaptureStdout();

    // Dispatch command
    dispatcher.M143_M193(gcode);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Error] M143_M193 command: M143 S-100 not possible due incorrect formatting."));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_laser_off) {
#if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1
    char gcode[] = "M143 S0";
    // Capture stdout
    testing::internal::CaptureStdout();

    // Dispatch command
    dispatcher.M143_M193(gcode);

    // snapshot the captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output
    EXPECT_THAT(output, HasSubstr("[Warning] M143_M193 command: M143 S0 laser cooler turned off."));
#endif
}

TEST_F(GCodeSecurityDispatcherTest, M143_M193_incorrect_config) {
#if DISABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 0
    // Capture stdout
        testing::internal::CaptureStdout();

        // Test command
        char command[] = "M143 S10";

        // Dispatch command
        dispatcher.M143_M193(command);

        // snapshot the captured output
        std::string output = testing::internal::GetCapturedStdout();

        // Verify the output
        EXPECT_THAT(output, HasSubstr("[Error] M143_M193 command: M143 S10 not possible due laser feature not enabled in configuration."));
#endif
}
