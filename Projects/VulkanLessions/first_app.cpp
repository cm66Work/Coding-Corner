#include "first_app.hpp"
#include <GLFW/glfw3.h>

namespace CoffeeBeanEngine {
// Call the Run function from FirstApp to try and create the window.
void FirstApp::Run() {
  while (!coffeeBeanEngineWindow
              .ShouldClose()) { // This it is the windows update loop.
    glfwPollEvents(); // Start Event Listernes for windwos level events.
  }
}
} // namespace CoffeeBeanEngine
