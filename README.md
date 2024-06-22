# Malicious G-code detection tool
This tool aims to detect malicious G-code. The tool reuses the G-code parser component that resides in the Marlin firmware (version bugfix-2.1.x): https://github.com/MarlinFirmware/Marlin/blob/bugfix-2.1.x/Marlin/src/gcode/parser.cpp


## Modifications to Marlin G-code parser
The parser is partly modified to run the standalone component. Commented code that was utilized in the original parser is denoted with  // [T] {reason commented out}.
Some unnecessary dependencies have been removed to limit the scope of the project.

## Submodules
This project utilizes the Google test framework for C++: https://github.com/google/googletest
When cloning this repository, be sure to include the submodules as well using

```git clone --recurse-submodules https://github.com/james-karsten/MGCodeDetector.git```

The submodules can be initialized by this command when the repository is already cloned.

```git clone --recurse-submodules https://github.com/james-karsten/MGCodeDetector.git```

# Documentation of code
This section serves as documentation for all additional code around the Marlin parser.

## 1. Invalid G-code syntax detection: _detect_invalid_gcode()_ method in _parser.cpp_
This method is added to prevent invalid syntax of G-code from being parsed by the parser. It uses case-sensitive or insensitive regular expressions that validate the syntax of the G-code line that was passed as a parameter in the _parse()_ method. When the syntax is invalid, the function will stop.

**G-code syntax regex**:

```^([GMT]\d+)((\s+[XYZEFSPIJKDHLQWUVOR](-?\d+(\.\d*)?)?)*)\s*$```

**Breakdown**:

- ```([GMT]\d+)``` = Line has to start with G, M or T followed by one or more digits.
- ```((\s+[XYZEFSPIJKDHLQWUVOR](-?\d+(\.\d*)?)?)``` = Line follows with one of the characters listed at the left which are the parameters or flags of the G-code. This includes negative numbers, subcodes (X30.3) or one or more digits (X1 or X132). It can also be repeated zero or multiple times, so no parameters or multiple parameters are possible.
- ```s\*``` = Matches zero or more whitespace at the end of the g-code line.

Tests of this regular expression can be found in the test file _InvalidGCodeParser.cpp_ under the _Google_tests_ folder: https://github.com/james-karsten/MGCodeDetector/blob/invalid-gcode-detection/Google_tests/InvalidGCodeParser.cpp

## 2. GCodeFileReader
This class takes a .gco file as input and tries to parse each line. It is a fairly simple class.
It also performs additional checks whether the file is readable and has a .gco file extension.

## 2. Malicious detection techniques

This section describes several different detection techniques for specific subcategories. The subcategories
of the commands are based on supported G-code instruction on the Marlin website: https://marlinfw.org/meta/gcode/
The commands are also listed in appendix A.

### Thermal

This section serves as the description for the Thermal subcategory. The thermal subcategory has a few general
detection methods

- temperature range = checks whether given G-code parameters are within boundaries based on the thresholds of the users configuration file.
- instruction position = checks where the G-code instruction has subsequent commands. (e.g. turning off fans should not 
have subsequent commands that require cooling).
- TODO occurance = checks how many times a thermal instruction occured in a .gco file

#### M104 / M109
- The M104 and M109 has additional checks if the temperatures are within boundaries.
This functionality is also implemented when AUTOTEMP is used (examples: https://marlinfw.org/docs/gcode/M104.html)

#### M106
- Gives warning when S temperature is set to high
- Also checks temperature of EXTRA_FAN_SPEED when M106 P<fan> T3-255 is used (examples: https://marlinfw.org/docs/gcode/M106.html). 

#### M107
- Gives warning when instruction is used
- Checks wheter instruction has subsequent commands. If so, it states it in output. (e.g. If M104 command is invoked after
the fans are turned off, the printer might get overheated)

#### M140
- If ```M140 S100``` is used, checks on temperature bounds.
- If ```M140 P1``` is used, check will pass. If any other format is used, returns false.

#### M141
- If ```M140 S100``` is used, checks on temperature bounds
- If other format is used, returns false.

#### M143 / M193
- checks if laser feature is enabled
- If ```M143/M193 S100``` is used, checks on temperature bounds
- If ```M143 S0``` is used give user warning


# Appendices

## A Subcategories physcial G-code commmands supported by the Marlin firmware

| G-code Command                         | Version        | Subcategory                       | Variables                                                                 | Description                                              |
|----------------------------------------|----------------|-----------------------------------|--------------------------------------------------------------------------|----------------------------------------------------------|
| M126 - Baricuda 1 Open                 | N/A            | baricuda                          | BARICUDA                                                                 | Open the valve for Baricuda 1.                           |
| M127 - Baricuda 1 Close                | N/A            | baricuda                          | BARICUDA                                                                 | Close the valve for Baricuda 1.                          |
| M128 - Baricuda 2 Open                 | N/A            | baricuda                          | BARICUDA                                                                 | Open the valve for Baricuda 2.                           |
| M129 - Baricuda 2 Close                | N/A            | baricuda                          | BARICUDA                                                                 | Close the valve for Baricuda 2.                          |
| G26 - Mesh Validation Pattern          | 1.1.0          | calibration                       | G26_MESH_VALIDATION                                                     | Test the mesh and adjust.                                |
| G28 - Auto Home                        | N/A            | calibration                       | N/A                                                                      | Auto home one or more axes.                              |
| G29 - Bed Leveling                     | N/A            | calibration                       | AUTO_BED_LEVELING_(3POINT|LINEAR|BILINEAR|UBL)|MESH_BED_LEVELING       | Probe the bed and enable leveling compensation.          |
| G29 - Bed Leveling (3-Point)           | N/A            | calibration                       | AUTO_BED_LEVELING_3POINT                                                | Probe the bed and enable leveling compensation.          |
| G29 - Bed Leveling (Bilinear)          | N/A            | calibration                       | AUTO_BED_LEVELING_BILINEAR                                              | Probe the bed and enable leveling compensation.          |
| G29 - Bed Leveling (Linear)            | N/A            | calibration                       | AUTO_BED_LEVELING_LINEAR                                                | Probe the bed and enable leveling compensation.          |
| G29 - Bed Leveling (Manual)            | N/A            | calibration                       | MESH_BED_LEVELING                                                       | Measure Z heights in a grid, enable leveling compensation|
| G29 - Bed Leveling (Unified)           | N/A            | calibration                       | AUTO_BED_LEVELING_UBL                                                   | Probe the bed and enable leveling compensation.          |
| G30 - Single Z-Probe                   | 1.0.0-beta     | calibration                       | HAS_BED_PROBE                                                           | Probe bed at current XY location.                        |
| G31 - Dock Sled                        | 1.0.0-beta     | calibration                       | Z_PROBE_SLED                                                            | Dock the Z probe sled.                                   |
| G32 - Undock Sled                      | 1.0.0-beta     | calibration                       | Z_PROBE_SLED                                                            | Undock the Z probe sled.                                 |
| G34 - Mechanical Gantry Calibration    | 2.0.4          | calibration                       | MECHANICAL_GANTRY_CALIBRATION                                           | Modern replacement for Průša's TMC_Z_CALIBRATION         |
| G34 - Z Steppers Auto-Alignment        | N/A            | calibration                       | Z_STEPPER_AUTO_ALIGN                                                    | Align multiple Z steppers using a bed probe.             |
| G35 - Tramming Assistant               | N/A            | calibration                       | ASSISTED_TRAMMING                                                       | Run a procedure to tram the bed.                         |
| G38.2-G38.5 - Probe target             | 1.1.0          | calibration                       | G38_PROBE_TARGET                                                        | Probe towards (or away from) a workpiece.                |
| G42 - Move to mesh coordinate          | 1.1.2          | calibration                       | HAS_MESH                                                                | Move to a specific point in the leveling mesh.           |
| G425 - Backlash Calibration            | N/A            | calibration                       | CALIBRATION_GCODE                                                       | Use a conductive object to calibrate XYZ backlash.       |
| G76 - Probe temperature calibration    | N/A            | calibration                       | PROBE_TEMP_COMPENSATION                                                 | Calibrate probe temperature compensation.                |
| M102 - Configure Bed Distance Sensor   | 2.1.1          | calibration                       | BD_SENSOR                                                               | Set parameters for the Bed Distance Sensor.              |
| M192 - Wait for Probe temperature      | 2.0.6.2        | calibration                       | PROBE_TEMP_COMPENSATION                                                 | Wait for the probe temperature sensor to reach a target. |
| M290 - Babystep                        | 1.1.7          | calibration                       | BABYSTEPPING                                                            | Babystep one or more axes.                               |
| M401 - Deploy Probe                    | N/A            | calibration                       | N/A                                                                      | Deploy the bed probe.                                    |
| M402 - Stow Probe                      | N/A            | calibration                       | HAS_BED_PROBE                                                           | Stow the bed probe.                                      |
| M48 - Probe Repeatability Test         | N/A            | calibration                       | Z_MIN_PROBE_REPEATABILITY_TEST                                          | Measure Z Probe repeatability.                           |
| G33 - Delta Auto Calibration           | 1.1.0          | calibrationdelta                  | DELTA_AUTO_CALIBRATION                                                  | Calibrate various Delta parameters.                      |
| M10-M11 - Vacuum / Blower Control      | 2.0.8          | control                           | AIR_EVACUATION                                                          | Enable and disable the Cutter Vacuum or Laser Blower Motor.|
| M120 - Enable Endstops                 | N/A            | control                           | N/A                                                                      | Enable endstops and keep them enabled even when not homing.|
| M121 - Disable Endstops                | N/A            | control                           | N/A                                                                      | Disable endstops and keep them disabled when not homing.|
| M17 - Enable Steppers                  | N/A            | control                           | N/A                                                                      | Enable steppers.                                         |
| M18, M84 - Disable steppers            | N/A            | control                           | N/A                                                                      | Disable steppers (same as M84).                          |
| M3 - Spindle CW / Laser On             | 1.1.2          | control                           | SPINDLE_LASER_ENABLE                                                    | Set the spindle CW speed or laser power.                 |
| M355 - Case Light Control              | N/A            | control                           | CASE_LIGHT_PIN                                                          | Turn the case light on or off, set brightness.           |
| M360 - SCARA Theta A                   | N/A            | control                           | MORGAN_SCARA                                                            | Move to Theta A.                                         |
| M361 - SCARA Theta-B                   | N/A            | control                           | MORGAN_SCARA                                                            | Move to Theta-B.                                         |
| M362 - SCARA Psi-A                     | N/A            | control                           | MORGAN_SCARA                                                            | Move to Psi-A.                                           |
| M363 - SCARA Psi-B                     | N/A            | control                           | MORGAN_SCARA                                                            | Move to Psi-B.                                           |
| M364 - SCARA Psi-C                     | N/A            | control                           | MORGAN_SCARA                                                            | Move to Psi-C.                                           |
| M4 - Spindle CCW / Laser On            | 1.1.2          | control                           | SPINDLE_LASER_ENABLE                                                    | Set the spindle CCW speed or laser power.                |
| M405 - Filament Width Sensor On        | N/A            | control                           | FILAMENT_WIDTH_SENSOR                                                   | Enable filament width sensor flow control.               |
| M406 - Filament Width Sensor Off       | N/A            | control                           | FILAMENT_WIDTH_SENSOR                                                   | Disable filament width sensor flow control.              |
| M5 - Spindle / Laser Off               | 1.1.2          | control                           | SPINDLE_LASER_ENABLE                                                    | Turn off spindle or laser.                               |
| M7-M9 - Coolant Controls               | N/A            | control                           | N/A                                                                      | Turn mist or flood coolant on / off.                     |
| M701 - Load filament                   | N/A            | control                           | NOZZLE_PARK_FEATURE, ADVANCED_PAUSE_FEATURE, FILAMENT_LOAD_UNLOAD_GCODES| Load filament.                                           |
| M702 - Unload filament                 | N/A            | control                           | NOZZLE_PARK_FEATURE, ADVANCED_PAUSE_FEATURE, FILAMENT_LOAD_UNLOAD_GCODES| Unload filament.                                         |
| M80 - Power On                         | N/A            | control                           | PSU_CONTROL                                                             | Turn on the power supply.                                |
| M81 - Power Off                        | N/A            | control                           | PSU_CONTROL                                                             | Turn off the power supply.                               |
| M85 - Inactivity Shutdown              | N/A            | control                           | N/A                                                                      | Set the inactivity timeout.                              |
| M86 - Hotend Idle Timeout              | 2.1.3          | control                           | HOTEND_IDLE_TIMEOUT                                                     | Set the hotend idle timeout.                             |
| M900 - Linear Advance Factor           | N/A            | control                           | LIN_ADVANCE                                                             | Get and set Linear Advance K value.                      |
| M907 - Set Motor Current               | N/A            | control                           | DIGIPOTSS_PIN|HAS_MOTOR_CURRENT_PWM|DIGIPOT_I2C|DAC_STEPPER_CURRENT       | Set motor current via digital trimpot.                   |
| M908 - Set Trimpot Pins                | N/A            | control                           | DAC_STEPPER_CURRENT|DIGIPOTSS_PIN                                       | Set a digital trimpot directly.                          |
| M915 - TMC Z axis calibration          | N/A            | control                           | TMC2130, TMC_Z_CALIBRATION                                              | Align ends of the Z axis and test torque.                || G-code Command                         | Version        | Subcategory                       | Variables                                                                 | Description                                              |
| M999 - STOP Restart             | N/A            | control         | N/A                          | Return the machine to Running state                      |
| T?-Tx - MMU2 Special Commands   | 2.0.0          | control         | N/A                          | MMU2 special filament loading commands                   |
| T0-T7 - Select or Report Tool   | N/A            | control         | N/A                          | Set or report the current extruder or other tool         |
| M7219 - MAX7219 Control         | N/A            | debug           | MAX7219_DEBUG                | Control Max7219 Segmented LEDs                           |
| M862                           | 1.0.0-beta     | encoder         | I2C_POSITION_ENCODERS        | Perform an axis continuity test for position encoder modules |
| M863                           | 1.0.0-beta     | encoder         | I2C_POSITION_ENCODERS        | Perform steps-per-mm calibration for position encoder modules |
| M600 - Filament Change          | 1.1.0          | filament        | ADVANCED_PAUSE_FEATURE       | Automatically change filament                            |
| G53 - Move in Machine Coordinates | N/A          | geometry        | CNC_COORDINATE_SYSTEMS       | Apply native workspace to the current move               |
| M916 - L6474 Thermal Warning Test | N/A          | L6474           | MONITOR_L6470_DRIVER_STATUS  | Find L6474 drive level (KVAL_HOLD) threshold             |
| M917 - L6474 Overcurrent Warning Test | N/A       | L6474           | MONITOR_L6470_DRIVER_STATUS  | Find L6474 minimum current thresholds                    |
| M918 - L6474 Speed Warning Test | N/A            | L6474           | MONITOR_L6470_DRIVER_STATUS  | Find L6474 speed threshold                               |
| M300 - Play Tone                | N/A            | lcd             | SPEAKER                      | Play a single tone, buzz, or beep                        |
| G0-G1 - Linear Move             | 1.0.0-beta     | motion          | N/A                          | Add a straight line movement to the planner              |
| G10 - Retract                          | 1.0.0-beta     | motion                            | FWRETRACT                                                               | Retract the filament.                                    |
| G11 - Recover                          | 1.0.0-beta     | motion                            | FWRETRACT                                                               | Recover the filament with firmware-based retract.        |
| G2-G3 - Arc or Circle Move             | 1.0.0-beta     | motion                            | ARC_SUPPORT                                                             | Add an arc or circle movement to the planner.            |
| G5 - Bézier cubic spline               | 1.1.0          | motion                            | N/A                                                                      | Cubic B-spline with XYE destination and IJPQ offsets.    |
| G6 - Direct Stepper Move               | N/A            | motion                            | DIRECT_STEPPING                                                         | Perform a direct, uninterpolated, and non-kinematic synchronized move.|
| G80 - Cancel Current Motion Mode       | N/A            | motion                            | GCODE_MOTION_MODES                                                      | Cancel the current motion mode.                          |
| M410 - Quickstop                       | N/A            | motion                            | N/A                                                                      | Stop all steppers instantly.                             |
| M380 - Activate Solenoid               | N/A            | none                              | EXT_SOLENOID                                                            | Activate.                                                |
| M381 - Deactivate Solenoids            | N/A            | none                              | EXT_SOLENOID                                                            | Deactivate all extruder solenoids.                       |
| M906 - Stepper Motor Current           | N/A            | none                              | TMC2130|TMC2208|TMC2660|L64xx                                            | Set the motor current (in milliamps).                    |
| G12 - Clean the Nozzle                 | 1.1.0          | nozzle                            | NOZZLE_CLEAN_FEATURE                                                    | Perform the nozzle cleaning procedure.                   |
| G27 - Park toolhead                    | 1.1.0          | nozzle                            | NOZZLE_PARK_FEATURE                                                     | Park the current toolhead.                               |
| M125 - Park Head                       | N/A            | nozzle                            | PARK_HEAD_ON_PAUSE                                                      | Save current position and move to filament change position.|
| M112 - Full Shutdown                   | N/A            | safety                            | N/A                                                                      | Shut everything down and halt the machine.               |
| M486 - Cancel Objects                  | N/A            | sdcard                            | CANCEL_OBJECTS                                                          | Identify and cancel objects.                             |
| M524 - Abort SD print                  | 2.0.0          | sdcard                            | SDSUPPORT                                                               | Abort an SD print started with M24.                      |
| M540 - Endstops Abort SD               | N/A            | sdcard                            | SDSUPPORT, SD_ABORT_ON_ENDSTOP_HIT                                      | Abort SD printing when an endstop is triggered.          |
| M280 - Servo Position                  | N/A            | servos                            | NUM_SERVOS>0                                                            | Set or get a servo position.                             |
| M281 - Edit Servo Angles               | 2.0.0          | servos                            | EDITABLE_SERVO_ANGLES                                                   | Set servo deploy and/or stow angles.                     |
| M282 - Detach Servo                    | 2.0.9.2        | servos                            | SERVO_DETACH_GCODE                                                      | Detach a servo until its next move.                      |
| M104 - Set Hotend Temperature          | N/A            | thermal                           | N/A                                                                      | Set a new target hot end temperature.                    |
| M106 - Set Fan Speed                   | N/A            | thermal                           | EXTRA_FAN_SPEED                                                         | Turn on fan and set speed.                               |
| M107 - Fan Off                         | N/A            | thermal                           | N/A                                                                      | Turn off a fan.                                          |
| M109 - Wait for Hotend Temperature     | N/A            | thermal                           | N/A                                                                      | Wait for the hot end to reach its target.                |
| M140 - Set Bed Temperature             | N/A            | thermal                           | N/A                                                                      | Set a new target bed temperature.                        |
| M141 - Set Chamber Temperature         | N/A            | thermal                           | N/A                                                                      | Set a new target chamber temperature.                    |
| M143 - Set Laser Cooler Temperature    | 2.0.8          | thermal                           | TEMP_SENSOR_COOLER, TEMP_COOLER_PIN, COOLER_PIN, LASER_FEATURE          | Set a new target laser coolant temperature.              |
| M190 - Wait for Bed Temperature        | N/A            | thermal                           | N/A                                                                      | Wait for the bed to reach target temperature.            |
| M191 - Wait for Chamber Temperature    | N/A            | thermal                           | N/A                                                                      | Wait for the chamber to reach target temperature.        |
| M193 - Set Laser Cooler Temperature    | 2.0.8          | thermal                           | TEMP_SENSOR_COOLER, TEMP_COOLER_PIN, COOLER_PIN, LASER_FEATURE          | Set a new target laser coolant temperature.              |
| M303 - PID autotune                    | N/A            | thermal                           | PIDTEMP|PIDTEMPBED                                                      | Auto-tune the PID system to find stable values.          |
| M306 - Model Predictive Temp. Control  | 2.0.9.4        | thermal                           | MPCTEMP                                                                 | Set MPC values for a hotend.                             |
| M710 - Controller Fan settings         | 2.0.5.2        | thermal                           | CONTROLLER_FAN_EDITABLE                                                 | Set or report controller fan settings.                   |


