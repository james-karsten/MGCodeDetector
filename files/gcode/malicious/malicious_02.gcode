; This file sets the fan to uncorrect speed
G21 ; Set units to millimeters
G90 ; Use absolute positioning
M82 ; Set extruder to absolute mode
M106 S257 ; Set fan speed to maximum
G28 ; Home all axes
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
M106 S255 ; Ensure fan is at maximum speed
M106 S-100 ; invalid number
M106 G45 X1 ; invalid params
M106  ; without params
G1 F140 E30 ; Extrude 30mm of filament
G92 E0 ; Zero the extruder again
G1 F140 E30 ; Extrude 30mm of filament
G1 F140 E30 ; Extrude 30mm of filament
M107 ; Turn off fan
G28 X0 ; Home X axis
G28 Y0 ; Home Y axis
M84 ; Disable motors