#include "levelGeneration.h"

#include <experimental/random>
#include <iostream>

void LevelGeneration::RandomizeWalls()
{
  // randomly place walls around the map.
  // place more walls the further out we get from the center.
  int gridSize = _grid->grid.size();
  int gridCenter = gridSize / 2;
  for (int row = gridCenter - gridSize / 2; row < gridCenter + gridSize / 2; row++)
  {
    for (int col = gridCenter - gridSize / 2; col < gridCenter + gridSize / 2; col++)
    {
      _grid->grid[row][col] = std::experimental::randint(0, 100) > 50 ? 1 : 0;
      // add marching cubes and make more walls generated the fether away you get from the center of the game.
    }
  }
}

void LevelGeneration::GenerateRoom()
{
}

LevelGeneration::~LevelGeneration()
{
}
