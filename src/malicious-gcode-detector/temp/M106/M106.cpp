/**
 * This class detects the M106 commmand which sets the speed fans.
 * EXTRA_FAN_SPEED also checked against temperature bounds.
 * A warning is added because the M107 command is quite unusual.
 *
 * According to marlin firmware, Min speed = 0, Max speed = 255
 * docs: https://marlinfw.org/docs/gcode/M106.html
 */
#include <string>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"
#include <regex>
#include "../thermal-state/ThermalState.h"

/* Regex expression for EXTRA_FAN_SPEED */
const std::regex extraFanSpeed(R"(M106 P\d+ T\d+-(\d+))");
const std::regex setFanSpeed(R"(M106 P\d+ T(\d+))");


bool GCodeSecurityDispatcher::M106(char *gcode) {

    std::string gcodeString(gcode);
    std::smatch matches;

    /* Check if pattern matches for setting EXTRA_FAN_SPEED */
    if (std::regex_search(gcodeString, matches, extraFanSpeed)) { // M106 P1 T3-255

        /* if EXTRA_FAN_SPEED disabled Notify user  */
        #if DISABLED(EXTRA_FAN_SPEED)
            std::cout << "EXTRA_FAN_SPEED should be defined in the configuration for instruction " << gcode << std::endl;
            return false;
        #endif

        #if ENABLED(EXTRA_FAN_SPEED)
            /* check if the secondary speed fan has speed value*/
            if (matches.size() > 1) {

                /* retrieve speed from gcode */
                int speed = std::stoi(matches[1].str());
                return temperatureSecurity.safe_temperature_range(gcode, speed, MIN_FAN_SPEED, MAX_FAN_SPEED);
            }
        #endif
    } else if (std::regex_search(gcodeString, matches, setFanSpeed)) { // M106 P2 T2
        #if DISABLED(EXTRA_FAN_SPEED)
                std::cout << "EXTRA_FAN_SPEED should be defined in the configuration for instruction " << gcode << std::endl;
                return false;
        #endif

        return true;
    }

    /* Get speed */
    int speed = temperatureSecurity.extract_temperature(gcode);

    /* check if speed is turned off */
    if (speed == 0) {
        /* Remove M107 if it is in dangerous physcial commands */
        temperatureSecurity.command_position_allowed("M107");
        return true;
    }

    /* Check if speed is retrieved well */
    if (speed != -1) {

        /* Check if speed is within bounds */
        if (temperatureSecurity.safe_temperature_range(gcode, speed, MIN_FAN_SPEED, MAX_FAN_SPEED)) {

            /* Remove M107 from log list if speed is within bounds */
            thermalState.remove_item_physical_dangerous_command_log("M107");
            return true;
        }
    } else {
        /* Can't find speed value */
        std::cerr << "[Error]: speed value " << speed << " of Gcode command [" << gcode << "] invalid." << std::endl;
    }

    return false;
}


