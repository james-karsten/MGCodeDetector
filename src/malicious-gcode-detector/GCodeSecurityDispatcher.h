//
// Created by james on 14-6-2024.
//

#ifndef UNTITLED_GCODESECURITYDISPATCHER_H
#define UNTITLED_GCODESECURITYDISPATCHER_H
#include "types.h"

class GCodeSecurityDispatcher {

public:
    static void check_malicious_instruction(char command_letter, uint16_t codenum, int gcode_counter, char * gcode);

private:
    static bool M104_M109(char *gcode, int gcode_counter);
};

extern GCodeSecurityDispatcher security;


#endif //UNTITLED_GCODESECURITYDISPATCHER_H
