cmake_minimum_required(VERSION 3.8)
project(RaceModificationMod)
add_subdirectory(CWSDK)
add_library(RaceModificationMod-v0.0.1 SHARED
"main.cpp"
"src/systems/race_system.cpp"
"src/mod.cpp"
"src/enums/races.h"
"src/enums/classes.h")
target_link_libraries(RaceModificationMod LINK_PUBLIC CWSDK)
