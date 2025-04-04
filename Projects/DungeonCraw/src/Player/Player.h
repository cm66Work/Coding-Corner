#pragma once
#include "../Components/component.h"

/// @brief The player for the game.
class Player : public Component
{
public:
  Player(Color playerColor, int spawnX, int spawnY, int cellSize)
  {
    x = spawnX;
    y = spawnY;
    cellSize = cellSize;      
    color = color;
  };
};