#include "Palette.h"

const Color Background = {25,23,22,255};
const Color BackgroundLight = {68,13,15,255};
const Color Middle = {96,58,64,255};
const Color DarkLight = {132,89,107,255};
const Color Light = {175, 155, 182,255};

std::vector<Color> GetPaletteColors()
{
  return {Background, BackgroundLight, Middle, DarkLight, Light};
}