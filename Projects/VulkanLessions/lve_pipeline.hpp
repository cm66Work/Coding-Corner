#include <string>
#include <vector>

#ifndef LVE_PIPELINE_HPP
#define LVE_PIPELINE_HPP

namespace lve {
class LvePipeline {
public:
  LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath);

private:
  static std::vector<char> ReadFile(const std::string &filepath);

  void CreateGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath);
};
} // namespace lve
#endif // ! LVE_PIPELINE_HPP
