#include "first_app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
  lve::FirstApp app{};

  try { // Try to start the window application.
    app.Run();
  } catch (const std::exception &e) { // catch any errors during creation.
    std::cerr << e.what() << "\n";    // output any errors to the console.
    return EXIT_FAILURE;              // return -1.
  }

  return EXIT_SUCCESS; // return >1 for sucess.
}
