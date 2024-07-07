/**
 * This class detects the M710 commmand
 */
#include <string>
#include <regex>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"
#include "../thermal-state/ThermalState.h"

/* M710 regex with optional Pparams C D E and U*/
const std::regex m710Pattern(R"(^M710\s*((A[01])|(D\d+(\.\d+)?)|(I\d+(\.\d+)?)|(R)|(S\d+(\.\d+)?))?\s*((A[01])|(D\d+(\.\d+)?)|(I\d+(\.\d+)?)|(R)|(S\d+(\.\d+)?))?\s*((A[01])|(D\d+(\.\d+)?)|(I\d+(\.\d+)?)|(R)|(S\d+(\.\d+)?))?\s*((A[01])|(D\d+(\.\d+)?)|(I\d+(\.\d+)?)|(R)|(S\d+(\.\d+)?))?\s*((A[01])|(D\d+(\.\d+)?)|(I\d+(\.\d+)?)|(R)|(S\d+(\.\d+)?))?\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M710(char *gcode){

    #if ENABLED(CONTROLLER_FAN_EDITABLE)
    std::unordered_map<std::string, std::string> result = temperatureSecurity.parse_regex_gcode(m710Pattern, gcode);

        if (result.empty()) {
            // Incorrect formatting of command
            std::cout << "[Warning]: Incorrect formatting of command [" << gcode << "]" << std::endl;
            return false;
        }

        /* Check I and S params if they are OK. */
        if (result.find("I") != result.end()) {
            int speed = std::stoi(result.at("I"));
            if (!temperatureSecurity.safe_range(gcode, speed, MIN_FAN_SPEED, MAX_FAN_SPEED)) {
                return false;
            }
        }

        // Check if S param is within temp bounds
        if (result.find("S") != result.end()) {
            int speed = std::stoi(result.at("S"));
            if (!temperatureSecurity.safe_range(gcode, speed, MIN_FAN_SPEED, MAX_FAN_SPEED)) {
                return false;
            }
        }
    #else
        std::cout << "[Error]: Command: [" << gcode << "] not possible due CONTROLLER_FAN_EDITABLE not enabled in configuration." << std::endl;
        return false;
    #endif
    return false;
}