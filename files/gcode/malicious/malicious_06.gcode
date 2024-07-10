; This file sets maximum hot-end temperature and stabilizes temperature
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M143 S300 ; Set maximum hot-end temperature to 300�C
M193 S280 ; Stabilize temperature at 280�C
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M143 S300 ; Ensure maximum hot-end temperature is set to 300�C
M193 S280 ; Ensure temperature stabilizes at 280�C
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M104 S0 ; Turn off extruder
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors
M143 S4 ; Below threshold
M143 S-2 ; weird number
M143 V5 ; incorrect param
M193 S3 ; Below threshold
M193 S-11 ; weird number
M193 X1 ; incorrect param


