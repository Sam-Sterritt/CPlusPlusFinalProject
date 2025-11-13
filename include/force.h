//
// Created by sterritts on 11/9/2025.
//

#ifndef CPLUSPLUSFINALPROJECT_FORCE_H
#define CPLUSPLUSFINALPROJECT_FORCE_H

#include "entity.h"
#include "player.h"
#include "grid.h"


class Force: public Entity {

public:
  Force(int row, int col);
  ~Force() override = default;
  void onEncounter(std::shared_ptr<Player> p);
};

#endif //CPLUSPLUSFINALPROJECT_FORCE_H