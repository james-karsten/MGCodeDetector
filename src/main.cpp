#include <iostream>
#include "parser.h"
#include <string>
#include "../src/gcode-file-reader/GCodeFileReader.h"
#include <filesystem>
#include <fstream>
#include <list> // for list operations
#include <vector>
#include "malicious-gcode-detector/GCodeSecurityDispatcher.h"


// declaring list
std::vector<std::string> valid_gcodes;
std::vector<std::string> invalid_gcodes;
std::vector<std::string> malicious_gcodes;
std::vector<std::string> benign_gcodes;



void read_gcode_file_exp1(const std::string& filename) {

    // Check .gco file extension
    if (filename.size() < 6 || filename.substr(filename.size() - 6) != ".gcode") {
        std::cerr << "File Error: " << filename << " is not a .gcode file" << std::endl;
        return;
    }

    // Check if file can be opened
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "File Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    bool gcode_validation;
    while (std::getline(infile, line)) {

        /* skip line that starts with ; (comment*/
        if (line[0] == ';' || line.empty()) {
            continue;
        }

        gcode_validation = GCodeParser::detect_valid_gcode(const_cast<char *>(line.c_str()), true);

        if (gcode_validation) {
            valid_gcodes.push_back(line);
        } else {
            invalid_gcodes.push_back(line);
        }

    }

    infile.close();
}

/**
 * Experiment 1 for invalid/valid g-codes
 * @return
 */
int experiment_valid_invalid_gcodes() {
    std::string directory = "";

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".gcode") {
            std::string filename = entry.path().string();
            std::cout << "Analyzing file: " << filename << std::endl;
            read_gcode_file_exp1(filename);
        }
        std::cout << "  "  << std::endl;
    }

    /* print items */
    std::cout << "valid G-codes: " << std::endl;
    for (auto& code : valid_gcodes) {
        std::cout << code << std::endl;
    }

    std::cout << " =====================" << std::endl;
    std::cout << "Invalid G-codes: " << std::endl;
    for (auto& code : invalid_gcodes) {
        std::cout << code << std::endl;
    }


    return 0;
}



/**
 * Experiment 2 for benign/malicious g-codes
 * @return
 */
int experiment_benign_malicious_gcodes() {
    std::string directory = "";

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".gcode") {
            std::string filename = entry.path().string();
            std::cout << "Analyzing file: " << filename << std::endl;
            GCodeFileReader::read_gcode_file(filename);
        }
        std::cout << "  "  << std::endl;
    }

    std::cout << "Done" << std::endl;
    return 0;
}


int main() {
    std::string file;

    // Configuration files
    std::cout << "MGDetector v1" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "IMPORTANT: Configuration files for your 3D printer can be downloaded from: https://github.com/MarlinFirmware/Configurations/tree/import-2.1.x/config/examples";
    std::cout << "Only the 'Configuration.h' and 'Configuration_adv.h' files are necessary to download for this tool." << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    // Retrieve filepath
    std::cout << "Enter filepath for file analysis on malicious invalid G-code: " << std::endl;
    std::getline(std::cin, file);

    // Read code
    GCodeFileReader::read_gcode_file(file);
}

