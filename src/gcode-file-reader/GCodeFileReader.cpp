/**
 * This class reads GCO files and parses them with the
 * GCodeParser class
 */
#include <iostream>
#include "parser.h" // header parser
#include <fstream>
#include <string>
#include "GCodeFileReader.h"

void GCodeFileReader::read_gcode_file(const std::string& filename) {

    // Check .gco file extension
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".gco") {
        std::cerr << "File Error: " << filename << " is not a .gco file" << std::endl;
        return;
    }

    // Check if file can be opened
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "File Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {

        /* skip line that starts with ; (comment*/
        if (line[0] == ';' || line.empty()) {
            continue;
        }
        GCodeParser::parse(const_cast<char *>(line.c_str()));
    }

    infile.close();
}