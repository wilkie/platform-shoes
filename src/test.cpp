#include "platform-shoes.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv) {
  // initialize engine
  PlatformShoes::VideoSettings settings;
  settings.resolutionX = WIDTH;
  settings.resolutionY = HEIGHT;
  PlatformShoes::Engine* engine = new PlatformShoes::Engine(&settings);
  PlatformShoes::SpriteSheet* sheet = new PlatformShoes::SpriteSheet("assets/floortiles.png");
  PlatformShoes::Map* map = new PlatformShoes::Map(100, 100, sheet);
  engine->map(map);
  engine->run();

  return 0;
}
