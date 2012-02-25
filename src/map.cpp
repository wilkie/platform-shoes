#include "platform-shoes/map.h"

#include <string.h>

PlatformShoes::Map::Map(unsigned int width,
                 unsigned int height,
                 SpriteSheet* spriteSheet) : 
                   _width(width),
                   _height(height) {
  _tiles = new Tile[_width * _height];
  memset(_tiles, 0, _width*_height*sizeof(Tile));
  for(unsigned int x = 0; x < _width * _height; x++) {
    _tiles[x].spriteIndex = rand() % 20;
  }
  _spriteSheet = spriteSheet;
}

unsigned int PlatformShoes::Map::width() {
  return _width;
}

unsigned int PlatformShoes::Map::height() {
  return _height;
}

PlatformShoes::Tile* PlatformShoes::Map::tile(unsigned int x, unsigned int y) {
  return &_tiles[(y * _width) + x];
}

PlatformShoes::SpriteSheet* PlatformShoes::Map::spriteSheet() {
  return _spriteSheet;
}
