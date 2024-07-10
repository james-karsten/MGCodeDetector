M107 ; Turn off the fan
M190 S100 ; Wait for bed temperature to reach 100°C
M193 S280 ; Stabilize temperature at 280°C
M141 S100 ; Set chamber temperature to 100°C
G1 E30 ; Extrude 30mm of filament
