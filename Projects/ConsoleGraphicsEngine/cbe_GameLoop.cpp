#include "cbe_GameLoop.hpp"
#include "Graphics/cbe_Renderer.hpp"

// std
#include <iostream>

namespace CoffeeBeanEngine {

Engine *engine;
WindowRenderer *windowRenderer;

GameLoop::GameLoop(Engine *e) {
  this->engine = e;
  windowRenderer = new WindowRenderer(80, 60);
}
GameLoop::~GameLoop() {}

// Handles all Logic updates.
void GameLoop::Update() {}
// Handles all Grahpical updates.
void GameLoop::Render() {} // windowRenderer->DrawScreen(); }
// Handles all user or external inpute updates.
void GameLoop::HandleInput() {}
} // namespace CoffeeBeanEngine
