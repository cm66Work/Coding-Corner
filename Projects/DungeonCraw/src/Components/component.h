#pragma once
#include <vector>
#include <raylib.h>


/// @brief Re-creating the Unity component system to make development more familiar to me.
class Component
{
public:
  Component();
  void Draw();
  int x;
  int y;
  int cellSize;
  Color color;
};
