/**
 * This class forms as the dispatcher for the analysis of the physical Malicious G-code detection
 *
 */

#include <iostream>
#include "GCodeSecurityDispatcher.h"
#include "types.h"
#include <vector>

/* commands that can't have subsequent commands */
std::vector<char*> dangerous_command = { };

void GCodeSecurityDispatcher::check_malicious_instruction(char command_letter, uint16_t codenum, char *gcode) {

    GCodeSecurityDispatcher security;

    /* check if dangerous command is not empty, thus has subsequent commands */
    if (!dangerous_command.empty()) {
        std::cout << "[Danger]: Command " << dangerous_command.front() << " contains subsequent commands" << std::endl;

        /* clears list of dangerous commands*/
        dangerous_command.clear();
    }

    switch (command_letter) {
        case 'M':
            switch(codenum){
                case 104:
                    security.M104_M109(gcode);
                    break;
                case 109:
                    security.M104_M109(gcode);
                    break;
                case 106:
                    security.M106(gcode);
                    break;
                case 107:
                    /* push M107 to dangerous command (can't have subsequent commands) */
                    dangerous_command.push_back(gcode);
                    security.M107(gcode);
                    break;
                case 140:
                    security.M140(gcode);
                    break;
            }
            break;


        default:
            std::cout << "No match was found";
            break;
    }
}

