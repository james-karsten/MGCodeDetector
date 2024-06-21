#include "parser.h" // header parser

int main() {
    char testLine2[] = "M140 S400";
    char testLine3[] = "M140 S-400";
    char testLine4[] = "M140 P1";
    char testLine5[] = "M140 P-1";
    char testLine6[] = "M106 P4 T5-300";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine5);
    GCodeParser::parse(testLine6);
}
