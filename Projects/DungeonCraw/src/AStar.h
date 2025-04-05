#pragma once
#include <vector>
#include <iostream>
#include "utils.h"

struct Node {
    Vector2Int position;
    int g, h;
    Vector2Int parent;
    int f() const { return g + h; }
};


std::vector<Vector2Int> AStarPathfinding(
  const std::vector<std::vector<int>>& grid,
  const Vector2Int& startPoint,
  const Vector2Int& endPoint
);