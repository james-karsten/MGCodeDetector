#include <iostream>
#include "parser.h"
#include <string>
#include "../src/gcode-file-reader/GCodeFileReader.h"

int main() {
    // std::string filename = "C:\\Users\\james\\CLionProjects\\untitled\\files\\gcode\\Prusa_200um_MINI_PLA_23m.gcode";
//    std::string filename = "C:\\Users\\james\\CLionProjects\\untitled\\files\\gcode\\tests\\M107\\M107_valid_gcode.gcode";
//    GCodeFileReader::read_gcode_file(filename);
//
//    std::cout << "Done" << std::endl;

    char testLine2[] = "M191 I3";
    char testLine3[] = "M191 S80.3";
    char testLine4[] = "M191 S830";
    char testLine5[] = "M191 S0";
    char testLine6[] = "M191 R40";
    char testLine7[] = "M191 R9000";
    char testLine8[] = "M191 R0";
    char testLine9[] = "M191 R0,0";
    char testLine10[] = "M191 R-1000";
    char testLine11[] = "M191 Rxxx";
    char testLine12[] = "M191 S40";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine5);
    GCodeParser::parse(testLine6);
    GCodeParser::parse(testLine7);
    GCodeParser::parse(testLine8);
    GCodeParser::parse(testLine9);
    GCodeParser::parse(testLine10);
    GCodeParser::parse(testLine11);
    GCodeParser::parse(testLine12);
}
