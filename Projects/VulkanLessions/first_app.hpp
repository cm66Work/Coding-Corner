#include "lve_window.hpp"

namespace lve {
class FirstApp {
public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void Run();

private:
  LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
};
} // namespace lve
