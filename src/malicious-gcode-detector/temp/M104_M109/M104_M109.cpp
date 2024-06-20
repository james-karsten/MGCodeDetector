//
// Created by james on 14-6-2024.
//

#include <string>
#include <regex>
#include "../TemperatureSecurity.h"
#include "../../GCodeSecurityDispatcher.h"

bool GCodeSecurityDispatcher::M104_M109(char *gcode) {
    TemperatureSecurity temperatureSecurity;

    /* S (mintemp) and B (maxtemp) for possible autotemp command */
    int sParam = 0, bParam = 0, rParam = 0;

    /* M109 check wait for cooling */
    if (m109_wait_cooling(gcode, rParam)) {
        return true;
    }

    /* Check if M104 uses autotemp and is within bounds of heater */
    if (m104_m109_autotemp(gcode, sParam, bParam)) {
        return true;
    }

    /* Retract S command from M104 or M109 which sets the temperature */
    int temp = temperatureSecurity.extract_temperature(gcode);

    /* perform checks with normal S command */
    if (temp != -1) {
        return temperatureSecurity.safe_temperature_range(gcode, temp, HEATER_0_MINTEMP, HEATER_0_MAXTEMP);
    }

    return false;
}

/**
 * Checks if M104/M109 command uses autotemp pattern
 * @param gcode line
 * @param sParam S value in autotemp command
 * @param bParam B value in autotemp command
 * @return true if autotemp is used and within bounds, otherwise false
 */
bool GCodeSecurityDispatcher::m104_m109_autotemp(char *gcode, int &sParam, int &bParam) {
    // Convert char* to std::string
    std::string gcodeString(gcode);

    std::regex autotempPattern(R"(^M10[49]\sF(?:\sS(\d+))?(?:\sB(\d+))?(?:\sS(\d+))?(?:\sB(\d+))?$)");
    std::smatch matches;

    if (std::regex_match(gcodeString, matches, autotempPattern)) {
        // Initialize parameters to default values
        sParam = 0;
        bParam = 0;

        // Extract matched values for S and B, considering any order
        for (size_t i = 1; i < matches.size(); ++i) {
            if (matches[i].matched) {
                if (i == 1 || i == 3) {  // Positions where S might be matched
                    sParam = std::stoi(matches[i].str());
                } else if (i == 2 || i == 4) {  // Positions where B might be matched
                    bParam = std::stoi(matches[i].str());
                }
            }
        }

        // check if values are in safe temperature range
        if(temperatureSecurity.safe_temperature_range(gcode, sParam, bParam,
                                                      HEATER_0_MINTEMP, HEATER_0_MAXTEMP)) {
            return true;
        }
        return false;
    }
    return false;
}

/**
 * Checks if M109 uses wait for cooling command and is within bounds
 * @param gcode line
 * @param sParam S value in autotemp command
 * @param bParam B value in autotemp command
 * @return true if autotemp is used and within bounds, otherwise false
 */
bool GCodeSecurityDispatcher::m109_wait_cooling(char *gcode, int &rParam) {
    // Convert char* to std::string
    std::string gcodeString(gcode);

    // Regular expression for M109 R105 or M109 T1 R106
    std::regex waitCoolingRegex(R"(^M109(\sT\d+)?(\sR(\d+))?(\sS(\d+))?$)");
    std::smatch matches;

    // Check for match
    if (std::regex_match(gcodeString, matches, waitCoolingRegex)) {

        if (matches[3].matched) {  // Check if R is matched
            rParam = std::stoi(matches[3].str());
        } else if (matches[5].matched) {  // Check if S is matched
            rParam = std::stoi(matches[5].str());
        } else {
            return false;  // No R or S parameter found
        }

        //  Check if R command is within bounds
        if (temperatureSecurity.safe_temperature_range(gcode, rParam, HEATER_0_MINTEMP, HEATER_0_MAXTEMP)) {
            return true;
        }
        return false;
    }
    return false;
}