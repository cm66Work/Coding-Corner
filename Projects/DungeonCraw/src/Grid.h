#pragma once
#include <vector>
#include <raylib.h>
class Grid
{
public:
  /// @brief Grid for the game world. Entities are represented by int value IDs;
  /// @param width 
  /// @param height 
  /// @param cellSize 
  Grid(int width, int height, int cellSize, std::vector<Color> colorPalette):
    rows(height/cellSize),
    columns(width/cellSize),
    cellSize(cellSize),
    colors(colorPalette),
    cells(rows, std::vector<int>(columns,0)){};
  /// @brief Handles the drawing of the grid.
  void Draw();
private:
  int rows;
  int columns;
  int cellSize;
  std::vector<Color> colors;
  std::vector<std::vector<int>> cells;
};