/**
 * This class includes general malicious detection methods of the temperature subcategory
 */
#include <regex>
#include <iostream>
#include "TemperatureSecurity.h"

/**
 * This method extracts the temperature value from the M104 M109 command
 * @return Temperature
 */
int TemperatureSecurity::extract_temperature(char * gcode) {
    std::regex temperature_regex(R"(\bS(\d+))");
    std::cmatch temp;
    if (std::regex_search(gcode, temp, temperature_regex)) {
        return std::stoi(temp[1].str());
    }
    // error temp not found
    return -1;
}

/**
 * Checks the temperature range
 * @param gcode line
 * @param gcode_counter line number in gcode file
 * @param temp of parameter
 * @param min_temp minimum temperature threshold
 * @param max_temp maximum temperature threshold
 * @return true if temperature is between min/max temperature thresholds
 */

bool TemperatureSecurity::safe_temperature_range(char * gcode, int gcode_counter, int temp, int min_temp, int max_temp) {

    if (temp <= min_temp || temp >= max_temp) {
        std::cout << "Instruction " << gcode << " placed at line " << gcode_counter << " out of temperature range " << std::endl;
        return false;
    }

    return true;
}

/**
 * Checks the temperature range using two parameters (for autotemp)
 * @param gcode line
 * @param gcode_counter line number in gcode file
 * @param temp of parameter
 * @param min_temp minimum temperature threshold
 * @param max_temp maximum temperature threshold
 * @return true if temperature is between min/max temperature thresholds
 */

bool TemperatureSecurity::safe_temperature_range(char * gcode, int gcode_counter, int min_temp_param,
                                                 int max_temp_param, int min_temp, int max_temp) {

    if (min_temp_param > min_temp && min_temp_param < max_temp &&
        max_temp_param > min_temp_param && max_temp_param < max_temp) {
        return true;
    }

    std::cout << "Instruction " << gcode << " placed at line " << gcode_counter << " out of temperature range " << std::endl;
    return false;
}

/**
 * Checks whether gcode instruction starts at the beginning of the file
 * @param gcode line
 * @param gcode_counter line number in gcode file
 * @return return true if instruction is at beginning
 */
bool TemperatureSecurity::instruction_at_beginning (char * gcode, int gcode_counter) {
    /* Check if g-code is placed in the beginning */

    // TODO change value
    if (gcode_counter >= 15) {
        std::cout << "Instruction " << gcode << " placed at line " << gcode_counter << " which could be malicious." << std::endl;
        return false;
    }
    return true;
}

/**
 * Checks whether gcode instruction is at the end of the file
 * @param gcode line
 * @param gcode_counter line number in gcode file
 * @return return true if instruction is at end
 */
bool TemperatureSecurity::instruction_at_end (char * gcode, int gcode_counter) {
    /* Check if g-code is placed in the end */

    // TODO change value
    if (gcode_counter >= 100) {
        std::cout << "Instruction " << gcode << " placed at line " << gcode_counter << " which could be malicious." << std::endl;
        return false;
    }
    return true;
}

