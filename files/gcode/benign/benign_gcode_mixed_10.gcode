M191 S40 ; Wait for chamber temperature to reach 40�C
M193 S25 ; Stabilize temperature at 250�C
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
