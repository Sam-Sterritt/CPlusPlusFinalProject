//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_GRID_H
#define CPLUSPLUSFINALPROJECT_GRID_H

#include <vector>
#include <memory>
#include "entity.h"
#include "player.h"

class Grid {
private:
  std::vector<std::vector<std::shared_ptr<Entity>>> data;
  int rows, cols;

public:
  Grid(int rows, int cols);

  Entity& at(int r, int c);

  void display();

  // Set an element at a given position
  void setElement(std::shared_ptr<Entity> e, int r, int c);

  // Move an entity by a number of spaces (linear movement)
  void movePlayer(std::shared_ptr<Player> p, int numSpaces);

  void removeEntity(std::shared_ptr<Entity> e);

  bool isEmpty(int r, int c) const;

  void fill(int numTraps, int numForces);

  int getRows() const;
  int getCols() const;
};

#endif
