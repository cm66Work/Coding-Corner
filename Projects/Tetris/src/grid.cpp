#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int cols = 0; cols < numCols; cols++)
    {
      grid[row][cols] = 0;
    }
    
  }
}

void Grid::Print()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw()
{
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      int cellValue = grid[row][col];
      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize -1 , colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int column)
{
  if (row >= 0 && row < numRows && column >= 0 && column < numCols)
  {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
  if(grid[row][column] == 0)
    return true;
  return false;
}
