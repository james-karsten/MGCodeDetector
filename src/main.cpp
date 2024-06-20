#include "parser.h" // header parser

int main() {
    char testLine2[] = "M107";
    char testLine3[] = "M106 S200";
    char testLine4[] = "M106 P1 T3-254";
    char testLine5[] = "M106 P2 T2";
    char testLine6[] = "M106 P4 T5-300";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine5);
    GCodeParser::parse(testLine6);

    return 0;
}
