; (mix of GPT generated and self-generated invalid commands)
; General regex invalid G-codes
G1X10Y20Z30    ; Missing spaces
G1.1X10Y20     ; Invalid G-code format
G1 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10  X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 X8 Y9 Z10 ; To many characters
T3 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1  S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 ; To many characters
G61 X10 Y20 Z30 A40 B50 C60 D70 E80 F90 G100 H110 I120 J130 K140 L150 M160 N170 O180 P190 Q200 R210 S220 T230 U240
G29 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z A B C D E F G H I J K L M N O P Q R A B C D E F G H I J K L M N O P Q R A B C D E F G H I J K L M N O P Q R A B C D E F G H I J K L M N O P Q R A B C D E F G H I J K L M N O P Q R
M0 This is a very long test string to ensure the M code pattern does not match correctly and is invalid
M16 This string exceeds the maximum length allowed for M16 code pattern making it invalid for testing
M23 Another long string to ensure the M23 pattern does not match correctly due to its excessive length
M28 Example string for M28 code pattern matching purposes but it is too long to be valid in this case
M30 A string that tests the M30 code pattern but exceeds the maximum length making it invalid for matching
M32 Validating the M32 code pattern with this example string which is too long to be considered valid
M33 A sample string to check M33 code pattern but it is too long to match correctly as valid input
M117 Display message on the screen with M117 code pattern but this string exceeds the maximum length allowed
M118 Another display message for M118 code pattern validation but it is too long to be valid input
M815 Checking M815 pattern with this test string which is too long to match correctly and be considered valid
M919 Validating M919 pattern with a sample string that exceeds the maximum length allowed making it invalid
M928 A string to ensure M928 pattern works correctly but this string is too long to be valid input for matching
M999 Testing the M999 pattern with an example string that is too long to match correctly as valid input
T1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1 S1
G1 X8 Y9 Z10 A11 B12 C13 D14 E15 F16 G17 H18 I19 J20 K21 L22 M23 N24 O25 P26 Q27 R28 S29 T30 U31 V32 W33 X34 Y35 Z36
M100 X1.5 Y2.5 Z3.5 A4.5 B5.5 C6.5 D7.5 E8.5 F9.5 G10.5 H11.5 I12.5 J13.5 K14.5 L15.5 M16.5 N17.5 O18.5 P19.5 Q20.5 R21.5 S22.5 T23.5 U24.5 V25.5 W26.5 X27.5 Y28.5 Z29.5
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
