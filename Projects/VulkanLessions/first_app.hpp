#include "lve_window.hpp"

namespace lve {
class FirstApp {
public:
  // Constents for the windwos Width and Height.
  // Change this to change the default window size.
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  // Gets called when the program starts.
  void Run();

private:
  // Actually create the window how.
  // We do not need to handle pointers or dynamic memeory allocation
  // since that is all handled by at lower levels.
  LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
};
} // namespace lve
