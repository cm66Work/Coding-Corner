#pragma once
#include <vector>
#include <map>
#include "positon.h"
#include "colors.h"

class Block
{
public:
  Block();
  void Draw();
  void Move(int rows, int columns);
  std::vector<Position> GetCellPositions();
  int id;
  void Rotate();
  void UndoRotation();
  // we are going to store every possible stat each block can be in, using a map.
  // the key is the rotation state.
  std::map<int, std::vector<Position>> cells;
  private:
  int cellSize;
  // represent which state the block represents, which is the blocks current rotation.
  int rotationState;
  std::vector<Color> colors;
  int rowOffset;
  int columnOffset;
};