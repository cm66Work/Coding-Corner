#include "component.h"
Component::Component()
{
}
void Component::Draw()
{
  DrawRectangle(position.x, position.y, cellSize -1 , cellSize -1, color);
}
