#include "entity.h"
#include <iostream>

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

void Entity::Update()
{
  /* Later we want to use a state machine to figure this junk out.
     so for now we can just update the movement of the current entity.
  */
  if(movementPath.size() > 0)
  {
    // the entity wants to move to a new position.
    // so move over one tile.
    MoveToNextPosition(); 
  }
}

void Entity::SetPosition(Vector2Int newPosition)
{
  entityPosition = newPosition;
}

void Entity::MoveToNextPosition()
{
  if(movementPath.size() == 0)
    return;
  entityPosition = movementPath[0];
  movementPath.erase(movementPath.begin());
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

void Entity::SetMovementPath(std::vector<Vector2Int> newPath)
{
  if(movementPath.size() > 0)
    movementPath.clear();
  movementPath = newPath;
}
