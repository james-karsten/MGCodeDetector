/**
 * This class detects the M191 commmand
 * Against several commands
 * M191 S100 checks on temp bounds
 * M191 R40 checks on temp bounds
 * other format gives incorrect format warning
 */
#include <string>
#include <regex>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"

/* Regex for M191 S100 and M191 R40 */
const std::regex m191Pattern(R"(^M191\s+([SR])(\d+)\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M191(char *gcode) {

    std::cmatch match;

    // Check if the gcode matches the M191 pattern
    if (std::regex_match(gcode, match, m191Pattern)) {
        char commandType = match[1].str()[0];
        int paramValue = std::stoi(match[2].str());

        switch (commandType) {
            case 'S':
                return temperatureSecurity.safe_range(gcode, paramValue, CHAMBER_MINTEMP, CHAMBER_MAXTEMP);
            case 'R':
                return temperatureSecurity.safe_range(gcode, paramValue, CHAMBER_MINTEMP, CHAMBER_MAXTEMP);
            default:
                break;
        }
    }

    // Incorrect formatting of command
    std::cerr << "[Error]: Incorrect formatting or temp value of command [" << gcode << "]" << std::endl;
    return false;
}