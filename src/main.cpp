#include "parser.h" // header parser

int main() {
    char testLine2[] = "N1 G1 X10 Y20";
    GCodeParser::parse(testLine2);

    return 0;
}
