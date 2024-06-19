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
    bool M104_M109(char *gcode, int gcode_counter, int codenum);
    bool m104_m109_autotemp(char *gcode, int &sParam, int &bParam,  int & gcode_counter);
    bool m109_wait_cooling(char *gcode, int & rParam, int & gcode_counter);
};

extern GCodeSecurityDispatcher security;


#endif //UNTITLED_GCODESECURITYDISPATCHER_H
