//
// Created by sterritts on 11/9/2025.
//

#include "../include/diceRoller.h"

#include <iostream>
#include <ostream>
#include <random>

DiceRoller::DiceRoller(int low_end, int high_end): low_end(low_end), high_end(high_end) {};

int DiceRoller::roll() {
  std::string input;
  std::cout<<"Enter R to roll your dice!"<<std::endl;
  std::cin>>input;
  while (input != "R") {
    std::cout<<"You should roll the dice, time is ticking!" << std::endl;
    std::cin >> input;
  }
  int r = low_end + rand() % (high_end - low_end + 1);
  std::cout << "Dice roll: " << r << std::endl;
  return r;
};