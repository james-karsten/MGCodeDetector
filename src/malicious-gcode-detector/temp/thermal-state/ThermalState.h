//
// Created by james on 23-6-2024.
//
#pragma once
#ifndef UNTITLED_THERMALSTATE_H
#define UNTITLED_THERMALSTATE_H
#include <list>
#include <string>

/* FAN SPEED */
/* Min and Max speeds Fan */
extern const int MIN_FAN_SPEED;
extern const int MAX_FAN_SPEED;

/* commands that can't have subsequent commands */
extern std::list<const char *> physical_dangerous_commands_log;

/* Commands that require cooling */
extern std::list<const char *> cooling_commands;

class ThermalState {
public:

    static void remove_item_physical_dangerous_command_log(const char *command);

    static void add_item_physical_dangerous_command_log(const char *instruction);

    static const std::list<const char *>& get_physical_dangerous_commands_log();
};

extern ThermalState thermalState;

#endif //UNTITLED_THERMALSTATE_H
