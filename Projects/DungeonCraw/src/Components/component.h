#pragma once
#include <vector>

/// @brief Re-creating the Unity component system to make development more familiar to me.
class Component
{
public:
  Position position;
};

class Position
{
public:
  Position(int x, int y);
  void SetPosition(int newX, int newY);
  int x = 0;
  int y = 0;
};
