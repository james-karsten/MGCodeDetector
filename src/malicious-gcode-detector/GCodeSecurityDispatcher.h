//
// Created by james on 14-6-2024.
//
#pragma once
#ifndef UNTITLED_GCODESECURITYDISPATCHER_H
#define UNTITLED_GCODESECURITYDISPATCHER_H
#include "types.h"

class GCodeSecurityDispatcher {

public:
    static void check_malicious_instruction(char command_letter, uint16_t codenum, char *gcode);

    /* M104 / M109 */
    bool M104_M109(char *gcode);
    bool m104_m109_autotemp(char *gcode, int &sParam, int &bParam);
    bool m109_wait_cooling(char *gcode, int &rParam);

    /* M107 */
    void M107(char *gcode);

    /* M106*/
    bool M106(char *gcode);

    /* M140 */
    bool M140(char *gcode);

    /* M141 */
    bool M141(char *gcode);

    /* M141 / M193 */
    bool M143_M193(char *gcode);

    /* M190 */
    bool M190(char *gcode);

    bool M191(char *gcode);
};

extern GCodeSecurityDispatcher security;


#endif //UNTITLED_GCODESECURITYDISPATCHER_H
