# Molecular Dynamics Simulation (C++ / SDL2)
A simple molecular dynamics simulation written in c++ using SDL2 for visualization.
## Features
- SDL2-based rendering
## Dependencies
### SDL
1. Download and Extract SDL2.
2. In the Makefile, set the path to SDL.
```
CXXFLAGS := -I"C:/SDL2/include"
LDFLAGS  := -l"C:/SDL2/lib" -lmingw32 -lSDL2main -lSDL2
```
3. make sure SDL2.dll exist in the project folder.
## Building
### Requirement
- MinGW or any GCC-based C++ compiler
- SDL2
### Building Instructions
```
mingw32-make                        // build full program
mingw32-make run                    // build and run full program
mingw32-make clean                  // works with Git Bash
```
for testing purpose:
```
mingw32-make display3D_test         // build display test
mingw32-make run_display3D_test     // build and run display test
```
## Folder Structure
```
.
├───src/
├───include/
├───tests/
├───MakeFile
├───README.md
└───SDL2.dll
```