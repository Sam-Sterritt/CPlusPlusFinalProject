//
// Created by sterritts on 11/11/2025.
//

#include "../include/game.h"
#include <ctime>
#include <iostream>

/// @brief Constructor for the Game class
/// @param p Shared pointer to the Player object
///
/// Initializes the game with default values and associates the player.
/// Dice is initialized with range 1–6. Grid is initialized empty (0x0).
Game::Game(std::shared_ptr<Player> p)
    : rows(0),
      cols(0),
      numForces(0),
      numTraps(0),
      grid(0, 0),
      player(p),
      dice(1, 6),
      start_time(0),
      end_time(0),
      percent_red(0.0)
{}

void Game::introduce() {
  std::cout <<  "You are a player P. Your goal is to make it through the grid as "
                "fast as possible with the most points scored. In order to move, you must roll a dice. After "
                "you roll, you will move the number of spaces that the dice says. "
                "If you run into a force(F), you will move back two spaces and re- start "
                "your turn. If you hit a trap(T), you must roll a 4 or more to get the "
                "obstacle to go away. If you roll a 6, the T goes away and you move "
                "forward one space. The end is marked by a star." << std::endl;

  std::cout << "You can score a point by rolling a 6, and you can score 2 points by escaping traps quickly (<2 rolls). You loose "
               "two points by rolling a 1. At the end of the game, a percent of the time you took to complete"
               "the game will be subtracted from your total points. This percentage changes per level. E -> 5%, M -> 10%, H -> 20%. "
               "You can also choose to use your points to skip your position forward in the game (aka skip over obstacles!)" <<std::endl;
}

/// @brief Sets up the game level, grid size, and number of obstacles based on player input
void Game::setUp() {
  std::string level;
  std::cout << "Select the level you would like: (E)asy, (M)edium, (H)ard" << std::endl;
  std::cin >> level;

  if (level == "E" || level == "e") {
    //A 5x2 grid, with ~%2 traps and ~%10 forces
    rows = 5;
    cols = 3;
    numForces = 1;
    numTraps = 1;
    percent_red = 0.05;
  }

  else if (level == "M" || level == "m") {
    //A 10x5 grid, with %5 traps and %10 forces
    rows = 10;
    cols = 5;
    numForces = 5;
    numTraps = 3;
    percent_red = 0.1;
  }

  else if (level == "H" || level == "h") {
    //A 20x15 grid, with %10 traps and %15 forces
    rows = 20;
    cols = 15;
    numForces = 45;
    numTraps = 30;
    percent_red = 0.2;
  }
}

/// @brief Ends the game and calculates final score and rank
/// @param duration Duration of the game in seconds
void Game::end(double duration) {
  double penalty = static_cast<int>(player->getScore() * percent_red);
  int finalScore = static_cast<int>(player->getScore() - penalty);

  std::cout<<"Congrats "<< player->getName() << "! You finished in " << duration << " seconds." << std::endl;
  std::cout << "Time penalty (" << (percent_red * 100)
              << "% of points = -" << penalty << ")\n";
  std::cout << "Final Score: " << finalScore << " points!" << std::endl;

  char rank;

  if (finalScore >= 5 && duration <= 60)
    rank = 'A';
  else if (finalScore >= 3 && duration <= 120)
    rank = 'B';
  else if (finalScore == 0 && duration <= 180)
    rank = 'C';
  else
    rank = 'D';

  std::cout << "Your Rank: " << rank << std::endl;

  if (rank == 'A')
    std::cout << "Incredible! You mastered the grid!" << std::endl;
  else if (rank == 'B')
    std::cout << "Great job — solid performance!" << std::endl;
  else if (rank == 'C')
    std::cout << "Not bad! A little more speed and precision next time." << std::endl;
  else if (rank == 'D')
    std::cout << "You made it... barely! Try improving your time or rolls." << std::endl;

  player->addScore(-player->getScore()); //Reset in case of next game.
}

void Game::play() {
  start_time = std::clock();
  bool finished = false;

  while (!finished) {
    std::cout<<"\nCurrent Score: " << player->getScore() << std::endl;

    // Allow the player to skip spaces if they have enough points
    if (player->getScore() >= 3) {
      std::string choice;
      std::cout << "Would you like to spend points to skip forward? (Y/N)" << std::endl;
      std::cin >> choice;
      int skip = -1;
      if (choice == "Y" || choice == "y"){
        while (skip == -1){
          std::cout<<"How many spaces would you like to skip? You loose 3 points per skip" << std::endl;
          std::cin >> skip;

          if (skip*3 > player->getScore()) {
            std::cout << "Invalid skip number" << std::endl;
            skip = -1;
          }
        }
        grid.movePlayer(player,skip);
        player->addScore(-3*skip);
        grid.display();
        choice = "n";
      }
    }
    int roll = dice.roll();

    // Apply scoring rules based on dice roll
    if (roll == 6) {
      player->addScore(1);
      std::cout << "Wow! You rolled a 6! +1 point" << std::endl;
    }
    if (roll == 1) {
      player->addScore(-1);
      std::cout << "Unlucky! You rolled a 1, -1 point" << std::endl;
    }

    grid.movePlayer(player,roll);
    grid.display();

    // Check if player has reached the goal (bottom-right corner)
    if (player->getRow() == grid.getRows() - 1 && player->getCol() == grid.getCols() - 1) {
      finished = true;
    }

  }

  end_time = std::clock();
  double duration = double(end_time - start_time)/ CLOCKS_PER_SEC;

  end(duration);
}

/// @brief Sets up the grid with obstacles and places the player at the start
void Game::setGrid() {
  Grid grid(rows, cols);
  grid.fill(numTraps, numForces);
  grid.setElement(player, 0, 0);
  Game::grid = grid;
  grid.display();
}

void Game::setPlayer(Player player) {
  Game::player = std::make_shared<Player>(player);
}

double Game::getPercent() {
  return percent_red;
}