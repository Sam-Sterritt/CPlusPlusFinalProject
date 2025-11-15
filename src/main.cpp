//
// Created by sterritts on 11/9/2025.
//

#include <iostream>
#include "../include/grid.h"
#include "../include/player.h"
#include "../include/game.h"
#include <string>

int main() {
  // Create a shared pointer to the player, starting at position (0,0)
  auto p = std::make_shared<Player>("hold", 0, 0);

  // Create a Game object and associate it with the player
  Game game(p);
  game.introduce();

  // Ask the player for their name
  std::string name;
  std::cout<< "What is your player name?" << std::endl;
  std::cin >> name;
  p->setName(name);

  // Main game loop allowing the player to replay
  std::string play = "Y";
  while (play == "Y" || play == "y") {
    // Set up game level and difficulty
    game.setUp();

    // Initialize the grid and place obstacles, forces, goal, and player
    game.setGrid();

    // Start the main gameplay loop
    game.play();

    // Ask the player if they want to play again
    std::cout<<"Would you like to play again? (Y)es, (N)o" << std::endl;
    std::cin >> play;
  }

}