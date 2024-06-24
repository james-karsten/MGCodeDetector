//
// Created by james on 18-6-2024.
//
#pragma once
#ifndef UNTITLED_TEMPERATURESECURITY_H
#define UNTITLED_TEMPERATURESECURITY_H
#include <unordered_map>
#include <regex>
#include <list>

class TemperatureSecurity {

public:
    static int extract_temperature(char * gcode);
    static bool safe_temperature_range(char *gcode, int temp, int min_temp, int max_temp);
    static bool safe_temperature_range(char *gcode, int min_temp_param, int max_temp_param, int min_temp,
                                       int max_temp);
    static std::unordered_map<std::string, std::string> parse_regex_gcode(const std::regex& pattern, const char* gcode);

    static void command_position_allowed(std::string instruction);
};

extern TemperatureSecurity temperatureSecurity;


#endif //UNTITLED_TEMPERATURESECURITY_H
