#include "parser.h" // header parser

int main() {
    char testLine2[] = "M109 X100 Y200";
    GCodeParser::parse(testLine2);

    return 0;
}
