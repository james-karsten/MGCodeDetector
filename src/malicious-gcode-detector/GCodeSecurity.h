//
// Created by james on 14-6-2024.
//

#ifndef UNTITLED_GCODESECURITY_H
#define UNTITLED_GCODESECURITY_H
#include "types.h"

class GCodeSecurity {

public:
    static void check_malicious_instruction(const char command_letter, uint16_t codenum);

private:

};


#endif //UNTITLED_GCODESECURITY_H
