#pragma once
#include <raylib.h>

struct Vector2Int
{
  int x;
  int y;
};

// this will be used for all entities in the game.
class Entity
{
public:
  Entity(int cellSize);
  Entity(int x, int y, Color color, int cellSize);
  Entity(Vector2Int position, Color color,int cellSize);
  void Draw();
  void Move(Vector2Int newPosition);
  bool IsEntityClicked(Vector2Int clickPosition);
  void SelectEntity();
  void DeselectEntity();
  Vector2Int entityPosition;
  Color entityColor;
  int cellSize;
  bool isSelected;
};