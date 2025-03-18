#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() 
{
    Color backgroundColor = {24,0,0,255};
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 4;
    int FPS = 120;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while(WindowShouldClose() == false) {
        // this is the game loop

        // 1. Event Handling
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Live is running...");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of life has stopped.");
        }
        else if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if(FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }

        // 2. Update state
        simulation.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(backgroundColor);
        simulation.Draw();
        EndDrawing();
    }

    // close the game window
    CloseWindow();
    return 0;
}