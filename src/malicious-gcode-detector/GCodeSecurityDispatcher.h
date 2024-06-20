//
// Created by james on 14-6-2024.
//

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
};


#endif //UNTITLED_GCODESECURITYDISPATCHER_H
