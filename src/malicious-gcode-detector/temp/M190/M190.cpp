/**
 * This class detects the M190 commmand
 * Against several commands
 * M190 R40 T600 checks temp but only if BED_ANNEALING_GCODE is enabled
 * M190 S100 checks on temp bounds
 * M190 I1 return true
 * M190 R40 checks on temp bounds
 * other format gives incorrect format warning
 */
#include  <string>
#include <regex>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"

/* Regex for M190 R40 T600 and  M190 S100 and  M190 I1 and  M190 R40 */
const std::regex m190Pattern(R"(^M190\s+([SIR])(\d+)(?:\s+T(\d+))?\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M190(char *gcode) {
    std::cmatch match;

    // Check if the gcode matches the M190 pattern
    if (std::regex_match(gcode, match, m190Pattern)) {
        char commandType = match[1].str()[0];
        int paramValue = std::stoi(match[2].str());

        // Option in Marlin 2.1.3 for BED_ANNEALING_GCODE
        if (commandType == 'R' && match[3].matched) {
            #if (ENABLED(BED_ANNEALING_GCODE))
                int coolingTime = std::stoi(match[3].str());
                return temperatureSecurity.safe_temperature_range(gcode, paramValue, BED_MINTEMP, BED_MAXTEMP);
            #else
                std::cerr << "[Error]: Command: " << gcode << " not possible due BED_ANNEALING_GCODE not enabled in configuration." << std::endl;
                return false;
            #endif
        }

        switch (commandType) {
            case 'S':
                return temperatureSecurity.safe_range(gcode, paramValue, BED_MINTEMP, BED_MAXTEMP);
            case 'I':
                return true;
            case 'R':
                return temperatureSecurity.safe_range(gcode, paramValue, BED_MINTEMP, BED_MAXTEMP);
            default:
                break;
        }
    }

    // Incorrect formatting of M190 command
    std::cerr << "[Error]: Incorrect formatting or temperature value [" << gcode << "]" << std::endl;
    return false;
}

