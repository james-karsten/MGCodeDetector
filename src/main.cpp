#include <iostream>
#include "parser.h"
#include <string>
#include "../src/gcode-file-reader/GCodeFileReader.h"

int main() {
    std::string filename = "C:\\Users\\james\\CLionProjects\\untitled\\files\\gcode\\Prusa_200um_MINI_PLA_23m.gcode";
    GCodeFileReader::read_gcode_file(filename);

    std::cout << "Done" << std::endl;

//    char testLine2[] = "M107";
//    char testLine3[] = "M143 S400";
//    GCodeParser::parse(testLine2);
//    GCodeParser::parse(testLine2);
}
