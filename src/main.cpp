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

    char testLine2[] = "M710 A1 S255 I128";
    char testLine3[] = "M710 A0 S255";
    char testLine4[] = "M710 R";
    char testLine5[] = "M710 A0 S2550";
    char testLine6[] = "M710 A1 S245 I1228";
    char testLine7[] = "M710 A1 S2245 I28";
    char testLine8[] = "M710 A1 S0 I20.8";
    char testLine9[] = "M710 A1 S2245.8 I28";
    char testLine10[] = "M710 A1 S255 I0";
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
