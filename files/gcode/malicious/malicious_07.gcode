; This file waits for bed temperature
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M190 S100 ; Wait for bed temperature to reach 100�C
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M190 R500 ; Ensure bed temperature is set to 500�C
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M104 S0 ; Turn off extruder
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors
M190 S1000 ; temp out of bounds
M190 S4 ; temp out of bounds
M190 S-1 ; weird number
M190 X1 V5 ; wrong params
M190 R1000 ; temp out of bounds
M190 R4 ; temp out of bounds
M190 R-1 ; weird number
M190 X1 V5 ; wrong params