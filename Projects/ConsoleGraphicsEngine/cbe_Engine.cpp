#include "cbe_Engine.hpp"
#include "cbe_GameLoop.hpp"
#include "cbe_TimeManager.hpp"

namespace CoffeeBeanEngine {

GameLoop *gameloop;
TimeManager *timeManager;

bool shouldClose = false;

Engine::Engine() { Initialize(); }
Engine::~Engine() { Shutdown(); }

void Engine::Initialize() {
  timeManager = new TimeManager();
  gameloop = new GameLoop(this);
}

void Engine::Run() {
  while (!shouldClose) {
    // The game engine is running.
    timeManager->Tick();

    gameloop->Render();
    gameloop->Update();
    gameloop->HandleInput();
  }
}
void Engine::Shutdown() {}

float Engine::GetDeltaTime() { return timeManager->GetDeltaTime(); }

} // namespace CoffeeBeanEngine
