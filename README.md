# Grid Adventure Game

A simple console-based C++ game where a player navigates a grid, encounters traps and forces, and tries to reach the goal while scoring points.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Dependencies](#dependencies)
- [Compiler Used](#compiler-used)
- [Build Instructions](#build-instructions)
- [Testing](#testing)
- [Example Gameplay](#example-gameplay)

[//]: # (- [Gameplay Overview]&#40;#gameplay-overview&#41;)

---

## Description
The game consists of a player (`P`) navigating a grid. The player can choose their name, and the difficulty of the game. 
The grid will be filled with obstacles:
- **Traps (`T`)**: Requires a dice roll of 4 or more to escape.
- **Forces (`F`)**: Push the player back 2 spaces when encountered.
- **Goal (`*`)**: The final destination of the grid.

The player also has a score
- Rolling a 1 subtracts one point from the score
- Rolling a 6 adds two points to the score
- Escaping a trap in 3 or less tries adds three points

The player's objective is to reach the goal as quickly as possible while maximizing points. A longer time deducts points 
at the end of the game. There is a rank system at the end to help determine player success. As a player, you have the choice 
to use points to skip forward places in the grid. Each move takes one point.

---

## Features
- Configurable game levels: Easy, Medium, Hard.
- Dice-based movement and scoring system.
- Player can use points to skip forward.
- Dynamic grid generation with random obstacle placement.
- End-of-game scoring with rank based on performance.

---

## Dependencies

[//]: # (- C++14 or later compiler &#40;e.g., GCC, Clang, MSVC&#41;.)

[//]: # (- CMake &#40;version 4.0 or later&#41;.)

[//]: # (- [Catch2]&#40;https://github.com/catchorg/Catch2&#41; &#40;for unit tests&#41;.)

---

## Build Instructions

### Prerequisites
- **C++ Compiler:** GCC 13.2.0 (MinGW-builds) or any C++14 compatible compiler  
  Verify with:
  ```bash
  g++ --version

- **Cmake:** Cmake version 4.0+
  Verify with:
  ```bash
  cmake --version

- If you do not have cmake installed, go to this link: https://cmake.org/download/
- Choose eh Windows x64 Installer under "Binary Distibutions"
- Don't choose the ZIP folder
- After cmake installs, restart the powershell/terminal and try again

### Steps to Build
1. Clone the repository
   ```bash
   git clone https://github.com/Sam-Sterritt/CPlusPlusFinalProject.git
   cd CPlusPlusFinalProject
2. Create build directory and navigate to it
   ```bash
   mkdir build
   cd build
3. Generate build files using CMake:
   ```bash
   cmake -G "MinGW Makefiles" ..
4. Build the project
   ```bash
   cmake --build .

### Steps to Run
  FROM YOUR BUILD DIRECTORY

- Windows
  ```bash
  ./CPlusPlusFinalProject.exe

- Linux/macOS
  ```bash
  ./CPlusPlusFinalProject

---

## Testing

The game was not accommodating to test cases, and so testing was done manually through playing the game.
This included passing in invalid inputs, testing mathematical processes, and more. 

---

## Example Gameplay

