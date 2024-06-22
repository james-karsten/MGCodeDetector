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

/* Min and Max speeds Fan */
const int min_speed = 0;
const int max_speed = 255;

/* Regex expression for EXTRA_FAN_SPEED */
const std::regex extraFanSpeed(R"(M106 P\d+ T\d+-(\d+))");
const std::regex setFanSpeed(R"(M106 P\d+ T(\d+))");


bool GCodeSecurityDispatcher::M106(char *gcode) {
    TemperatureSecurity temperatureSecurity;

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
                return temperatureSecurity.safe_temperature_range(gcode, speed, min_speed, max_speed);
            }
        #endif
    } else if (std::regex_search(gcodeString, matches, setFanSpeed)) { // M106 P2 T2
        #if DISABLED(EXTRA_FAN_SPEED)
                std::cout << "EXTRA_FAN_SPEED should be defined in the configuration for instruction " << gcode << std::endl;
                return false;
        #endif

        return true;
    }

    /* Get temperature */
    int temp = temperatureSecurity.extract_temperature(gcode);

    /* Check if temperature is retrieved well */
    if (temp != -1) {

        /* Check if temperature is within bounds */
        if (temperatureSecurity.safe_temperature_range(gcode, temp, min_speed, max_speed)) {
            return true;
        }
    } else {
        /* Can't find temperature value */
        std::cerr << "[Error]: Temperature value " << temp << " of Gcode command [" << gcode << "] invalid." << std::endl;
    }

    return false;
}


