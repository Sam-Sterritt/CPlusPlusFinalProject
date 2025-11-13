//
// Created by sterritts on 11/9/2025.
//

# include "../include/player.h"

Player::Player(const std::string n, int r, int c)
    : Entity(r, c, "P"), name(n), score(0) {}

int Player::getScore() const {
  return score;
}
void Player::addScore(int s) {
  score += s;
}

std::string Player::getName() const {
  return name;
}

void Player::setName(const std::string n) {
  name = n;
}

