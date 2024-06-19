//
// Created by james on 18-6-2024.
//

#ifndef UNTITLED_TEMPERATURESECURITY_H
#define UNTITLED_TEMPERATURESECURITY_H


class TemperatureSecurity {

public:
    static int extract_temperature(char * gcode);
    static bool safe_temperature_range(char * gcode, int gcode_counter, int temp, int min_temp, int max_temp);
    static bool safe_temperature_range(char * gcode, int gcode_counter, int min_temp_param, int max_temp_param,
                                       int min_temp, int max_temp);
    static bool instruction_at_beginning (char * gcode, int gcode_counter);
    static bool instruction_at_end (char * gcode, int gcode_counter);
};

extern TemperatureSecurity temperatureSecurity;


#endif //UNTITLED_TEMPERATURESECURITY_H
