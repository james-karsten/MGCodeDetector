M193 S22 ; Stabilize temperature at 280�C
M303 E-1 C8 S210 ; PID tuning (could destabilize temperature)
G21 ; Set units to millimeters
G90 ; Use absolute positioning
G1 Z15.0 F9000 ; Move the platform down 15 mm
M84 ; Disable motors