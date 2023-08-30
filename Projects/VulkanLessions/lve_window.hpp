// lev_window : Little Vulkan Engien Window.
// Define guarding, to protect existing definision int the project
// preventing a refenrece error or memory leak.
#ifndef GLFW_INCLUDE_VULKAN
// Tell GLFW to include Vulkan headers.
#define GLFW_INCLUDE_VULKAN
#endif

// GLFW is platform egnostic windowing tool.
// allows us to creat a window regardelss of the opperating system
// without needing to change the code for each platform.
#include <GLFW/glfw3.h>
#include <string>

namespace lve {
class LveWindow {
public:
  LveWindow(int w, int h, std::string name);
  // desitructor is the last function called before an object is
  // destroyed.
  ~LveWindow();

  // delete the copy constructor and opporator.
  // Resource creation happens when variables are initulised.
  // Cleanups are handled by destructors.
  LveWindow(const LveWindow &) = delete;
  LveWindow &operator=(const LveWindow &) = delete;

  // returns true if the user has clicked the close button on the window.
  bool ShouldClose() { return glfwWindowShouldClose(pWindow); }

private:
  // Helper funcion for creating the window.
  void InitWindow();

  const int WIDTH, HEIGHT;
  const std::string WINDOW_NAME;
  GLFWwindow *pWindow;
};
} // namespace lve
