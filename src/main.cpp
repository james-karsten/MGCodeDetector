#include "parser.h" // header parser

int main() {
    char testLine2[] = "M109 S100 X10 Y432";
    char testLine4[] = "M104 S500 X10 Y432";
    char testLine3[] = "M104_M109 X10 Y432";
    GCodeParser::parse(testLine2);
    GCodeParser::parse(testLine4);
    GCodeParser::parse(testLine3);

    return 0;
}
