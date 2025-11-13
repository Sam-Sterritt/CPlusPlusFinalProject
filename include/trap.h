//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_TRAP_H
#define CPLUSPLUSFINALPROJECT_TRAP_H

#include "entity.h"
#include "player.h"
#include "grid.h"

class Trap : public Entity {
public:
  Trap(int row, int col);
  ~Trap() override = default;

  void onEncounter(std::shared_ptr<Player> p);
};

#endif //CPLUSPLUSFINALPROJECT_TRAP_H