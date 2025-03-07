#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173,204,96,255};
Color darkGreen = {43,51,24,255};

int cellSize = 30;
int cellCount = 25;
int offset = 75; // with of the game boarder.

// used to keep track of the time the update method on the snake was called.
double lastUpdateTime = 0;

/// @brief Returns true if the element is inside the deque
/// @param element 
/// @param deque 
/// @return 
bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
            return true;
    }
    return false;
}

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
    public:
    // The first value in the body is the head of the snake.
    // deque is use full because it allows us to push and pop from both
    //  ends of the list.
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};

    // for keeping track of the directions the snake is moving.
    Vector2 direction = {1,0};
    
    // If we are adding a new segment to the snake then we do not want the
    //  snake to also move, we will just add a new segment to the snakes head.
    bool addSegment = false;

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{
                offset + x*cellSize, offset + y*cellSize, 
                (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
        
    }

    void Update()
    {

        body.push_front(Vector2Add(body[0], direction));
        if(addSegment)
        {
            // push a new element to the snake body's head.
            addSegment = false;
        }
        else
        {
            // to move the snake we remove the last point and add a new point at the front
            //  in the direction the snake is moving.
            body.pop_back();
        }
    }

    void Reset()
    {
        // the default position of the snake body.
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        direction = {1,0};
    }
};

class Food
{
    public:
    Vector2 position = {5,6};
    Texture2D texture;

    Food(deque<Vector2> snakeBody)
    {
        Image image = LoadImage("src/Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos(snakeBody);
    }

    ~Food()
    {
        //UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, 
            offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomCell()
    {
        float x = GetRandomValue(0, cellCount-1);
        float y = GetRandomValue(0, cellCount-1);
        return Vector2{x,y};
    }

    Vector2 GenerateRandomPos(deque<Vector2> snakeBody)
    {
        Vector2 newPosition = GenerateRandomCell();
        while(ElementInDeque(newPosition, snakeBody))
        {
            // the new postion for the food is inside the snake body.
            newPosition = GenerateRandomCell();
        }
        return newPosition;
    }
};

class Game
{
public:
    Snake snake = Snake();
    Food food = Food(snake.body);

    /// @brief Used to pause the game and wait for the player
    /// to press a key before the game continues
    bool running = true;

    int score = 0;

    // load the game sounds.
    Sound eatSound;
    Sound wallSound;

    Game()
    {
        // Raylib audio
        InitAudioDevice();

        // load the sounds.
        eatSound = LoadSound("src/Sounds/eat.wav");
        wallSound = LoadSound("src/Sounds/wall.mp3");
    }
    
    ~Game()
    {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
        // Raylib audio - Closing the audio device.
        CloseAudioDevice();
    }

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update()
    {
        if (!running)
            return; // wait for the player.

        // The game is running
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }

    void CheckCollisionWithFood()
    {
        if(Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score ++;
            PlaySound(eatSound);
        }
    }

    void CheckCollisionWithEdges()
    {
        if(snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            // the snake has hit the edge of the map.
            GameOver();
        }
        if(snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }

    /// @brief Gets called when the snake dies.
    void GameOver()
    {
        snake.Reset();
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
        score = 0;
        PlaySound(wallSound);
    }

    /// @brief Check if the snake head has collided with its body.
    void CheckCollisionWithTail()
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front(); // remove snakes head before checking.
        if(ElementInDeque(snake.body[0], headlessBody))
        {
            // the head has collided with the tail.
            GameOver();
        }
    }    
};

int main() 
{
    cout<<"Starting the game..."<<endl;
    InitWindow(2*offset + cellSize * cellCount, 2*offset + cellSize*cellCount, "Snake");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        if(eventTriggered(0.2))
        { 
            // Move the snake
            game.Update();
        }

        // Detect player input.
        // We also need to check if the player is not trying to move the snake
        //  into its own body.
        if(IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
        {
            game.snake.direction = {0, -1};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
        {
            game.snake.direction = {0, 1};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
        {
            game.snake.direction = {-1, 0};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
        {
            game.snake.direction = {1, 0};
            game.running = true;
        }

        // Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(
            Rectangle{
                (float)offset - 5, (float)offset - 5, 
                (float)cellSize * (float)cellCount + 10, 
                (float)cellSize * (float)cellCount + 10}, 
            5, darkGreen);
        game.Draw(); 
        DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score),
            offset -5, offset + cellSize * cellCount + 10, 40, darkGreen);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}