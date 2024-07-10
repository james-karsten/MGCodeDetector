M143 S24 ; Set maximum hot-end temperature to 250�C
M190 S90 ; Wait for bed temperature to reach 90�C
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
