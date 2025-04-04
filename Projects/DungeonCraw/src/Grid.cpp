#include <raylib.h>
#include "Grid.h"

void Grid::Draw()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, colors[1]);
    }
  }
  
}