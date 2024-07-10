; v This file sets and waits for extruder temperature
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M104 S300 ; Set extruder temperature to 300°C
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M109 S300 ; Wait for extruder to reach 300°C
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M104 S0 ; Turn off extruder
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors
M104 S1 ; temp to low
M109 S1 ; temp to low
M104 X1 ; wrong param
M109 Z5 ; wrong param