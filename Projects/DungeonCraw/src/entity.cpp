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
  Color color = (isSelected) ? Color{125,125,125,255} : entityColor;
  DrawRectangle(entityPosition.x * cellSize + 1, entityPosition.y * cellSize + 1, cellSize - 1, cellSize - 1, color);
}

void Entity::Move(Vector2Int newPosition)
{
  // add A* path finding later. for now just move the entity to the location.
  entityPosition = newPosition;
}

/// @brief Returns true if the clickPosition is equal to the entity position
/// @param clickPosition 
/// @return 
bool Entity::IsEntityClicked(Vector2Int clickPosition)
{
  if(clickPosition.x == entityPosition.x && clickPosition.y == entityPosition.y)
    return true;
  return false;
}

void Entity::SelectEntity()
{
  isSelected = true;
}

void Entity::DeselectEntity()
{
  isSelected = false;
}
