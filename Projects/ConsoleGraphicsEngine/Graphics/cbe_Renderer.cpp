
#include "cbe_Renderer.hpp"

// std
#include <iostream>

namespace CoffeeBeanEngine {

WindowRenderer::WindowRenderer(const int wWidth, const int wHight)
    : width(wWidth), height(wHight) {}

void WindowRenderer::DrawScreen() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      std::cout << "X";
    }
    std::cout << "\n";
  }

  ClearScreen();
}

void WindowRenderer::ClearScreen() { system("cls"); }
} // namespace CoffeeBeanEngine
