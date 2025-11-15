//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_DICEROLLER_H
#define CPLUSPLUSFINALPROJECT_DICEROLLER_H

/// @brief A simple dice roller class that generates random integers
/// between a specified lower and upper bound (inclusive)

class DiceRoller {
private:
  int low_end;
  int high_end;
public:

  DiceRoller(int low_end, int high_end);

  /// @brief Roll the dice and generate a random value
  /// @return An integer between low_end and high_end (inclusive)
  int roll();
};

#endif //CPLUSPLUSFINALPROJECT_DICEROLLER_H