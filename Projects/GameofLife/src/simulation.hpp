#pragma once
#include"Grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height, int cellSize)
        :grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {grid.FillRandom();};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
        void Update();
        bool IsRunning() {return run;} 
        void Start() {run = true;}
        void Stop() {run = false;}
    private:
        Grid grid;
        Grid tempGrid; // used to store the updated state of the grid for the next frame.
        bool run;
};