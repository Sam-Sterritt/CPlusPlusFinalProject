//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_TRAP_H
#define CPLUSPLUSFINALPROJECT_TRAP_H

#include "entity.h"
#include "player.h"
#include "grid.h"
#include "obstacle.h"


/// @brief Represents a trap obstacle on the grid.
///
/// Inherits from Obstacle. When a player enters a Trap, a specific effect occurs.
/// This class overrides the onEncounter
/// method to implement its behavior.
class Trap : public Obstacle {
public:
  Trap(int row, int col);
  ~Trap() override = default;

  /// @brief Called when a player encounters the trap
  /// @param p Shared pointer to the Player that triggered the trap
  ///
  /// Overrides Obstacle::onEncounter to apply the trap's specific effect.
  void onEncounter(std::shared_ptr<Player> p) override;
};

#endif //CPLUSPLUSFINALPROJECT_TRAP_H