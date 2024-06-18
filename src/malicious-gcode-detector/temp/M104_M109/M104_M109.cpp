//
// Created by james on 14-6-2024.
//

#include "../TemperatureSecurity.h"
#include "../../GCodeSecurityDispatcher.h"

bool GCodeSecurityDispatcher::M104_M109(char * gcode, int gcode_counter) {
    TemperatureSecurity temperatureSecurity;

    /* Retract S command from M104 or M109 which sets the temperature */
    int temp = temperatureSecurity.extract_temperature(gcode);

    /* perform checks */
    if (temp != -1) {
        return temperatureSecurity.safe_temperature_range(gcode, gcode_counter, temp, 0, 300) and temperatureSecurity.instruction_at_beginning(gcode, gcode_counter);
    }

    return false;
}