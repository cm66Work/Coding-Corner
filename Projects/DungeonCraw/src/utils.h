#pragma once

#include <iostream>

struct Vector2Int
{
  int x;
  int y;

  Vector2Int& operator=(const Vector2Int& other)
  {
    if(this == &other)
      return *this;

    x = other.x;
    y = other.y;

    return *this;
  }
  bool operator==(const Vector2Int& other) const {
    return x == other.x && y == other.y;
  }
  void Print()
  {
    std::cout<<"x: "<<x<<", y: "<<y<<std::endl;
  }
};
