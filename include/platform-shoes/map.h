#ifndef BADGER_MAP_H
#define BADGER_MAP_H

#include "platform-shoes/tile.h"
#include "platform-shoes/sprite_sheet.h"

namespace PlatformShoes {
  /*
   *  Describes a world made out of tiles drawn from a single SpriteSheet.
   */
  class Map {
    public:
      /*
       *  Constructs a PlatformShoes::Map of the given width and height and drawn
       *    using the given PlatformShoes::SpriteSheet
       */
      Map(unsigned int width,
          unsigned int height,
          SpriteSheet* spriteSheet);

      /*
       *  Queries the tile at the world coordinates (x,y)
       */
      Tile*        tile(unsigned int x, unsigned int y);

      /*
       *  Returns the width of the map.
       */
      unsigned int width();

      /*
       *  Returns the height of the map
       */
      unsigned int height();

      /*
       *  Returns the PlatformShoes::SpriteSheet being used to draw the map.
       */
      SpriteSheet* spriteSheet();

    private:

      // Internal storage
      unsigned int _width;
      unsigned int _height;
      SpriteSheet* _spriteSheet;

      // The tiles that compose the map
      Tile*        _tiles;
  };
}

#endif
