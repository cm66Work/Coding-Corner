#pragma once
#include <raylib.h>
#include <vector>
#include "utils.h"
// this will be used for all entities in the game.
class Entity
{
public:
  Entity(int cellSize);
  Entity(int x, int y, Color color, int cellSize);
  Entity(Vector2Int position, Color color,int cellSize);
  void Draw();
  void Update();
  Vector2Int entityPosition;
  void SetPosition(Vector2Int newPosition);
  void MoveToNextPosition();
  bool IsEntityClicked(Vector2Int clickPosition);
  void SelectEntity();
  void DeselectEntity();
  void SetMovementPath(std::vector<Vector2Int> newPath);
  Color entityColor;
  int cellSize;
  bool isSelected;
private:
  std::vector<Vector2Int> movementPath;
  int totalActionPoints = 2;
  int remainingActionPoints = 2;
};