#pragma once
#include <vector>
#include <raylib.h>
class Grid
{
public:
  Grid(std::vector<Color> colors, int cellSize):
    colors(colors), cellSize(cellSize) 
  {
    numRows = 20;
    numCols = 30;
    grid = std::vector<std::vector<int>>(numRows, std::vector<int>(numCols,0));
    Initialize();
  }

  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int column);
  bool IsCellEmpty(int row, int column);
  std::vector<std::vector<int>> grid;

private:
  int numRows;
  int numCols;
  std::vector<Color> colors;
  int cellSize;
};