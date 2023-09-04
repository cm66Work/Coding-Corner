#pragma once

#include "cbe_GameLoop.hpp"
#include "cbe_TimeManager.hpp"

namespace CoffeeBeanEngine {

// The Entry point for the game engine.
// Acting as the central hub.
// There should only ever be one.
class Engine {
public:
  // Construter for the game engine.
  Engine();
  // Destructer for the game engine.
  ~Engine();

  // Set starting variables for the engine.
  void Initialize();
  // Start the engine.
  void Run();
  // Clean up resources.
  void Shutdown();

  float GetDeltaTime();

private:
  // All events and actions that will happen whilst the game is running.
  GameLoop *gameloop;
  // Handles time running within the Engine, EG. DELTA TIME and the games
  // internal clock.
  TimeManager *timeManager;
};
} // namespace CoffeeBeanEngine
