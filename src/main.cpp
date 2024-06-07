#include <iostream>
#include <string>
#include <fstream>
#include "parser.h" // header parser

/**
 * Read .gco file
 * @path path of .gco file
 */
std::string readFile(const std::string& path) {
    std::ifstream file(path);

    // check if file is can be opened
    if (!file) {
        std::cerr << "Could not open file: " << path << std::endl;
        return "";
    }

    // read file and return contents of file
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

int main() {

    const char* gcode_line = "G28";

    GCodeParser::parse(const_cast<char *>(gcode_line));
//    std::string path = R"(C:\Users\james\CLionProjects\untitled\files\test.gco)";
//
//    std::string content = readFile(path);
//    if (content.empty()) {
//        std::cout << "Content is empty";
//        return 1;
//    }
    return 0;
}
