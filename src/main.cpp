#include "parser.h" // header parser

int main() {
    char testLine2[] = "M141 S400";
    char testLine3[] = "M141 S-400";
    char testLine4[] = "M141 P1";
    char testLine5[] = "M141 S60";
    char testLine6[] = "m141 P4 S101,11";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine5);
    GCodeParser::parse(testLine6);
}
