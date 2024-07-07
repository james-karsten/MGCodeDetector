/**
 * This class detects the M143_M193 commmands
 */
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../TemperatureSecurity.h"
#include <regex>

/* Regex for M143/M193 S100 */
const std::regex m143m193SetTemperature(R"(^M1[49]3\s+S\d+\s*(;.*)?$)");

/* Regex for turning off laser cooler */
const std::regex m143TurnLaserCoolerOff(R"(^M143\s+S0\s*(;.*)?$)");

bool GCodeSecurityDispatcher::M143_M193(char *gcode) {

    /* check if Laser Cooler temperature is possible */
    #if ENABLED(LASER_FEATURE) and TEMP_SENSOR_COOLER == 1

        /* Check if laser cooler is turned off */
        std::unordered_map<std::string, std::string> result = temperatureSecurity.parse_regex_gcode(m143TurnLaserCoolerOff, gcode);

        /* return true if laser cooler is turned off */
        if (!result.empty()) {
            std::cout << "[Warning]: Command [" << gcode << "] laser cooler turned off." << std::endl;
            return true;
        }

        // match and retrieve gcode params of M140 S100
        result = temperatureSecurity.parse_regex_gcode(m143m193SetTemperature, gcode);

        /* check if result is not empty */
        if (!result.empty()) {
            int temp = stoi(result.at("S"));

            return temperatureSecurity.safe_range(gcode, temp, COOLER_MINTEMP, COOLER_MAXTEMP);
        } else {
            std::cout << "[Error]: Command [" << gcode << "] not possible due incorrect formatting." << std::endl;
            return false;
        }
    #endif

    std::cout << "[Error]: Command: " << gcode << " not possible due laser feature not enabled in configuration." << std::endl;
    return false;
}