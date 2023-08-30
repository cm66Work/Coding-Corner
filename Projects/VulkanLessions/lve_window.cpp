#include "lve_window.hpp"
// #include <GLFW/glfw3.h>

namespace lve {
LveWindow::LveWindow(int w, int h, std::string name)
    : WIDTH(w), HEIGHT(h), WINDOW_NAME(name) {
  InitWindow();
}

LveWindow::~LveWindow() {
  glfwDestroyWindow(pWindow);
  glfwTerminate();
}

void LveWindow::InitWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  pWindow =
      glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME.c_str(), nullptr, nullptr);
}
} // namespace lve
