#include "parser.h" // header parser

int main() {
    char testLine2[] = "M107";
    char testLine3[] = "G01 X7 Y6";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine3);

    return 0;
}
