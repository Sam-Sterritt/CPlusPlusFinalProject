//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_DICEROLLER_H
#define CPLUSPLUSFINALPROJECT_DICEROLLER_H

class DiceRoller {
private:
  int low_end;
  int high_end;
public:
  DiceRoller(int low_end, int high_end);
  int roll();
};

#endif //CPLUSPLUSFINALPROJECT_DICEROLLER_H