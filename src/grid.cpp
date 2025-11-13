//
// Created by sterritts on 11/9/2025.
//

#include "../include/grid.h"
#include "../include/force.h"
#include "../include/trap.h"
#include "../include/goal.h"
#include <random>
#include <iostream>

Grid::Grid(int rows, int cols)
      : rows(rows), cols(cols), data(rows, std::vector<std::shared_ptr<Entity>>(cols, nullptr)) {};

int Grid::getCols() const {
      return Grid::cols;
}

int Grid::getRows() const{
      return Grid::rows;
}

Entity& Grid::at(int r, int c) {
      if (data[r][c] == nullptr) {
            throw std::runtime_error("No entity at that location!");
      }
      return *(data[r][c]);
}

void Grid::display() {
      for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                  if (data[i][j]) {
                        std::cout << data[i][j]->getSymbol() << " ";
                  } else {
                        std::cout << ". "; // empty cell
                  }
            }
            std::cout << std::endl;
      }
      std::cout << std::endl;
}

void Grid::setElement(std::shared_ptr<Entity> e, int r, int c) {
      data[r][c] = e;
      e->setRow(r);
      e->setCol(c);
}

void Grid::movePlayer(std::shared_ptr<Player> p, int numSpaces) {
      // Remove player from current cell
      int oldRow = p->getRow();
      int oldCol = p->getCol();
      data[oldRow][oldCol] = nullptr;

      // Compute new position linearly
      int linearPos = oldRow * cols + oldCol + numSpaces;

      // Clamp to bounds
      if (linearPos < 0) linearPos = 0;
      if (linearPos >= rows * cols) linearPos = rows * cols - 1;

      int newRow = linearPos / cols;
      int newCol = linearPos % cols;

      // Handle encounters
      if (!isEmpty(newRow, newCol)) {
            auto other = data[newRow][newCol];
            if (auto trapPtr = std::dynamic_pointer_cast<Trap>(other)) {
                  trapPtr->onEncounter(p);
                  data[newRow][newCol] = nullptr; // clear trap
            }
            else if (auto forcePtr = std::dynamic_pointer_cast<Force>(other)) {
                  forcePtr->onEncounter(p);
                  data[newRow][newCol] = nullptr; // clear force
                  // move back two spaces
                  movePlayer(p, -2);
                  return;
            }
      }

      // Place player in new position
      p->setRow(newRow);
      p->setCol(newCol);
      data[newRow][newCol] = p;
}


bool Grid::isEmpty(int r, int c) const {
      return data[r][c] == nullptr;
}

void Grid::fill(int numTraps, int numForces) {
      int i = 0;
      while (i < numTraps) {
            int r = 1 + rand() % (rows - 2);
            int c = 1 + rand() % (cols - 2);

            if (isEmpty(r, c)) {
                  auto t = std::make_shared<Trap>(r, c);
                  data[r][c] = t;
                  i++;
            }
      }

      int j = 0;
      while (j < numForces) {
            int r = 1 + rand() % (rows - 2);
            int c = 1 + rand() % (cols - 2);

            if (isEmpty(r, c)) {
                  auto f = std::make_shared<Force>(r, c);
                  data[r][c] = f;
                  j++;
            }
      }

      data[rows-1][cols-1] = std::make_shared<Goal>(rows-1, cols-1);
}

void Grid::removeEntity(std::shared_ptr<Entity> e) {
      data[e->getRow()][e->getCol()] = nullptr;
      e.reset();
}