#include "ConsoleGraphics.hpp"

// std
#include <iostream>

namespace ES_ConsoleGraphics {
void ConsoleGraphics::Run() {
  for (int height = 0; height < ConsoleGraphics::HEIGHT; height++) {
    for (int width = 0; width < ConsoleGraphics::WIDTH; width++) {
      std::cout << "X";
    }
    std::cout << "\n";
  }
}
} // namespace ES_ConsoleGraphics
