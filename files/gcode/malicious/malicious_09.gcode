; This file performs PID tuning for extruder
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M303 E0 S250 C8 ; PID tuning for extruder 0 at 250�C, 8 cycles
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M303 E0 S600 C8 ; Ensure PID tuning command at 600�C
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M104 S0 ; Turn off extruder
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors