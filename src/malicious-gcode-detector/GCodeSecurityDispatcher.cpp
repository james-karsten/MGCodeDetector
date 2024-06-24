/**
 * This class forms as the dispatcher for the analysis of the physical Malicious G-code detection
 *
 */

#include "GCodeSecurityDispatcher.h"
#include "types.h"


void GCodeSecurityDispatcher::check_malicious_instruction(char command_letter, uint16_t codenum, char *gcode) {

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
                    security.M107(gcode);
                    break;
                case 140:
                    security.M140(gcode);
                    break;
                case 141:
                    security.M141(gcode);
                    break;
                case 143:
                    security.M143_M193(gcode);
                    break;
                case 190:
                    security.M190(gcode);
                    break;
                case 191:
                    security.M191(gcode);
                    break;
                case 193:
                    security.M143_M193(gcode);
                    break;
                case 303:
                    security.M303(gcode);
                    break;
            }
            break;


        default:
            break;
    }
}

