/**
 * The tests aim to test the GCodeFileReader class
 * NOTE: most tests were created with the help of GPT4o
 */
#include <gtest/gtest.h>
#include <string>
#include "../../src/gcode-file-reader/GCodeFileReader.h"

class GCodeFileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(GCodeFileReaderTest, ValidFileExtension) {
    testing::internal::CaptureStderr();
    GCodeFileReader::read_gcode_file("gcode.txt");
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "File Error: gcode.txt is not a .gco file\n");
}

TEST_F(GCodeFileReaderTest, ValidFileExtensionNonExist) {
    testing::internal::CaptureStderr();
    GCodeFileReader::read_gcode_file("test.gco");
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "File Error: Could not open file test.gco\n");
}