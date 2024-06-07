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

#include <iostream>
#include <map>
#include "parser.h"

void check_parser(const std::string& gcode, const std::string& expectedCommand, const std::map<char, float>& expectedParameters) {
    GCodeParser parser;
    parser.parse(const_cast<char *>(gcode.c_str()));

    if (parser.command() != expectedCommand) {
        std::cerr << "Test failed for G-code: " << gcode << std::endl;
        std::cerr << "Expected command: " << expectedCommand << " but got: " << parser.command() << std::endl;
    } else {
        std::cout << "Command test passed for: " << gcode << std::endl;
    }

    for (const auto& param : expectedParameters) {
        if (parser.has_parameter(param.first)) {
            float value = parser.parameter_value(param.first);
            if (value != param.second) {
                std::cerr << "Test failed for G-code: " << gcode << std::endl;
                std::cerr << "Expected parameter " << param.first << " value: " << param.second << " but got: " << value << std::endl;
            } else {
                std::cout << "Parameter " << param.first << " test passed for: " << gcode << std::endl;
            }
        } else {
            std::cerr << "Test failed for G-code: " << gcode << std::endl;
            std::cerr << "Expected parameter " << param.first << " but it was not found." << std::endl;
        }
    }
}

int main() {
    check_parser("G1 X10.0 Y20.0 Z30.0", "G1", {{'X', 10.0}, {'Y', 20.0}, {'Z', 30.0}});

    // Test case 2
    check_parser("M104 S190", "M104", {{'S', 190.0}});

    // Test case 3
    check_parser("G28", "G28", {});

    // Test case 4
    check_parser("G92 E0", "G92", {{'E', 0.0}});


    const char* gcode_line = "KAK";

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
