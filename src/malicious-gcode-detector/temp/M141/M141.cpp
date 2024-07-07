/**
 * This class detects the M141 commmand
 * When M140 S100 is used, checks on temperature
 * If gcode doesn't match formatting of examples above, notify user
 */
#include <string>
#include <regex>
#include <unordered_map>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"

/* Regex for M140 S100 */
const std::regex m141SetTemperature(R"(^M141\s+S\d+\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M141(char *gcode) {
    // match and retrieve gcode params of M140 S100
    std::unordered_map<std::string, std::string> result = temperatureSecurity.parse_regex_gcode(m141SetTemperature, gcode);

    /* check if result is not empty */
    if (!result.empty()) {
        int temp = stoi(result.at("S"));

        /* return if temp == 0*/
        if (temp == 0) {
            return true;
        }
        return temperatureSecurity.safe_range(gcode, temp, CHAMBER_MINTEMP, CHAMBER_MAXTEMP);
    }

    /* incorrect formatting M104 command*/
    std::cout << "[Warning]: Incorrect formatting of command [" << gcode << "] " << std::endl;
    return false;
}

