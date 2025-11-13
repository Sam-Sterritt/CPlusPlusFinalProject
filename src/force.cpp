//
// Created by sterritts on 11/9/2025.
//


#include "../include/force.h"
#include "../include/player.h"
#include <iostream>

Force::Force(int r, int c)
    : Entity(r, c, "F") {}

void Force::onEncounter(std::shared_ptr<Player> p) {
  std::cout << "You encountered a force block. You have been pushed back two spaces." << std::endl;
}

