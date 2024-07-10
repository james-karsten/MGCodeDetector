M193 S24 ; Stabilize temperature at 270�C
M303 E0 C8 S210 ; PID tuning (could destabilize temperature)
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors
