//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_ENTITY_H
#define CPLUSPLUSFINALPROJECT_ENTITY_H

#include <string>

/// @brief Abstract base class representing any entity that can exist on the grid.
///
/// This class is designed to be inherited by Player, Obstacle, or other entities.
/// It stores basic positional information (row and column) and a symbol representing
/// the entity visually on the grid. Making this class abstract ensures that only
/// derived, concrete entities can be instantiated.
class Entity {
protected:
  int row, col;
  std::string symbol; ///< Symbol representing the entity on the grid
public:
  Entity(int r, int c, std::string s);
  virtual ~Entity() = default;

  /// @brief Get the symbol of the entity
  /// @return The symbol as a string
  virtual std::string getSymbol() const;

  virtual void setRow(int r);
  virtual void setCol(int c);

  virtual int getRow() const;
  virtual int getCol() const;
};

#endif //CPLUSPLUSFINALPROJECT_ENTITY_H