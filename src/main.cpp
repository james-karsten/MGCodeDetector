#include "parser.h" // header parser

int main() {
    // Define a test G-code line
    char testLine1[] = "G1 X10.5.3 Y20";      // Invalid float value '10.5.3'
    GCodeParser::parse(testLine1);
    return 0;
}
