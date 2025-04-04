#pragma once
#include "entity.h"

class Player : public Entity
{
public:
  Player(int x, int y, Color color, int cellSize) : Entity(x, y, color, cellSize)
  {
    isSelected = false;
  };
};