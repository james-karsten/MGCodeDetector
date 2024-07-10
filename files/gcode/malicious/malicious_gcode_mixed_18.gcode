M143 S300 ; Set maximum hot-end temperature to 300°C
M107 ; Turn off the fan
M106 S0 ; Turn off the fan
M193 S280 ; Stabilize temperature at 280°C
G1 E30 ; Extrude 30mm of filament
