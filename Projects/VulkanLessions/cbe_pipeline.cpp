#include "cbe_pipeline.hpp"

// std
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

namespace CoffeeBeanEngine {

CoffeeBeanEnginePipeline::CoffeeBeanEnginePipeline(
    CoffeeBeanEngineDevice &device, const std::string &vertFilePath,
    const std::string &fragFilePath, const PipelineConfigInfo configInfo)
    : coffeeBeanEngineDevice(device) {

  CreateGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
}

std::vector<char>
CoffeeBeanEnginePipeline::ReadFile(const std::string &filepath) {
  std::ifstream file{filepath, std::ios::ate | std::ios::binary};

  if (!file.is_open()) {
    throw std::runtime_error{"ERROR:file stream open: failed to open file: " +
                             filepath};
  }

  size_t fileSize = static_cast<size_t>(file.tellg());
  std::vector<char> buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();
  return buffer;
}

void CoffeeBeanEnginePipeline::CreateGraphicsPipeline(
    const std::string &vertFilePath, const std::string &fragFilePath,
    const PipelineConfigInfo configInfo) {
  auto vertCode = ReadFile(vertFilePath);
  auto fragCode = ReadFile(fragFilePath);

  std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
  std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
}

void CoffeeBeanEnginePipeline::CreateShaderModule(
    const std::vector<char> &code, VkShaderModule *shaderModule) {
  // When using the Vulkan API, rather then calling a funcion with
  // a bunch of paramaters. We instead configure a struct and call
  // a function with a pointer to the struct. This way all our config
  // information is in one place.
  VkShaderModuleCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  // The size of our vector array.
  createInfo.codeSize = code.size();
  // We need to recast the code pointer since
  // Vulkan expects a uint32_t rather then a char array.
  // Keep in mind that a char array and a uint32_t is not the same sime
  // whilst holding the same information wihtin.
  // But since we are alreayd storing our code as a vector
  // the vector will always work off the worst case alligmnet,
  // which uses more memeory space, but will allways fit.
  createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

  if (vkCreateShaderModule(coffeeBeanEngineDevice.device(), &createInfo,
                           nullptr, shaderModule) != VK_SUCCESS) {
    throw std::runtime_error(
        "ERROR:Create Shader Module: Failed to create shader module.");
  }
}

PipelineConfigInfo
CoffeeBeanEnginePipeline::DefaultPipelineConfigInfo(uint32_t width,
                                                    uint32_t height) {
  PipelineConfigInfo configInfo{};

  return configInfo;
}

} // namespace CoffeeBeanEngine
