#include "cbe_TimeManager.hpp"

// std
#include <chrono>
#include <cstdint>
#include <ctime>

namespace CoffeeBeanEngine {

TimeManager::TimeManager() { Start(); }
TimeManager::~TimeManager() {}

void TimeManager::Start() { Tick(); }

void TimeManager::Tick() {
  deltaTime = (std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now().time_since_epoch())
                   .count()) -
              lastFrameTime;

  lastFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                      std::chrono::system_clock::now().time_since_epoch())
                      .count();
}

float TimeManager::GetDeltaTime() const {
  return deltaTime > 0 ? deltaTime : 0;
}

float deltaTime;

uint32_t lastFrameTime;

} // namespace CoffeeBeanEngine
