// lev_window : Little Vulkan Engien Window.
#pragma once

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <GLFW/glfw3.h>
#include <string>

namespace lve {
class LveWindow {
public:
  LveWindow(int w, int h, std::string name);
  // desitructor is the last function called before an object is
  // destroyed.
  ~LveWindow();

  LveWindow(const LveWindow &) = delete;
  LveWindow &operator=(const LveWindow &) = delete;

  bool ShouldClose() { return glfwWindowShouldClose(pWindow); }

private:
  void InitWindow();

  const int WIDTH, HEIGHT;
  const std::string WINDOW_NAME;
  GLFWwindow *pWindow;
};
} // namespace lve
