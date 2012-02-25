#ifndef BADGER_VIEWPORT_H
#define BADGER_VIEWPORT_H

#include "platform-shoes/map.h"
#include "platform-shoes/renderer.h"

namespace PlatformShoes {
  /*
   *  Describes a view of the world from a particular position.
   */
  class Viewport {
    public:
      /*
       *  Constructs a PlatformShoes::Viewport.
       */
      Viewport();

      /*
       *  Attaches the given PlatformShoes::Map.
       */
      void map(PlatformShoes::Map* value);

      /*
       *  Returns the current PlatformShoes::Map.
       */
      PlatformShoes::Map* map();

      /*
       *  Draws the world from the perspective of this view with the
       *    given PlatformShoes::Renderer.
       */
      void draw(Renderer* renderer);

    private:

      // Internal Storage
      Map* _map;
  };
}

#endif
