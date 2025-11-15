//
// Created by sterritts on 11/14/2025.
//

#include "player.h"
#include <memory>

#ifndef CPLUSPLUSFINALPROJECT_OBSTACLE_H
#define CPLUSPLUSFINALPROJECT_OBSTACLE_H

/// @brief Abstract base class representing obstacles on the grid.
///
/// Obstacles are entities that can interact with the player when encountered.
/// Each derived obstacle class (e.g., Force, Trap) must implement the `onEncounter`
/// method to define its specific behavior.
class Obstacle : public Entity{
public:
  Obstacle(int row, int col, std::string s): Entity(row, col, s){};

  /// @brief Called when a player encounters the obstacle.
  /// @param p Shared pointer to the Player that triggered the encounter
  ///
  /// This is a pure virtual function. Each derived class must define the
  /// specific effect of the obstacle on the player.
  virtual void onEncounter(std::shared_ptr<Player> p) = 0;
};

#endif //CPLUSPLUSFINALPROJECT_OBSTACLE_H