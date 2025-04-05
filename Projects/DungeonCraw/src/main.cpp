#include <raylib.h>
#include <vector>
#include <iostream>
#include <cmath>
#include "Palette.h"
#include "Grid.h"
#include "player.h"
#include "AStar.h"

double lastUpdateTime = 0;
bool EventTriggered(double interval = 0.2)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main() 
{
    const int CELL_SIZE = 16;
    const int MAP_WIDTH = 20;
    const int MAP_HEIGHT = 30;
    const int WINDOW_WIDTH = (MAP_WIDTH * CELL_SIZE); // we want 60 cells by 30 cells for the game window. 
    const int WINDOW_HEIGHT = (MAP_HEIGHT * CELL_SIZE) + 150;
    int FPS = 30;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dungeon Crawl");
    SetTargetFPS(FPS);
    SetTargetFPS(30);

    std::vector<Color> colorPalette = GetPaletteColors();
    Grid grid = Grid(colorPalette, CELL_SIZE);
    Player player = Player(10,10,colorPalette[3], CELL_SIZE);
    
    while (!WindowShouldClose())
    {
        // Player Inputs
        if(IsMouseButtonPressed(0))
        {
            // check what tile the player has clicked on.
            Vector2 mousePosition = GetMousePosition();
            Vector2Int mousePositionInGrid;
            mousePositionInGrid.x = round((mousePosition.x - (CELL_SIZE / 2)) / CELL_SIZE);
            mousePositionInGrid.y = round((mousePosition.y - (CELL_SIZE / 2)) / CELL_SIZE);
            // mousePositionInGrid.Print();

            // if the player has clicked on the same tile as the player,
            //  select the player.
            if(player.IsEntityClicked(mousePositionInGrid))
            {
                if(player.isSelected)
                {
                    player.DeselectEntity();
                }
                else
                {
                   player.SelectEntity(); 
                }
            }
            else if(player.isSelected)
            {
                if(grid.IsCellOutside(mousePositionInGrid.x, mousePositionInGrid.y) == false &&
                    grid.IsCellEmpty(mousePositionInGrid.x, mousePositionInGrid.y))
                {
                    Vector2Int endPoint;
                    endPoint.x = mousePositionInGrid.x;
                    endPoint.y = mousePositionInGrid.y;
                    std::vector<Vector2Int> path = AStarPathfinding(
                                                    grid.grid, player.entityPosition, endPoint);
                    if(path.size() != 0)
                    {
                        player.SetMovementPath(path);
                    }
                }
            }
            // if the player is selected, and not clicked again,
            //  move the player to the new tile.
        }
        else if(IsMouseButtonPressed(1) && player.isSelected)
        {
            player.DeselectEntity();
        }
        // Update 
        if(EventTriggered(0.2))
        {
            // Update the current active entity.
            // for now that is just the player.
            player.Update();
        }
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