//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_PLAYER_H
#define CPLUSPLUSFINALPROJECT_PLAYER_H

#include <string>
#include "entity.h"

/// @brief Represents the player in the game.
///
/// Inherits from Entity and adds player-specific attributes such as name and score.
/// Provides methods to get and update the player's score and manage their name.
class Player : public Entity {
private:
  std:: string name;
  int score;

public:
  Player(const std::string name, int r = 0, int c = 0);

  int getScore() const; //const here tells the compiler this function won't chane the object. This is good since I plan to make constant players.
  void addScore(int s);
  std::string getName() const;
  void setName(const std::string name);
};

#endif //CPLUSPLUSFINALPROJECT_PLAYER_H