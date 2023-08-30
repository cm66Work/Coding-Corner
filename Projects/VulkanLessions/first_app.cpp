#include "first_app.hpp"
#include <GLFW/glfw3.h>

namespace lve {
void FirstApp::Run() {
  while (!lveWindow.ShouldClose()) {
    glfwPollEvents();
  }
}
} // namespace lve
