M140 S100 ; Set bed temperature to 100°C
M106 S255 ; Turn on fan at maximum speed
M107 ; Turn off the fan
M190 S100 ; Wait for bed temperature to reach 100°C
G1 Z15.0 F9000 ; Move the platform down 15 mm
