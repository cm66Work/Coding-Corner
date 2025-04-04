#include <raylib.h>
#include <vector>
#include "Palette.h"
#include "Grid.h"
#include "player.h"


int main() 
{
    const int WINDOW_WIDTH = (20 * 16); // we want 60 cells by 30 cells for the game window. 
    const int WINDOW_HEIGHT = (30 * 16) + 150;
    int FPS = 30;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dungeon Crawl");
    SetTargetFPS(FPS);
    SetTargetFPS(60);

    std::vector<Color> colorPalette = GetPaletteColors();
    Grid grid = Grid(colorPalette);
    Player player = Player(10,10,colorPalette[3], 16);
    
    while (!WindowShouldClose())
    {
        // Player inputs
        // Update 
        // Rendering 


        // Call drawing functions
        BeginDrawing();
        ClearBackground(colorPalette[0]); 

        grid.Draw();
        player.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}