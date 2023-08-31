#include "lve_pipeline.hpp"

// std
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {

LvePipeline::LvePipeline(const std::string &vertFilePath,
                         const std::string &fragFilePath) {
  CreateGraphicsPipeline(vertFilePath, fragFilePath);
}

std::vector<char> LvePipeline::ReadFile(const std::string &filepath) {
  std::fstream file{filepath, std::ios::ate | std::ios::binary};

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

void LvePipeline::CreateGraphicsPipeline(const std::string &vertFilePath,
                                         const std::string &fragFilePath) {
  auto vertCode = ReadFile(vertFilePath);
  auto fragCode = ReadFile(fragFilePath);

  std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
  std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
}
} // namespace lve
