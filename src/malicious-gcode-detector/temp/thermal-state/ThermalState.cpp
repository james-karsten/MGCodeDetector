/**
 * This class keeps a global variable log of dangerous physcial commands that could
 * damage the printer when misused. For example
 * If M107 (Fans Off) is invoked, and after that the M140 S150 command is invoked (set bed temperature)
 * then this could overheat the printer
 */

#include <algorithm>
#include "ThermalState.h"
#include <string.h>
// initialize lists
const int MIN_FAN_SPEED = 0;
const int MAX_FAN_SPEED = 255;

std::list<const char *> physical_dangerous_commands_log = {};

std::list<const char *> cooling_commands = {
        "M104", // Set Hotend Temperature
        "M109", // Wait for Hotend Temperature
        "M140", // Set Bed Temperature
        "M141", // Set Chamber Temperature
        "M143", // Set Laser Cooler Temperature
        "M190", // Wait for Bed Temperature
        "M191", // Wait for Chamber Temperature
        "M193", // Set Laser Cooler Temperature
        "M303", // PID autotune
        "M306", // Model Predictive Temp. Control
        "M710" // Controller Fan settings
};

// Function to find and remove an item from the list
void ThermalState::remove_item_physical_dangerous_command_log(const char *instruction) {
    auto it = std::find_if(physical_dangerous_commands_log.begin(), physical_dangerous_commands_log.end(),
                           [instruction](const char* cmd) {
                               return strcmp(cmd, instruction) == 0;
                           });

    if (it != physical_dangerous_commands_log.end()) {
        physical_dangerous_commands_log.erase(it);
    }
}

// Adds item to physcial dangerous command log list
void ThermalState::add_item_physical_dangerous_command_log(const char *instruction) {
    physical_dangerous_commands_log.push_back(instruction);
}

// Function to get the log
const std::list<const char *>& ThermalState::get_physical_dangerous_commands_log() {
    return physical_dangerous_commands_log;
}