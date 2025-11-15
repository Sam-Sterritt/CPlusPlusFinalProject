//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_GOAL_H
#define CPLUSPLUSFINALPROJECT_GOAL_H

#include "entity.h"

/// @brief Represents the goal or target entity on the grid.
///
/// The Goal class inherits from Entity and is used to mark the location
/// that the player is trying to reach to win or complete the game.
/// It has a fixed position and a distinct symbol on the grid.
class Goal : public Entity {
public:
  Goal(int r, int c);
};

#endif //CPLUSPLUSFINALPROJECT_GOAL_H