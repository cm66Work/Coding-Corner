#include <iostream>

namespace ES_Core {

std::wstring tetramino[7];

int _fieldWithd = 12;
int _fieldHeight = 18;
// Element storage for the game.
// 0 is empty, and then each following number represents a shape.
unsigned char *pField = nullptr;

void CreateShapes();
void CreateGameBoard();
int Rotate(int px, int py, int r);

int main() {
  CreateShapes();
  return 0;
}

void CreateShapes() {
  // appending to the end of each tetramino we can build a fake 2D array
  // that goes from 0 to 15 where 0 is equal to (0,0) and 15 is equal to (3,3).
  //
  // As a result we can rotate each tetramino by changing how we get the index
  // for each rotation.
  //
  // 0)   i = y*w+x
  // 90)  i = 12+y-(x*4)
  // 180) i = 15-(y*c=4)-x
  // 270) i = 3+y+(x*4)
  tetramino[0].append(L"..X.");
  tetramino[0].append(L"..X.");
  tetramino[0].append(L"..X.");
  tetramino[0].append(L"..X.");

  tetramino[1].append(L"..X.");
  tetramino[1].append(L".XX.");
  tetramino[1].append(L".X..");
  tetramino[1].append(L"....");

  tetramino[2].append(L".X..");
  tetramino[2].append(L".XX.");
  tetramino[2].append(L"..X.");
  tetramino[2].append(L"....");

  tetramino[3].append(L"....");
  tetramino[3].append(L".XX.");
  tetramino[3].append(L".XX.");
  tetramino[3].append(L"....");

  tetramino[4].append(L"..X.");
  tetramino[4].append(L".XX.");
  tetramino[4].append(L"..X.");
  tetramino[4].append(L"....");

  tetramino[5].append(L".XX.");
  tetramino[5].append(L"..X.");
  tetramino[5].append(L"..X.");
  tetramino[5].append(L"..X.");

  tetramino[6].append(L".X..");
  tetramino[6].append(L".X..");
  tetramino[6].append(L".X..");
  tetramino[6].append(L".XX.");
}

void CreateGameBoard() {
  pField = new unsigned char[_fieldWithd *
                             _fieldHeight]; // Create play field buffer.
  // board boundry.
  for (int x = 0; x < _fieldWithd; x++) {
    for (int y = 0; y < _fieldHeight; y++) {
      // build the board:
      // 0: Empty space.
      // 9: Board.
      pField[y * _fieldWithd + x] =
          (x == 0 || x == _fieldWithd - 1 || y == _fieldHeight - 1) ? 9 : 0;
    }
  }
}

int Rotate(int px, int py, int r) {
  switch (r % 4) {
  case 0:
    return py * 4 + px; // no rotation.
  case 1:
    return 12 + py - (px * 4); // 90 degree rotation.
  case 2:
    return 15 - (py * 4) - px; // 180 degree rotation.
  case 3:
    return 3 - py + (px * 4); // 270 degree rotation.
  }
  return -1;
}

} // namespace ES_Core
