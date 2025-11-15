//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_FORCE_H
#define CPLUSPLUSFINALPROJECT_FORCE_H

#include "entity.h"
#include "obstacle.h"
#include "player.h"
#include "grid.h"

/// @brief Represents a "force" block in the game that pushes the player back when encountered.
///
/// Inherits from Obstacle. When a player enters a Force block, a specific effect occurs
/// (e.g., moving the player back two spaces). This class overrides the onEncounter method
/// to implement this behavior.
class Force : public Obstacle{

public:
  Force(int row, int col);

  /// @brief Called when a player encounters the force block
  /// @param p Shared pointer to the Player that triggered the encounter
  ///
  /// Overrides Obstacle::onEncounter to apply the force effect (e.g., push back the player).
  void onEncounter(std::shared_ptr<Player> p) override;
};

#endif //CPLUSPLUSFINALPROJECT_FORCE_H