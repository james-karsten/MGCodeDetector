/**
 * This class forms as the dispatcher for the analysis of the physical Malicious G-code detection
 *
 */

#include <string>
#include <iostream>
#include "GCodeSecurityDispatcher.h"
#include "types.h"
#include <unordered_set>

void GCodeSecurityDispatcher::check_malicious_instruction(char command_letter, uint16_t codenum, int gcode_counter, char * gcode) {

    switch (command_letter) {
        case 'M':
            case 104:
                M104_M109(gcode, gcode_counter);
                break;
            case 109:
                M104_M109(gcode, gcode_counter);
                break;


        default:
            std::cout << "No match was found";
            break;
    }
}
