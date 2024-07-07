/**
 * This class detects the M140 commmand
 * When M140 S100 is used, checks on temperature
 * Else, checks is M140 I1 us used
 * If gcode doesn't match formatting of examples above, notify user
 */
#include <string>
#include <regex>
#include <unordered_map>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"

/* Regex for M140 S100 */
const std::regex m140SetTemperature(R"(^M140\s+S\d+\s*(;.*)?$)");
/* Regex fir M140 I1 */
const std::regex pattern(R"(^M140\s+I\d+\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M140(char *gcode) {
    // match and retrieve gcode params of M140 S100
    std::unordered_map<std::string, std::string> result = temperatureSecurity.parse_regex_gcode(m140SetTemperature, gcode);

    /* check if result is not empty */
    if (!result.empty()) {
        int temp = stoi(result.at("S"));
        return temperatureSecurity.safe_range(gcode, temp, BED_MINTEMP, BED_MAXTEMP);
    }

    // Check if M140 I1 is used
    result = temperatureSecurity.parse_regex_gcode(pattern, gcode);
    if (!result.empty()) {
        return true;
    }

    /* incorrect formatting M104 command*/
    std::cout << "[Warning]: Incorrect formatting of command [" << gcode << "]" << std::endl;
    return false;
}

