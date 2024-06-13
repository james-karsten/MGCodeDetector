#include "parser.h" // header parser

int main() {
    char testLine2[] = "M109 X10 Y432";
    GCodeParser::parse(testLine2);

    return 0;
}
