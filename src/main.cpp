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

    char testLine2[] = "M303 E0 C8 S210";
    char testLine3[] = "M303 E-1 C8 S210";
    char testLine4[] = "M303 E10 C8 S210";
    char testLine5[] = "M303 E0 C8 S2100";
    char testLine6[] = "M303 E-1 C8 S210";
    char testLine7[] = "M303 E0 C8 S210.5";
    char testLine8[] = "M303 D E-1 C8 S21.5";
    char testLine9[] = "M303 C8 S210 U";
    char testLine10[] = "M303 S210";
    char testLine11[] = "M303 S0 U";
    char testLine12[] = "M303 S5210";
    char testLine13[] = "M303 E3 C8 S21";
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
    GCodeParser::parse(testLine13);
}
