//
// Created by sterritts on 11/11/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_GAME_H
#define CPLUSPLUSFINALPROJECT_GAME_H
#include "grid.h"
#include "player.h"
#include "diceRoller.h"
#include <chrono>

class Game {
private:
  int rows;
  int cols;
  int numForces;
  int numTraps;
  Grid grid;
  std::shared_ptr<Player> player;
  DiceRoller dice;
  clock_t end_time;
  clock_t start_time;
  double percent_red;

public:
  Game( std::shared_ptr<Player> p);
  void introduce();
  void setUp();
  void play();

  void setGrid();
  void setPlayer(Player player);

  double getPercent();
};

#endif //CPLUSPLUSFINALPROJECT_GAME_H