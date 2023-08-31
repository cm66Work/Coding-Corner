#include "lve_pipeline.hpp"
#include "lve_window.hpp"

#ifndef LVE_FIRST_APP_HPP
#define LVE_FIRST_APP_HPP

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
  LvePipeline lvePipeLine{"shaders/simple_shadter.vert.spv",
                          "shaders/simple_shadter.frag.spv"};
};
} // namespace lve
#endif // !lve_first_app_hpp
