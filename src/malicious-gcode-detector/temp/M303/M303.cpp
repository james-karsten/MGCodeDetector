/**
 * This class detects the M303 commmand
 * M303 E0 C8 S210
 * Checks on S param if in safe temp range 0=hotend -1=bed /
 * Checks on E param if contains either 0 or -1
 * Checks C param if it is bigger then 3 (required)
 * Checks if PIDTEMP and PIDTEMPBED are enabled for M303 command to be used
 * Outputs warning if wrong format is used
 */
#include <string>
#include <regex>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"

/* M303 regex with optional Pparams C D E and U*/
const std::regex m303Pattern(R"(^M303\s*((C-?\d+)|(D)|(E(-1|0))|(S\d+(\.\d+)?)|(U))?\s*((C-?\d+)|(D)|(E(-1|0))|(S\d+(\.\d+)?)|(U))?\s*((C-?\d+)|(D)|(E(-1|0))|(S\d+(\.\d+)?)|(U))?\s*((C-?\d+)|(D)|(E(-1|0))|(S\d+(\.\d+)?)|(U))?\s*((C-?\d+)|(D)|(E(-1|0))|(S\d+(\.\d+)?)|(U))?\s*(;.*)?$)");


bool GCodeSecurityDispatcher::M303(char *gcode){
    std::cmatch match;

    #if ENABLED(PIDTEMP) and ENABLED(PIDTEMPBED)
        std::unordered_map<std::string, std::string> result = temperatureSecurity.parse_regex_gcode(m303Pattern, gcode);

        if (result.empty()) {
            // Incorrect formatting of command
            std::cout << "[Warning]: Incorrect formatting of command [" << gcode << "]" << std::endl;
            return false;
        }

        // S param is mandatory. Retrieve S value
        int sParam = std::stoi(result.at("S"));

        // check if C param is at least 3
        if(result.find("C") != result.end()) {
            int cParam = std::stoi(result.at("C"));
            if (cParam < 3) {
                // Incorrect amount of C param of command
                std::cout << "[Warning]: C parameter in command [" << gcode << "] is too low." << std::endl;
                return false;
            }
        }

        /* check if E is defined */
        if (result.find("E") != result.end()) {
            int eParam = std::stoi(result.at("E"));
            // Handle E parameter
            switch (eParam) {
                case 0:
                    /* Check against Hotend threshold */
                    return temperatureSecurity.safe_temperature_range(gcode, sParam, HEATER_0_MINTEMP, HEATER_0_MAXTEMP);
                case -1:
                    /* Check against temp bed threshold*/
                    return temperatureSecurity.safe_temperature_range(gcode, sParam, BED_MINTEMP, BED_MAXTEMP);
                default:
                    break;
            }
        } else {
            return temperatureSecurity.safe_temperature_range(gcode, sParam, HEATER_0_MINTEMP, HEATER_0_MAXTEMP);
        }

        // Incorrect formatting of command
        std::cout << "[Warning]: Incorrect formatting of command [" << gcode << "]" << std::endl;
        return false;
    #else
        std::cout << "[Error]: Command: " << gcode << " not possible due PIDTEMP and PIDTEMPBED not enabled in configuration." << std::endl;
        return false;
    #endif
}