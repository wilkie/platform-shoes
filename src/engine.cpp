#include "platform-shoes/engine.h"

#include "math.h"

PlatformShoes::Engine::Engine(VideoSettings* video) {
	_video = *video;
	if (!_initialize()) {
		return;
	}
	_renderer = new Renderer();
}

void PlatformShoes::Engine::_draw() {
	_renderer->clear();
}

void PlatformShoes::Engine::run() {
	SDL_Event event;
	while(true) {
		if (!SDL_PollEvent(&event)) {
			_draw();
			SDL_GL_SwapBuffers();
			SDL_Delay(1);
		}
		else {
			if(event.type == SDL_QUIT) {
				break;
			}
			_fireEvent(&event);
		}
	}

	// destruct SDL
	SDL_Quit();
}

bool PlatformShoes::Engine::_initialize() {
	if (_startSDL()) {
		_initViewport();
		return true;
	}

	fprintf(stderr, "Engine cannot initialize.");
	return false;
}

void PlatformShoes::Engine::_initViewport() {
}

bool PlatformShoes::Engine::_startSDL() {
#ifdef NO_SDL
	return false;
#else
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,         32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,        1);

	SDL_Surface* surf_display;
	if((surf_display = SDL_SetVideoMode(_video.resolutionX, _video.resolutionY, 32, SDL_HWSURFACE | SDL_OPENGL)) == NULL) {
		fprintf(stderr, "Unable to initialize SDL: SDL_SetVideoMode failed\n");
        return false;
    }

	SDL_WM_SetCaption("PlatformShoes", "PlatformShoes");

	return true;
#endif
}

void PlatformShoes::Engine::_fireEvent(void* data) {
	SDL_Event* event = (SDL_Event*)data;
	if (event->type == SDL_MOUSEBUTTONDOWN) {	
		switch(event->button.button) {
		case SDL_BUTTON_LEFT:
			break;
		}
	}
	else if (event->type == SDL_KEYDOWN) {
		switch(event->key.keysym.sym) {
		case SDLK_LEFT:
		case SDLK_h:
			break;
		case SDLK_RIGHT:
		case SDLK_l:
			break;
		case SDLK_UP:
		case SDLK_k:
			break;
		case SDLK_DOWN:
		case SDLK_j:
			break;
		case SDLK_COMMA:
			break;
		case SDLK_PERIOD:
			break;
		case SDLK_EQUALS:
			break;
		case SDLK_MINUS:
			break;
		}
	}
}

