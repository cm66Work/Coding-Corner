#include <raylib.h>
#include "Grid.hpp"

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
           Color color = cells[row][column] ? Color{0,255,0,255} : Color{55,55,55,255}; 
           DrawRectangle(column * cellSeize, row * cellSeize, cellSeize-1, cellSeize-1, color);
        }
        
    }
    
}

void Grid::SetValue(int row, int column, int value)
{
    if (IsWithinBounds(row, column) == false)
        return; 
    cells[row][column] = value;
}

int Grid::GetValue(int row, int column)
{
    if(IsWithinBounds(row, column) == false)
        return 0;
    return cells[row][column];
}

/// @brief Checks to see if the given row and column is indie the grid
/// @param row 
/// @param column 
/// @return 
bool Grid::IsWithinBounds(int row, int column)
{
    if((row >= 0 && row < rows && column >= 0 && column < columns) == false)
        return false;
    return true;
}

void Grid::FillRandom()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int randomValue = GetRandomValue(0,4); // gives us better control over how many live cells we have.

            cells[row][column] = (randomValue == 4) ? 1 : 0; // 20% should be alive.
        }
        
    }
    
}
