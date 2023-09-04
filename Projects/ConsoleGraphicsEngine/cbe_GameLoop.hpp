#pragma once

namespace CoffeeBeanEngine {

class Engine;

// The Game Game loop whilst the game is running.
class GameLoop {
public:
  GameLoop(Engine *engine);
  ~GameLoop();

  // Handles all Logic updates.
  void Update();
  // Handles all Grahpical updates.
  void Render();
  // Handles all user or external inpute updates.
  void HandleInput();

private:
  Engine *engine;

  // Other private methods and attributes.
};
} // namespace CoffeeBeanEngine
