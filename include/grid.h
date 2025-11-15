//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_GRID_H
#define CPLUSPLUSFINALPROJECT_GRID_H

#include <vector>
#include <memory>
#include "entity.h"
#include "player.h"

/// @brief Represents the game grid, which holds entities such as players, obstacles, and goals.
///
/// The Grid class manages a 2D grid of shared pointers to Entity objects. It provides
/// methods for accessing, displaying, moving, adding, and removing entities, as well as
/// utility functions for checking occupancy and filling the grid with obstacles.
class Grid {
private:
  std::vector<std::vector<std::shared_ptr<Entity>>> data;
  int rows, cols;

public:
  Grid(int rows, int cols);

  /// @brief Access the entity at a given position
  /// @param r Row index
  /// @param c Column index
  /// @return Reference to the entity at the specified position
  Entity& at(int r, int c);

  /// @brief Display the current state of the grid to the console
  void display();

  /// @brief Set an entity at a specific position
  /// @param e Shared pointer to the entity to place
  /// @param r Row index
  /// @param c Column index
  void setElement(std::shared_ptr<Entity> e, int r, int c);

  /// @brief Move a player a number of spaces
  /// @param p Shared pointer to the player
  /// @param numSpaces Number of spaces to move)
  void movePlayer(std::shared_ptr<Player> p, int numSpaces);

  /// @brief Remove a specific entity from the grid
  /// @param e Shared pointer to the entity to remove
  void removeEntity(std::shared_ptr<Entity> e);

  /// @brief Check if a grid position is empty
  /// @param r Row index
  /// @param c Column index
  /// @return True if the position contains no entity, false otherwise
  bool isEmpty(int r, int c) const;

  /// @brief Fill the grid with a specified number of traps and force blocks
  /// @param numTraps Number of traps to place
  /// @param numForces Number of force blocks to place
  void fill(int numTraps, int numForces);

  int getRows() const;
  int getCols() const;
};

#endif
