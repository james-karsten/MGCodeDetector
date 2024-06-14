/**
 * This class forms as the dispatcher for the analysis of the physical Malicious G-code detection
 *
 */

#include <string>
#include <iostream>
#include "GCodeSecurity.h"
#include "types.h"
#include "temp/M104.h"


void check_malicious_instruction(const char command_letter, uint16_t codenum) {
    switch (command_letter) {
        case 'M':
            switch (codenum) {
                case 104:
                    std::cout << "instruction M104 detected";
                    M104();
                    return;
            }
            break;

        default:
            std::cout << "No match was found";
            return;
    }
}
