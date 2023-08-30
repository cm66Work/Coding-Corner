#include "lve_window.hpp"
// #include <GLFW/glfw3.h>

namespace lve {
LveWindow::LveWindow(int w, int h, std::string name)
    : WIDTH(w), HEIGHT(h), WINDOW_NAME(name) { // Member initulisers
  InitWindow();                                // call the helper funcion.
}

LveWindow::~LveWindow() {
  // destroy the resources we aquired during initulisation.
  glfwDestroyWindow(pWindow);
  glfwTerminate();
}

void LveWindow::InitWindow() {
  // Initulise the GLFW library.
  glfwInit();
  // Do not create an OpenGL context when the window is created,
  // since we will be using Vulkan instead.
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  // We will be handeling window resizing, so diable it for now.
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  // Create the window.
  // Window name needs to be converted into an array of chars
  // First null is for making the window fullscreen.
  // Last null is for OpenGL context, which we just diabled.
  pWindow =
      glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME.c_str(), nullptr, nullptr);
}
} // namespace lve
