M303 X1 W3 ; wrong params
M303 E0 C5 S400 ; out of bounds (hotend)
M303 E0 C5 S2 ; out of bounds (hotend)
M303 E0 C5 S-19 ; Weird charcter (hotend)
M303 E0 C1 S19 ; C param too low (hotend)
M303 E-1 C5 S400 ; out of bounds (bedtemp)
M303 E-1 C5 S2 ; out of bounds (bedtemp)
M303 E-1 C5 S-19 ; Weird charcter (bedtemp)
M303 E-1 C2 S20 ; C param to low (bedtemp)
