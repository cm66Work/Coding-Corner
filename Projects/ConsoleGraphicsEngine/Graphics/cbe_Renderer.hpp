
namespace CoffeeBeanEngine {

class WindowRenderer {

public:
  WindowRenderer(const int wWidth, const int wHight);

  void DrawScreen();

private:
  const int width, height;

  void ClearScreen();
};

} // namespace CoffeeBeanEngine
