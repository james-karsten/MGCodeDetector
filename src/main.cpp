#include "parser.h" // header parser

int main() {
    char testLine1[] = "G1 X11 Y2 Z4";
    GCodeParser::parse(testLine1);

    return 0;
}
