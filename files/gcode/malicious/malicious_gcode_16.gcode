M191 S900 ; Wait for chamber temperature to reach 900�C
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
M191 S4 ; out of bounds temp
M191 S-904 ; Weird
M191 V8 X1 ; incorrect formatting
