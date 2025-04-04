#pragma once
#include <vector>
#include <raylib.h>
class Grid
{
public:
  Grid(std::vector<Color> colors):
    colors(colors)
  {
    numRows = 30;
    numCols = 20;
    cellSize = 16;
    Initialize();
  }

  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int column);
  bool IsCellEmpty(int row, int column);
  int grid[30][20];

private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};