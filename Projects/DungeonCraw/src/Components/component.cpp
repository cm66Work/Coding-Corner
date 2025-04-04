#include "component.h"

Position::Position(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Position::SetPosition(int newX, int newY)
{
  this -> x = newX;
  this -> y = newY;
}
