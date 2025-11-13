//
// Created by sterritts on 11/9/2025.
//

#include <string>
#include "../include/entity.h"

Entity::Entity(int r, int c, std::string s) : row(r), col(c), symbol(s) {}

std::string Entity::getSymbol() const{
  return symbol;
};

void Entity::setRow(int r) {
  row = r;
};
void Entity::setCol(int c) {
  col = c;
};

int Entity::getRow() const{
  return row;
};
int Entity::getCol() const{
  return col;
};