# Molecular Dynamics Simulation (C++ / SDL2)
A simple molecular dynamics simulation written in c++ using SDL2 for visualization.
## Features
- SDL2-based rendering
## Building
### Requirement
- MinGW or any GCC-based C++ compiler
- SDL2
### Building Instructions
```
mingw32-make                        // build full program
mingw32-make run                    // build and run full program
mingw32-make clean                  // NOT WORKING :(
```
for testing purpose:
```
mingw32-make display3D_test         // build display test
mingw32-make run_display3D_test     // build and run display test
```
## Folder Structure
```
.
|---src/        # sorce files
|---tests/      # unit/module? tests
|---MakeFile
|---README.md
|---SDL2.dll
```