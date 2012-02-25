#ifndef BADGER_ENGINE_H
#define BADGER_ENGINE_H

#include <platform-shoes/renderer.h>
#include <platform-shoes/viewport.h>
#include <platform-shoes/map.h>

// This is here instead of the cpp because main() is overriden by
// preprocessor magicks.
#ifndef NO_SDL
#include <sdl.h>
#endif

namespace PlatformShoes {
  /*
   *  Describes the display configuration the Engine should attempt to use.
   */
  struct VideoSettings {
    /*
     *  The horizontal resolution.
     */
    unsigned int resolutionX;

    /*
     *  The vertical resolution.
     */
    unsigned int resolutionY;
  };

  /*
   *  Handles rendering and most major logic.
   */
  class Engine {
    public:
      /*
       *  Construct an Engine initialized with the given display configuration
       */
      Engine(VideoSettings* video);

      /*
       *  Attach the given PlatformShoes::Map.
       */
      void map(Map* value);

      /*
       *  Execute the game loop. There is no escape from this function until the game ends.
       */
      void run();

    private:

      // Internal storage
      VideoSettings _video;
      Renderer*     _renderer;
      Viewport*     _mainViewport;
      Map*          _map;

      // Initialization methods
      bool _startSDL();
      bool _initialize();
      void _initViewport();

      // Input event handler
      void _fireEvent(void* data);

      // Called to draw a frame
      void _draw();

      // Called to update all game objects
      void _update();
  };
}

#endif
