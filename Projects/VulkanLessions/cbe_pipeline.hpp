
#ifndef CBE_PIPELINE_HPP
#define CBE_PIPELINE_HPP

#include "cbe_device.hpp"

// std
#include <string>
#include <vector>

namespace CoffeeBeanEngine {

// contains the data to specify how we want to configure
// our pipeline.
//
// Allows the application layer to configure our pipeline completely.
struct PipelineConfigInfo {};

class CoffeeBeanEnginePipeline {
public:
  CoffeeBeanEnginePipeline(CoffeeBeanEngineDevice &device,
                           const std::string &vertFilePath,
                           const std::string &fragFilePath,
                           const PipelineConfigInfo configInfo);
  ~CoffeeBeanEnginePipeline() {}

  // deleate copy constructors to avoid duplicating pointers to
  // Vulkan Objects.
  CoffeeBeanEnginePipeline(const CoffeeBeanEnginePipeline &) = delete;
  void operator=(const CoffeeBeanEnginePipeline &) = delete;

  static PipelineConfigInfo DefaultPipelineConfigInfo(uint32_t width,
                                                      uint32_t height);

private:
  static std::vector<char> ReadFile(const std::string &filepath);

  void CreateGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath,
                              const PipelineConfigInfo configInfo);

  // VkShaderModule is a pointer, and this takes in a pointer.
  // So this is a pointer to a pointer.
  void CreateShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule);

  // WARNING!! Memory unsafe.
  // if the devive is released from memeory before the pipeline
  // will result in a memeory leake.
  //
  // The only reason why this is here is becase the devive should always
  // outlive everything else. Unless the user removes their graphics card
  // with the computer still running.
  // This is also made safer by the fact that for a pipeline to
  // exits, there needs to be a device.
  // TODO: Review for possible fix to make memeory safe.
  CoffeeBeanEngineDevice &coffeeBeanEngineDevice;

  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;
};
} // namespace CoffeeBeanEngine
#endif // !DEBUG
