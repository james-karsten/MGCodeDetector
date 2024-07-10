M190 S100 ; Wait for bed temperature to reach 100�C
M191 S40 ; Wait for chamber temperature to reach 100�C
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
