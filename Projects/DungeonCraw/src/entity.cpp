#include "entity.h"

Entity::Entity(int cellSize)
{
  Entity(0,0, Color{255,255,255,255}, cellSize);
}

Entity::Entity(int x, int y, Color color, int cellSize)
{
  entityPosition.x = x;
  entityPosition.y = y;
  entityColor = color;
  this->cellSize = cellSize;
}

Entity::Entity(Vector2Int position, Color color, int cellSize)
{
  entityPosition = position;
  entityColor = color;
  this->cellSize = cellSize;
}

void Entity::Draw()
{
  DrawRectangle(entityPosition.x * cellSize + 1, entityPosition.y * cellSize + 1, cellSize - 1, cellSize - 1, entityColor);
}
