M190 S75 ; Wait for bed temperature to reach 75�C
M191 S55 ; Wait for chamber temperature to reach 85�C
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
