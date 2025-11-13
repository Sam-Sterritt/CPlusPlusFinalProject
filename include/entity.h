//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_ENTITY_H
#define CPLUSPLUSFINALPROJECT_ENTITY_H

#include <string>

class Entity {
  ///This is an abstract class that will be the base class for
  ///obstacle and player. This is used to that the grid can hold
  ///both an obstacle and a player at the same time.
protected:
  int row, col;
  std::string symbol;
public:
  Entity(int r, int c, std::string s);
  virtual ~Entity() = default;

  virtual std::string getSymbol() const;

  virtual void setRow(int r);
  virtual void setCol(int c);

  virtual int getRow() const;
  virtual int getCol() const;
};

#endif //CPLUSPLUSFINALPROJECT_ENTITY_H