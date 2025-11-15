//
// Created by sterritts on 11/11/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_GAME_H
#define CPLUSPLUSFINALPROJECT_GAME_H
#include "grid.h"
#include "player.h"
#include "diceRoller.h"
#include <chrono>

/// @brief Main class representing the game logic for the grid-based game.
///
/// This class manages the game state, including the grid, player, dice, and timers.
/// It handles game setup, player interaction, and tracks progress or completion percentage.
class Game {
private:
  int rows;                    ///< Number of rows in the game grid
  int cols;                    ///< Number of columns in the game grid
  int numForces;               ///< Number of force blocks on the grid
  int numTraps;                ///< Number of traps on the grid
  Grid grid;                   ///< The game grid
  std::shared_ptr<Player> player; ///< Shared pointer to the player object
  DiceRoller dice;             ///< Dice roller for player movement
  clock_t start_time;          ///< Game start time
  clock_t end_time;            ///< Game end time
  double percent_red;          ///< Tracks percentage of points to be deleted at end of game. Changes per level

public:
  Game( std::shared_ptr<Player> p);

  /// @brief Introduces the game to the player.
  void introduce();

  /// @brief Sets up the game grid, entities, and initial conditions.
  void setUp();

  /// @brief Main game loop where the player takes turns and interacts with the grid.
  void play();

  /// @brief Sets up the grid layout, placing obstacles, traps, and force blocks.
  void setGrid();

  /// @brief Sets the player object.
  /// @param player Player object to associate with the game
  void setPlayer(Player player);

  /// @brief Returns the percentage of score reduction.
  /// @return A double representing the percentage
  double getPercent();

  /// @brief Ends the game and calculates duration.
  /// @param duration Duration of the game session
  void end(double duration);
};

#endif //CPLUSPLUSFINALPROJECT_GAME_H