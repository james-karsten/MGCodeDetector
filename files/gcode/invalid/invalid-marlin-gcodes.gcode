; (mix of GPT generated and self-generated invalid commands)
; General regex invalid G-codes
G1X10Y20Z30    ; Missing spaces
G1.1X10Y20     ; Invalid G-code format
G1 X10 Y20 Z30 # Comment with other character
G92..1         ; Double decimal point
!        ; invalid char
A2 X0 ; not a G-code command
G 92.1         ; Space in command
M104S190       ; Missing space after command
T1E1           ; Invalid T-code
G1 X10 Y20 Z30 extra         ; Extra text at the end
G1 X10,Y20,Z30               ; Commas instead of spaces
G1 X10 Y20 Z30.3.3           ; Double decimal point in number
G1 X10 Y20 Z30@#             ; Invalid character
G1 X10 -20                   ; Invalid param
M1X10 Y20                    ; Invalid M-code
this is a test               ; sentence invalid
234567890                    ; number sequence
,.<><>                       ; special character sequence
G1 X---10                    ; triple minus
G80 M,                       ; Parameter with comma
G90 M-M-M-M-M                ; Parameter chain with M
G+8                          ; special character between number and param
G1~ X0                       ; special character after codenum
G4.4 3.3                     ; G-code subcode with invalid param
GrG                          ; invalid format GrG
G1 X1 T1 M1 T1 Z1 /filepath/ ; invalid params
G1 !/filepath                ; invalid filepath
T1 !.fielpath                ; invalid Filepath
M456 /test                   ; invalid filepath
G1 X10 20 Z30                ; Missing parameter letter
G1X10 Y20Z30                 ; Missing spaces
G1 X10.5.5 Y20               ; Double decimal point
G1 X10 Y20 Z 30              ; Space in number
G1 X10 Y20 Z30E              ; Missing number after parameter
G1 X10Y20 Z30!               ; Invalid character
M23X10 Y20 Z30               ; Invalid M-code
G X10 Y20 Z30                ; Missing command number
G1 X10 Y20 Z-30.             ; Trailing decimal point
G1 X10Y20Z30; Comment        ; Missing spaces
G1 X10..5 Y20 Z30            ; Double decimal point
G1 X10 Y20Z30                ; Missing space
G1 X10 20                    ; Missing parameter letter
G1 X10 Y20 Z30.3.3.3         ; Triple decimal point
G1 X10 Y20 Z30E5F6           ; No space between parameters
G1 X10 Y20 Z30# Comment      ; Invalid character
G1 X10.5 Y20..5 Z30          ; Double decimal point
G1 X10 Y20 Z-30@#            ; Invalid character
G1 X10 Y20 Z30 extra text    ; Extra text at the end
G1 X10, Y20, Z30             ; Commas instead of spaces
G1 X10 Y20 Z30..             ; Trailing double decimal point
G1 X10 Y20 Z30.              ; Trailing decimal point
G1 X10 Y20 Z30@@             ; Double special character
G1 X10 Y20 Z30#              ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30-              ; Trailing negative sign
G1 X10 Y20 Z30E-5F-6         ; No space between parameters with negatives
G1 X10..5 Y20 Z30.5          ; Double decimal point
G1 X10 Y20 Z-30@             ; Invalid character
G1 X10 Y20 Z30# Comment      ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30E5F6G7         ; No space between parameters
G1 X10 Y20 Z30...            ; Triple trailing decimal point
G1 X10 Y20 Z-30#             ; Invalid character
G1 X10.5 Y20 Z30..5          ; Double decimal point
G1 X10 Y20 Z30-              ; Trailing negative sign
G1 X10 Y20 Z30.3.3.3         ; Triple decimal point
G1 X10 Y20 Z30# Comment      ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30E5F6G7         ; No space between parameters
G1 X10 Y20 Z30E-5F-6         ; No space between parameters with negatives
G1 X10..5 Y20 Z30.5          ; Double decimal point
G1 X10 Y20 Z-30@             ; Invalid character
G1 X10 Y20 Z30.              ; Trailing decimal point
G1 X10 Y20 Z30#              ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30E5F6G7         ; No space between parameters
G1 X10 Y20 Z30...            ; Triple trailing decimal point
G1 X10 Y20 Z-30#             ; Invalid character
G1 X10.5 Y20 Z30..5          ; Double decimal point
G1 X10 Y20 Z30-              ; Trailing negative sign
G1 X10 Y20 Z30.3.3.3         ; Triple decimal point
G1 X10 Y20 Z30# Comment      ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30E5F6G7         ; No space between parameters
G1 X10 Y20 Z30E-5F-6         ; No space between parameters with negatives
G1 X10..5 Y20 Z30.5          ; Double decimal point
G1 X10 Y20 Z-30@             ; Invalid character
G1 X10 Y20 Z30.              ; Trailing decimal point
G1 X10 Y20 Z30#              ; Invalid character
G1 X10.5.5 Y20 Z30           ; Double decimal point
G1 X10 Y20 Z30E5F6G7         ; No space between parameters
G1 X10 Y20 Z30...            ; Triple trailing decimal point
G1 X10 Y20 Z-30#             ; Invalid character
G1 X10.5 Y20 Z30..5          ; Double decimal point
G1 X10 Y20 Z30-              ; Trailing negative sign
G1 X10 Y20 Z30.3.3.3         ; Triple decimal point
G1 X10 Y20 Z30# Comment      ; Invalid character

; G61 Regex regex invalid G-codes
G61X10Y20    ; Missing spaces
G61 Xniet*12
G61.1X10Y20  ; Invalid G-code format
G61 X10 Y20 Z30extra         ; Extra text at the end
G61 X10,Y20,Z30               ; Commas instead of spaces
G61 X10 Y20 Z30.3.3           ; Double decimal point in number
G61 X10 Y20 Z30@#             ; Invalid character
G61X10 Y20                    ; Missing spaces
G61 X10 20 Z30                ; Missing parameter letter
G61X10 Y20Z30                 ; Missing spaces
G61 X10.5.5 Y20               ; Double decimal point
G61 X10 Y20 Z30E              ; Missing number after parameter
G61 X10Y20 Z30!               ; Invalid character
G61 X10 Y20 Z-30.             ; Trailing decimal point
G61 X10Y20Z30; Comment        ; Missing spaces
G61 X10..5 Y20 Z30            ; Double decimal point
G61 X10 Y20Z30                ; Missing space
G61 X10 20                    ; Missing parameter letter
G61 X10 Y20 Z30.3.3.3         ; Triple decimal point
G61 X10 Y20 Z30E5F6           ; No space between parameters
G61 X10 Y20 Z30# Comment      ; Invalid character
G61 X10.5 Y20..5 Z30          ; Double decimal point
G61 X10 Y20 Z-30@#            ; Invalid character
G61 X10, Y20, Z30             ; Commas instead of spaces
G61 X10 Y20 Z30..             ; Trailing double decimal point
G61 X10 Y20 Z30.              ; Trailing decimal point
G61 X10 Y20 Z30@@             ; Double special character
G61 X10 Y20 Z30#              ; Invalid character
G61 X10.5.5 Y20 Z30           ; Double decimal point
G61 X10 Y20 Z30-              ; Trailing negative sign
G61 X10 Y20 Z30E-5F-6         ; No space between parameters with negatives
G61 X10..5 Y20 Z30.5          ; Double decimal point
G61 X10 Y20 Z-30@             ; Invalid character
G61 X10 Y20 Z30# Comment      ; Invalid character
G61 X10.5.5 Y20 Z30           ; Double decimal point
G61 X10 Y20 Z30E5F6G7         ; No space between parameters
G61 X10 Y20 Z30...            ; Triple trailing decimal point
G61 X10 Y20 Z-30#             ; Invalid character
G61 X10.5 Y20 Z30..5          ; Double decimal point
G61 X10 Y20 Z30-              ; Trailing negative sign
G61 X10 Y20 Z30.3.3.3         ; Triple decimal point
G61 X10 Y20 Z30# Comment      ; Invalid character
G61 X10.5.5 Y20 Z30           ; Double decimal point
G61 X10 Y20 Z30E5F6G7         ; No space between parameters


; G29 Regex regex invalid G-codes
G29F 10.0X ; Missing space before parameter
G29X Y10 ; Invalid character in parameter
G29 F 10.0.0 ; Extra decimal point
G29 F 10 0 ; Missing decimal point
G29 F -10-5 ; Double negative sign
G29 F 10@ ; Invalid character in parameter
G29 F 10# ; Invalid character in parameter
G29 F 10$ ; Invalid character in parameter
G29 F 10% ; Invalid character in parameter
G29 F 10^ ; Invalid character in parameter
G29 F 10& ; Invalid character in parameter
G29 F 10* ; Invalid character in parameter
G29 F 10( ; Invalid character in parameter
G29 F 10) ; Invalid character in parameter
G29 F 10_ ; Invalid character in parameter
G29 F 10+ ; Invalid character in parameter
G29 F 10= ; Invalid character in parameter
G29 F 10| ; Invalid character in parameter
G29 F 10\\ ; Invalid character in parameter
G29 F 10/ ; Invalid character in parameter
G29 F 10~ ; Invalid character in parameter
G29 F 10` ; Invalid character in parameter
G29 F 10< ; Invalid character in parameter
G29 F 10> ; Invalid character in parameter
G29 F 10? ; Invalid character in parameter
G29 F 10, ; Invalid character in parameter
G29 F 10. ; Trailing decimal point
G29 F 10..0 ; Double decimal point
G29 F 10 -10 ; Space before negative sign
G29 F 10 - 10 ; Space before and after negative sign
G29 F 10 X10Y20 ; Missing spaces between parameters
G29 F 10X Y 10 ; Missing space before parameter
G29 F 10X Y10 Z ; Missing space before parameter
G29 F10 X 10 ; Missing space after parameter letter
G29F 10 X 10 ; Missing space before parameter
G29 F 10 X 10Y20 ; Missing space between parameters
G29 F 10X Y 10 Z 20 ; Missing space before parameter
G29 F 10 X 10 Y 10 Z 20# Comment ; Invalid character in comment
G29 F 10 X 10 Y 10 Z 20$ Comment ; Invalid character in comment
G29 F 10 X 10 Y 10 Z 20% Comment ; Invalid character in comment


; M Regex regex invalid G-codes
M1 Click to continue                     ; M1 is not in the list
M105 Arthur                              ; M105 is not in the list
M28B1 file.txt                           ; Missing space after B1
M117Hello World!                         ; Missing space after M117
M33funstuff/mask.gco                     ; Missing space after M33
M919XYZE O3 P-1 S1                       ; Missing space after M919
M0Click to continue                      ; No space after M0
M16Click to continue                     ; No space after M16
M23Click to continue                     ; No space after M23
M28Click to continue                     ; No space after M28
M30Click to continue                     ; No space after M30
M32Click to continue                     ; No space after M32
M33Click to continue                     ; No space after M33
M117Click to continue                    ; No space after M117
M118Click to continue                    ; No space after M118
M815Click to continue                    ; No space after M815
M919Click to continue                    ; No space after M919
M928Click to continue                    ; No space after M928
M16_Arthur                               ; Underscore instead of space
M23_/musicg\~1/jingle.gco                ; Underscore instead of space
M28_file.txt                             ; Underscore instead of space
M28_B1_file.txt                          ; Underscore instead of space
M30_/path/to/file.gco                    ; Underscore instead of space
M32_S5022_!/boats/sailboat.gco           ; Underscore instead of space
M32_P_!/models/lgbust.gco#               ; Underscore instead of space
M33_funstuff/mask.gco                    ; Underscore instead of space
M117_Hello_World!                        ; Underscore instead of space
M118_E1_Yello_World!                     ; Underscore instead of space
M118_A1_action:cancel                    ; Underscore instead of space
M118_Hello_World                         ; Underscore instead of space
M815_G0_X0_Y0|G0_Z10|M300_S440_P50       ; Underscore instead of space
M919_XYZE_O3_P-1_S1                      ; Underscore instead of space
M928_log.txt                             ; Underscore instead of space


; T regex
T?X
TxY
TcZ
T"X
T Y
T X
T c
T x
T ?
T "X
T ?X
Tx 1
Tc 2
T ? 3
T " 4
T Q
T1x
T2c
T3"
T4?
T"5
T?6
T~x
T#c
T"x
T,c
T?7
Tx#
Tc$
T"@
T_?
T&x
T*c
T_x
T"X Y
T?X Z
Tx Y
Tc Z
T X Y
T? X Z
T" X Y
T? Y Z
Tx; Y
Tc# Z
T* X Y
T_ X Z
T& Y Z
T? X Y Z