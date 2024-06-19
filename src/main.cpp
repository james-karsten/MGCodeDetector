#include "parser.h" // header parser

int main() {
    char testLine2[] = "M109 S100 X10 Y432";
    char testLine4[] = "M104 S500 X10 Y432";
    char testLine3[] = "M104_M109 X10 Y432";
    char testLine5[] = "M109 R1000";
    char testLine6[] = "M109 T1 R10";
    char testLine7[] = "M109 T1 R200";
    char testLine8[] = "M109 T1 R2300";
    char testLine9[] = "M109 R130";
    char testLine10[] = "M104 F1 B100 S200";
    char testLine11[] = "M104 F S180 B1";
    char testLine12[] = "M104 F B2000 S100";
    char testLine13[] = "M104 F B0 S1";
    char testLine14[] = "M109 S180";
    char testLine15[] = "M109 R120";
    char testLine16[] = "M109 T1 R120";
    char testLine17[] = "M109 T1 R420";
    char testLine18[] = "M109 R420";
    char testLine19[] = "M109 S420";
    char testLine20[] = "M109 F B4 S100";
//    GCodeParser::parse(testLine2);
//    GCodeParser::parse(testLine4);
//    GCodeParser::parse(testLine3);
//    GCodeParser::parse(testLine5);
//    GCodeParser::parse(testLine6);
//    GCodeParser::parse(testLine7);
//    GCodeParser::parse(testLine8);
//    GCodeParser::parse(testLine9);
//    GCodeParser::parse(testLine10);
//    GCodeParser::parse(testLine11);
//    GCodeParser::parse(testLine12);
    GCodeParser::parse(testLine13);
//    GCodeParser::parse(testLine14);
//    GCodeParser::parse(testLine15);
//    GCodeParser::parse(testLine16);
//    GCodeParser::parse(testLine17);
//    GCodeParser::parse(testLine18);
//    GCodeParser::parse(testLine19);
//    GCodeParser::parse(testLine20);

    return 0;
}
