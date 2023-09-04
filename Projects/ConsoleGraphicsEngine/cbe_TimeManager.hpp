#pragma once

#include <cstdint>
namespace CoffeeBeanEngine {

class TimeManager {
public:
  TimeManager();
  ~TimeManager();

  // Initializes timekeeping.
  void Start();
  // Updates the *DeltaTime* between frames.
  void Tick();
  // Returns the time taken to render the last frame.
  float GetDeltaTime() const;

private:
  float deltaTime;
  std::uint32_t lastFrameTime;

  // Other private methods and attributes.
};
} // namespace CoffeeBeanEngine
