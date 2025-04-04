#pragma once
#include <raylib.h>
#include <vector>

// https://www.color-hex.com/color-palette/72219
extern const Color Background;
extern const Color BackgroundLight; 
extern const Color Middle;
extern const Color DarkLight; 
extern const Color Light; 

std::vector<Color> GetPaletteColors();

