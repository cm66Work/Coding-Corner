#include <iostream>
#include <raylib.h>

using namespace std;

Color green = {173,204,96,255};
Color darkGreen = {43,51,24,255};

int cellSize = 30;
int cellCount = 25;

class Food
{
    public:
    Vector2 position = {5,6};
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("src/Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }
};

int main() 
{
    cout<<"Starting the game..."<<endl;
    InitWindow(cellSize * cellCount, cellSize*cellCount, "Snake");
    SetTargetFPS(60);

    Food food = Food();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        // Drawing
        ClearBackground(green);

        // Draw the food
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}