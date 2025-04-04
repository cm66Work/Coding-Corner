#include <raylib.h>
#include <iostream>
#include "Grid.h"

void Grid::Initialize()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      std::cout<<grid[row][col];
    }
    std::cout<<std::endl;
  }
}

void Grid::Draw()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      DrawRectangle(row * cellSize + 1, col * cellSize + 1, cellSize - 1, cellSize -1, colors[1]);
    }
  }
}

bool Grid::IsCellOutside(int row, int column)
{
  if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    return false;
  return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
  if(grid[row][column] == 0)
    return true;
  return false;
}