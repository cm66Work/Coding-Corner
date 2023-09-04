#include "cbe_Engine.hpp"
#include "cbe_GameLoop.hpp"
#include "cbe_TimeManager.hpp"

// std
#include <iostream>

namespace CoffeeBeanEngine {

GameLoop *gameloop;
TimeManager *timeManager;

bool shouldClose = false;

Engine::Engine() { Initialize(); }
Engine::~Engine() { Shutdown(); }

void Engine::Initialize() { timeManager = new TimeManager(); }

void Engine::Run() {
  while (!shouldClose) {
    // The game engine is running.
    timeManager->Tick();

    std::cout << "Delta Time: " << timeManager->GetDeltaTime() << "\n";
  }
}
void Engine::Shutdown() {}

} // namespace CoffeeBeanEngine
