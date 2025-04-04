#include <raylib.h>
#include <vector>
#include "Palette.h"
#include "Grid.h"


int main() 
{
    const int WINDOW_WIDTH = 60; // we want 60 cells by 30 cells for the game window. 
    const int WINDOW_HEIGHT = 30;
    const int CELL_SIZE = 16; // 16 bit game.
    int FPS = 30;
    InitWindow(WINDOW_WIDTH * CELL_SIZE, WINDOW_HEIGHT * CELL_SIZE, "Dungeon Crawl");
    SetTargetFPS(FPS);
    SetTargetFPS(60);

    std::vector<Color> colorPalette = GetPaletteColors();
    Grid grid = Grid(WINDOW_WIDTH * CELL_SIZE, WINDOW_HEIGHT * CELL_SIZE, CELL_SIZE, colorPalette);
    
    while (!WindowShouldClose())
    {
        // Call drawing functions
        BeginDrawing();
        ClearBackground(colorPalette[0]); 

        grid.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}