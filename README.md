# Malicious G-code detection tool
This tool aims to detect malicious G-code. The tool reuses the G-code parser component that resides in the Marlin firmware (version bugfix-2.1.x): https://github.com/MarlinFirmware/Marlin/blob/bugfix-2.1.x/Marlin/src/gcode/parser.cpp


## Modifications to Marlin G-code parser
The parser is partly modified to run the standalone component. Commented code that was utilized in the original parser is denoted with  // [T] {reason commented out}.
Some unnecessary dependencies have been removed to limit the scope of the project.

## Submodules
This project utilizes the Google test framework for C++: https://github.com/google/googletest
When cloning this repository, be sure to include the submodules as well using

```git clone --recurse-submodules https://github.com/james-karsten/MGCodeDetector.git```

The submodules can be initialized by this command when the repository is already cloned.

```git clone --recurse-submodules https://github.com/james-karsten/MGCodeDetector.git```

# Documentation of code
This section serves as documentation for all additional code around the Marlin parser.

## Invalid G-code syntax detection: _detect_invalid_gcode()_ method in _parser.cpp_
This method is added to prevent invalid syntax of G-code from being parsed by the parser. It uses case-sensitive or insensitive regular expressions that validate the syntax of the G-code line that was passed as a parameter in the _parse()_ method. When the syntax is invalid, the function will stop.

**G-code syntax regex**:

```^([GMT]\d+)((\s+[XYZEFSPIJKDHLQWUVOR](-?\d+(\.\d*)?)?)*)\s*$```

**Breakdown**:

- ```([GMT]\d+)``` = Line has to start with G, M or T followed by one or more digits.
- ```((\s+[XYZEFSPIJKDHLQWUVOR](-?\d+(\.\d*)?)?)``` = Line follows with one of the characters listed at the left which are the parameters or flags of the G-code. This includes negative numbers, subcodes (X30.3) or one or more digits (X1 or X132). It can also be repeated zero or multiple times, so no parameters or multiple parameters are possible.
- ```s\*``` = Matches zero or more whitespace at the end of the g-code line.

Tests of this regular expression can be found in the test file _InvalidGCodeParser.cpp_ under the _Google_tests_ folder: https://github.com/james-karsten/MGCodeDetector/blob/invalid-gcode-detection/Google_tests/InvalidGCodeParser.cpp
