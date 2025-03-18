#include <vector>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}};

    for (const auto &offset : neighborOffsets)
    {
        /*
            We are going to assume that the grid will wrap around to the other side,
            so we calculate this with the row and column size taking into account.
        */
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();

        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

void Simulation::Update()
{
    if(IsRunning() == false) return; 
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            int liveNeighbors = CountLiveNeighbors(row, column);
            int cellValue = grid.GetValue(row, column);

            if (cellValue == 1)
            {
                if (liveNeighbors > 3 || liveNeighbors < 2)
                {
                    tempGrid.SetValue(row, column, 0); // kill the cell
                }
                else
                {
                    tempGrid.SetValue(row, column, 1); // make the cell alive
                }
            }
            else
            {
                if(liveNeighbors == 3)
                {
                    tempGrid.SetValue(row,column,1); // make the cell alive
                }
                else
                {
                    tempGrid.SetValue(row,column, 0); // kill the cell
                }
            }
        }
    }
    grid = tempGrid;
}
