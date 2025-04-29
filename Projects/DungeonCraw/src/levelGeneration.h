#pragma once

#include "Grid.h"

class LevelGeneration
{
private:
  Grid* _grid;
public:
  LevelGeneration(Grid* grid):
    _grid(grid){};
  void RandomizeWalls();
  void GenerateRoom();

  ~LevelGeneration();
};
