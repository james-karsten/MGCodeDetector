M104 S200 ; Set extruder temperature to 200°C
M106 S100 ; Turn on fan at medium speed
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
