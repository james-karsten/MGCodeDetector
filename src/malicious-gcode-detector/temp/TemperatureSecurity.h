//
// Created by james on 18-6-2024.
//

#ifndef UNTITLED_TEMPERATURESECURITY_H
#define UNTITLED_TEMPERATURESECURITY_H


class TemperatureSecurity {

public:
    static int extract_temperature(char * gcode);
    static bool safe_temperature_range(char *gcode, int temp, int min_temp, int max_temp);
    static bool safe_temperature_range(char *gcode, int min_temp_param, int max_temp_param, int min_temp,
                                       int max_temp);
};

extern TemperatureSecurity temperatureSecurity;


#endif //UNTITLED_TEMPERATURESECURITY_H
