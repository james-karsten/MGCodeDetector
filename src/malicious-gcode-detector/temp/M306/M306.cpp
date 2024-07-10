/**
 * This class warns when the M306 commmand is invoked
 */
#include <string>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"
#include "../thermal-state/ThermalState.h"

void GCodeSecurityDispatcher::M306(char *gcode) {
    /* push M107 to dangerous command (can't have subsequent commands) */
    std::string gcodeString(gcode);

    std::cout << "[Warning]: Command [" << gcodeString << "] is invoked which tunes the Model Predictive Temperature Control." << std::endl;
    return;
}


