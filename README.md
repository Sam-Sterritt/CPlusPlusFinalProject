# Grid Adventure Game

A simple console-based C++ game where a player navigates a grid, encounters traps and forces, and tries to reach the goal while scoring points.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Dependencies](#dependencies)
- [Build Instructions](#build-instructions)

[//]: # (- [Run Instructions]&#40;#run-instructions&#41;)

[//]: # (- [Testing]&#40;#testing&#41;)

[//]: # (- [Gameplay Overview]&#40;#gameplay-overview&#41;)

---

## Description
The game consists of a player (`P`) navigating a grid filled with obstacles:
- **Traps (`T`)**: Require a dice roll of 4 or more to remove. Rolling a 6 moves you forward 1 space.
- **Forces (`F`)**: Push the player back 2 spaces when encountered.
- **Goal (`*`)**: The final destination of the grid.

The player also has a score
- Rolling a 1 subtracts one point from the score
- Rolling a 6 adds one point to the score
- Escaping a trap in 3 or less tries adds two points

The player's objective is to reach the goal as quickly as possible while maximizing points. There is a rank system at the end
to help determine player success. 

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

[//]: # (1. **Clone the repository**)

[//]: # (```bash)

[//]: # (git clone <repository_url>)

[//]: # (cd <repository_directory>)
