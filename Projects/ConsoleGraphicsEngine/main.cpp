#include "cbe_Engine.hpp"

// std
#include <iostream>
#include <stdexcept>

int main() {

  CoffeeBeanEngine::Engine engine{};

  try {
    engine.Run();
  } catch (const std::exception &e) { // catch any errors during creation.
    std::cerr << e.what() << "\n";    // output any errors to the console.
    return EXIT_FAILURE;              // return -1.
  }

  return EXIT_SUCCESS;
}
