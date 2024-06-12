/**
 * The tests aim to test the method detect_invalid_gcode in the GCodeParser
 * which determines wheter a G-code line has valid syntax based on a regex expression.
 */
#include <gtest/gtest.h>
#include "../src/parser.cpp"

class GCodeInputParserTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(GCodeInputParserTest, ValidGcode) {
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 F1500"));  // Simple move command with feedrate
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M106 S255"));  // Set fan speed
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G90"));  // Set to absolute positioning
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M140 S70"));  // Set bed temperature
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G21"));  // Set units to millimeters
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82"));  // Set extruder to absolute mode
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E"));  // / Disable extruder motors
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 E0"));  // Set extruder position
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G0 X0 Y0"));  // Rapid move to origin
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G28 X0 Y0"));  // Home X and Y axes
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10.5 Y20.3 Z30.1 E0.5"));  // Move with precise floats
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G2 X10 Y20 I5 J5"));  // Clockwise arc move
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G3 X10 Y20 I5 J5"));  // Counter-clockwise arc move
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G4 P2000"));  // Dwell (wait)
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M109 S200"));  // Set extruder temperature and wait
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G30"));  // Single Z probe
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 X0 Y0 Z0"));  // Set position
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E"));  // Disable extruder motors
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82"));  // Set extruder to absolute mode
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G20"));  // Set units to inches
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G53"));  // Use machine coordinate system
}

TEST_F(GCodeInputParserTest, InvalidGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10..5 Y20 Z30"));  // Invalid float value '10..5'
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 20"));  // Missing parameter identifier 'Y'
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z@30"));  // Invalid character '@' in parameter
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z-"));  // Incomplete parameter value
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 40"));  // Extra numerical value without parameter identifier
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10,Y20,Z30"));  // Invalid format with commas
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30.3.3"));  // Invalid float value '30.3.3'
}

TEST_F(GCodeInputParserTest, FuzzedGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30@#$"));  // Special characters in parameters
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M104 S-99999"));  // Extreme negative value
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X+10 Y-20"));  // Plus and minus signs
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X1e10 Y2e-3"));  // Scientific notation
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z\n30"));  // Newline character within the command
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 "));  // Trailing space
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z 30"));  // Space within parameter value
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1\tX10\tY20\tZ30"));  // Tab characters separating parameters
}
