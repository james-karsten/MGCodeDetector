# Malicious G-code detection tool
This tool aims to detect malicious G-code. The tool reuses the G-code parser component that resides in the Marlin firmware (version bugfix-2.1.x): https://github.com/MarlinFirmware/Marlin/blob/bugfix-2.1.x/Marlin/src/gcode/parser.cpp

The parser is partly modified to run the standalone component. Commented code that was utilized in the original parser is denoted with  // [T] {reason commented out}.
Some unnecessary dependencies have been removed to limit the scope of the project.

## Submodules
This project utilizes the Google test framework for c++: https://github.com/google/googletest
When cloning this repository, be sure to include the submodules as well using

```git clone --recurse-submodules <repository_url>```

The submodules can be initialized by this command when the repository is already cloned.

```git clone --recurse-submodules <repository_url>```