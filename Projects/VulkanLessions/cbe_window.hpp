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

#ifndef CBE_WINDOW_HPP
#define CBE_WINDOW_HPP
namespace CoffeeBeanEngine {
class CoffeeBeanEngineWindow {
public:
  CoffeeBeanEngineWindow(int w, int h, std::string name);
  // desitructor is the last function called before an object is
  // destroyed.
  ~CoffeeBeanEngineWindow();

  // delete the copy constructor and opporator.
  // Resource creation happens when variables are initulised.
  // Cleanups are handled by destructors.
  CoffeeBeanEngineWindow(const CoffeeBeanEngineWindow &) = delete;
  CoffeeBeanEngineWindow &operator=(const CoffeeBeanEngineWindow &) = delete;

  // returns true if the user has clicked the close button on the window.
  bool ShouldClose() { return glfwWindowShouldClose(pWindow); }

  void CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

private:
  // Helper funcion for creating the window.
  void InitWindow();

  const int WIDTH, HEIGHT;
  const std::string WINDOW_NAME;
  GLFWwindow *pWindow;
};
} // namespace CoffeeBeanEngine
#endif
