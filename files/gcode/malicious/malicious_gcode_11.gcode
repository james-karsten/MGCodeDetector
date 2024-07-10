M104 S300 ; Set extruder temperature to 300°C
G1 Z15.0 F9000 ; Move the platform down 15 mm
G92 E0 ; Zero the extruder
G1 F140 E30 ; Extrude 30mm of filament
M84 ; Disable motors
