//
// Created by sterritts on 11/9/2025.
//

#include "../include/trap.h"
#include "../include/player.h"
#include <iostream>
#include <vector>
#include "../include/diceRoller.h"

Trap::Trap(int r, int col) : Entity(r, col, "T") {}

void Trap::onEncounter(std::shared_ptr<Player> p) {
  std::cout << "You encountered a trap! To get out you need to roll a 4 or more" << std::endl;

  std::vector<std::string> jokes = {
    "Why did the scarecrow win an award? Because he was outstanding in his field!",
    "I told my wife she was drawing her eyebrows too high. She looked surprised.",
    "Why dont skeletons fight each other? They dont have the guts.",
    "I would tell you a construction joke, but I am still working on it.",
    "Why did the math book look sad? Because it had too many problems.",
    "I asked the librarian if the library had any books on paranoia. She whispered, 'They are right behind you…'",
    "Why dont eggs tell jokes? They would crack each other up.",
    "I tried to catch some fog yesterday. I mist."
};
  int num_rolls = 0;

  bool trapped = true;
  DiceRoller dice(1,6);

  while (trapped) {
    std::cout<<"Because trapped, Your punishment is a bad joke"<<std::endl;
    int index = std::rand() % jokes.size();
    std::cout << jokes[index] << std::endl;

    int r = dice.roll();
    num_rolls++;

    if (r >= 4) {
      std::cout << "You escaped!" << std::endl;
      trapped = false;
      if (num_rolls <= 3) {
        std::cout <<"You escaped the trap quickly! +2 points" << std::endl;
        p->addScore(2);
      }
    } else {
      std::cout << "You are still trapped" << std::endl;
    }
  }
}



