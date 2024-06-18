/**
 * The tests aim to test the method detect_invalid_gcode in the GCodeParser
 * which determines whether a G-code line has valid syntax based on a regex expression.
 * NOTE: most tests were created with the help of GPT4o
 */
#include <gtest/gtest.h>
#include "../src/parser.cpp"
#include "parser.h"

class GCodeInputParserTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(GCodeInputParserTest, ValidGcode) {
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 F1500", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M106 S255", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G90", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M140 S70", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G21", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 E0", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G0 X0 Y0", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G28 X0 Y0", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10.5 Y20.3 Z30.1 E0.5", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G2 X10 Y20 I5 J5", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G3 X10 Y20 I5 J5", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G4 P2000", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M109 S200", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G30", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 X0 Y0 Z0", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G20", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G53", false));
}

TEST_F(GCodeInputParserTest, InvalidGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10..5 Y20 Z30", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 20", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z@30", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z-", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 40", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10,Y20,Z30", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30.3.3", false));
}

TEST_F(GCodeInputParserTest, FuzzedGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30@#$", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M104_M109 S-99999", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X+10 Y-20", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X1e10 Y2e-3", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z\n30", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 ", false));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z 30", false));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1\tX10\tY20\tZ30", false));
}

TEST_F(GCodeInputParserTest, CaseInsensitiveValidGcode) {
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z30 F1500", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g1 x10 y20 z30 f1500", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M106 S255", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m106 s255", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G90", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g90", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M140 S70", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m140 s70", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G21", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g21", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m82", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m84 e", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 E0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g92 e0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G0 X0 Y0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g0 x0 y0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G28 X0 Y0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g28 x0 y0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10.5 Y20.3 Z30.1 E0.5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g1 x10.5 y20.3 z30.1 e0.5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G2 X10 Y20 I5 J5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g2 x10 y20 i5 j5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G3 X10 Y20 I5 J5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g3 x10 y20 i5 j5", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G4 P2000", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g4 p2000", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M109 S200", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m109 s200", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G30", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g30", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G92 X0 Y0 Z0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g92 x0 y0 z0", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M84 E", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m84 e", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M82", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("m82", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G20", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g20", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G53", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("g53", true));
}

TEST_F(GCodeInputParserTest, CaseInsensitiveInvalidGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10..5 y20 Z30", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 x10 20", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 z@30", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 x10 Y20 Z-", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("g1 x10 Y20 Z30 40", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10,Y20,z30", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 x10 y20 Z30.3.3", true));
}

TEST_F(GCodeInputParserTest, CaseInsensitiveFuzzedGcode) {
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("g1 X10 y20 Z30@#$", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("M104_M109 s-99999", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X+10 Y-20", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 x1e10 Y2e-3", true));
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 X10 Y20 Z\n30", true));
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1 X10 y20 Z30 ", true));  // Trailing space
    EXPECT_FALSE(GCodeParser::detect_invalid_gcode("G1 x10 Y20 z 30", true));  // Space within parameter value
    EXPECT_TRUE(GCodeParser::detect_invalid_gcode("G1\tX10\tY20\tZ30", true));  // Tab characters separating parameters
}