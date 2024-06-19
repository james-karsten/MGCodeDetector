/**
 * This class forms as the dispatcher for the analysis of the physical Malicious G-code detection
 *
 */

#include <string>
#include <iostream>
#include "GCodeSecurityDispatcher.h"
#include "types.h"
#include <unordered_set>

void GCodeSecurityDispatcher::check_malicious_instruction(char command_letter, uint16_t codenum, char *gcode) {

    GCodeSecurityDispatcher security;

    switch (command_letter) {
        case 'M':
            case 104:
                security.M104_M109(gcode);
                break;
            case 109:
                security.M104_M109(gcode);
                break;


        default:
            std::cout << "No match was found";
            break;
    }
}

