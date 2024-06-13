#include "parser.h" // header parser

int main() {
    char testLine2[] = "G4 X44 Y2 Z4 X10 Y5 Z10 X10 Y5 Z10 X10 Y5 Z10 X10 Y5 Z10 X10 Y5 Z10 X10 Y5 Z10";
    char testLine3[] = "G1 X10 20";
    char testLine4[] = "G1 X10 Y20 Z@30";
    char testLine5[] = "G1 X10 Y20 Z-";
    char testLine6[] = "G1 X10 Y20 Z30 40";
    char testLine7[] = "G1 X10,Y20,Z30";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine5);
    GCodeParser::parse(testLine6);
    GCodeParser::parse(testLine7);

    return 0;
}
