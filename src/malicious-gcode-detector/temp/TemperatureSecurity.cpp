/**
 * This class includes general malicious detection methods of the temperature subcategory
 */
#include <regex>
#include <iostream>
#include <unordered_map>
#include "TemperatureSecurity.h"
#include "thermal-state/ThermalState.h"

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

bool TemperatureSecurity::safe_temperature_range(char *gcode, int temp, int min_temp, int max_temp) {

    if (temp < min_temp || temp > max_temp) {
        std::cout << "[Danger]: Command [" << gcode  << "] out of temperature range " << std::endl;
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

bool TemperatureSecurity::safe_temperature_range(char *gcode, int min_temp_param, int max_temp_param, int min_temp,
                                                 int max_temp) {

    if (min_temp_param >= min_temp && min_temp_param <= max_temp &&
        max_temp_param >= min_temp_param && max_temp_param <= max_temp) {
        return true;
    }

    std::cout << "[Danger]: Command [" << gcode << "] out of temperature range " << std::endl;
    return false;
}

/**
 * This method checks if a gcode matches a regex pattern, if so
 * It returns with an unordered_map containing the values of the gcode
 * @param pattern regex
 * @param gcode line
 * @return nothing if no match is found, returns params in dict if match was found
 */
std::unordered_map<std::string, std::string> TemperatureSecurity::parse_regex_gcode(const std::regex& pattern, const char* gcode) {
    std::smatch match;
    std::unordered_map<std::string, std::string> params;

    // Convert char* to std::string
    std::string gcode_str(gcode);

    // Check if gcode matches
    if (std::regex_match(gcode_str, match, pattern)) {
        // Extract the entire matched string
        std::string matched = match.str(0);
        std::regex param_pattern(R"(([A-Z])(\d+(\.\d+)?))");
        std::sregex_iterator iter(matched.begin(), matched.end(), param_pattern);
        std::sregex_iterator end;

        while (iter != end) {
            std::smatch param_match = *iter;

            // param_match[1] is the key, param_match[2] is the value
            params[param_match[1].str()] = param_match[2].str();
            ++iter;
        }
    }
    return params;
}

/**
 * Checks whether specifc command comes after command which could damage printer.
 * This method considers physical_dangerous_commands_log in the ThermalState
 * Which keeps track of the dangerous physcial commands.
 * @param command_letter
 * @param codenum
 * @param gcode
 */
void TemperatureSecurity::command_position_allowed(std::string instruction) {

    /* get physical_dangerous_commands_log from ThermalState */
    std::list<const char *> physical_dangerous_command_log = thermalState.get_physical_dangerous_commands_log();

    /* check if command is logged */
    bool is_dangerous = std::find(physical_dangerous_command_log.begin(), physical_dangerous_command_log.end(), instruction) != physical_dangerous_command_log.end();

    if (is_dangerous) {
        std::cout << "[Danger]: Command [" << instruction << "] contains subsequent commands that require cooling" << std::endl;
        // Clear dangerous commands
        thermalState.remove_item_physical_dangerous_command_log(instruction.c_str());
    }
}
