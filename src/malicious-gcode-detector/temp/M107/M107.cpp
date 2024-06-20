/**
 * This class detects the M107 commmand which turns off the fans.
 * A warning is added because the M107 command is quite unusual.
 * The method also checks whether there are any movement or heating commands after which is
 * checked in the GCodeSecurityDispatcher.cpp. This is dangerous as it can overheat the printer.
 */
#include <string>
#include <iostream>
#include "../../GCodeSecurityDispatcher.h"

void GCodeSecurityDispatcher::M107(char *gcode) {
    /* Warning for unusual command */
    std::string gcodeString(gcode);
    std::cout << "[Warning]: " << gcodeString << " is invoked which turns off the fans." << std::endl;
}


