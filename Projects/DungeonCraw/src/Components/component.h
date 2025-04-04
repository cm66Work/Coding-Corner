#pragma once
#include <vector>
#include <raylib.h>
#include "position.h"


/// @brief Re-creating the Unity component system to make development more familiar to me.
class Component
{
public:
  Component():
    position(Position(0,0)){};
  void Draw();
  Position position;
  int cellSize;
  Color color;
};
