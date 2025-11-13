//
// Created by sterritts on 11/9/2025.
//

#include <iostream>
#include "../include/grid.h"
#include "../include/player.h"
#include "../include/game.h"
#include <string>

int main() {

  auto p = std::make_shared<Player>("hold", 0, 0);

  Game game(p);
  game.introduce();

  std::string name;
  std::cout<< "What is your player name?" << std::endl;
  std::cin >> name;
  p->setName(name);

  std::string play = "Y";
  while (play == "Y" || play == "y") {
    game.setUp();
    game.setGrid();
    game.play();
    std::cout<<"Would you like to play again? (Y)es, (N)o" << std::endl;
    std::cin >> play;
  }

}