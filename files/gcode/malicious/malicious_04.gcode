; This file sets the bed temperature
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M140 S120 ; Set bed temperature to 120�C
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M140 S300 ; Ensure bed temperature is set to 300�C
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M104 S0 ; Turn off extruder
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors
M140 S4 ; out of range
M140 S-100 ; out of range
M140 X1 Y1 Z1 ; wrong params
M306 ; Invoked warning when M306 command is invoked