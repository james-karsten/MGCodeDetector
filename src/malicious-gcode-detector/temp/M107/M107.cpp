/**
 * This class detects the M107 commmand which turns off the fans.
 * A warning is added because the M107 command is quite unusual.
 * The method also checks whether there are any movement or heating commands after which is
 * checked in the GCodeSecurityDispatcher.cpp. This is dangerous as it can overheat the printer.
 */
#include <string>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../thermal-state/ThermalState.h"

void GCodeSecurityDispatcher::M107(char *gcode) {

    /* add M107 to physcial dangerous command log */
    thermalState.add_item_physical_dangerous_command_log("M107");

    /* push M107 to dangerous command (can't have subsequent commands) */
    std::string gcodeString(gcode);

    /* if LASER_SYNCHRONOUS_M106_M107 is enabled, it turns off the laser. */
    #if ENABLED(LASER_SYNCHRONOUS_M106_M107)
        std::cout << "[Warning]: Command [" << gcodeString << "] is invoked which turns off the laser." << std::endl;
    #endif

    std::cout << "[Warning]: Command [" << gcodeString << "] is invoked which turns off the fans." << std::endl;
}


