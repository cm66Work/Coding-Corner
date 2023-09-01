#ifndef CBE_FIRST_APP_HPP
#define CBE_FIRST_APP_HPP

#include "cbe_device.hpp"
#include "cbe_pipeline.hpp"
#include "cbe_window.hpp"

namespace CoffeeBeanEngine {
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
  CoffeeBeanEngineWindow coffeeBeanEngineWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
  CoffeeBeanEngineDevice coffeeBeanEngineDevice{coffeeBeanEngineWindow};
  CoffeeBeanEnginePipeline coffeeBeanEnginePipeLine{
      coffeeBeanEngineDevice, "shaders/simple_shadter.vert.spv",
      "shaders/simple_shader.frag.spv",
      CoffeeBeanEnginePipeline::DefaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
} // namespace CoffeeBeanEngine
#endif // !lve_first_app_hpp
