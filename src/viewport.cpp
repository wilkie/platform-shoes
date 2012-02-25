#include "platform-shoes/viewport.h"

PlatformShoes::Viewport::Viewport() {
}

void PlatformShoes::Viewport::draw(Renderer* renderer) {
  unsigned int x, y;
  renderer->bindTexture(_map->spriteSheet()->texture());
  for (y = 0; y < _map->height(); y++) {
    for (x = 0; x < _map->width(); x++) {
      Tile* tile = _map->tile(x, y);
      double coords[4];
      _map->spriteSheet()->textureCoordinates(tile->spriteIndex, coords);

      Sprite* sprite = _map->spriteSheet()->sprite(tile->spriteIndex);
      renderer->drawSquare(x*32.0f, y*32.0f,
                           (float)sprite->width, (float)sprite->height,
                           coords[0], coords[1], coords[2], coords[3]);
    }
  }
}

PlatformShoes::Map* PlatformShoes::Viewport::map() {
  return _map;
}

void PlatformShoes::Viewport::map(PlatformShoes::Map* value) {
  _map = value;
}
