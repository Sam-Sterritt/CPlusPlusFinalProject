cmake_minimum_required(VERSION 4.0)
project(CPlusPlusFinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPlusPlusFinalProject
        src/main.cpp
        include/player.h
        src/player.cpp
        include/diceRoller.h
        src/diceRoller.cpp
        include/grid.h
        include/entity.h
        include/trap.h
        src/trap.cpp
        include/force.h
        src/force.cpp
        src/entity.cpp
        src/grid.cpp
        include/goal.h
        src/goal.cpp
        include/game.h
        src/game.cpp
        include/obstacle.h
)
