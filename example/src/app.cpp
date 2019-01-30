
#include <iostream>

#include "core/texture.h"
#include "core/shader.h"
#include "core/program.h"
#include "app.h"
#include "config.h"
#include "resources.h"
#include "engine.h"

using namespace std;
using namespace CSGE;

void App::run() {
	SDL_Event e;
	auto quit = false;
	Resources resources(Config::basedir);
	Engine engine(window, resources);

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				auto key = e.key.keysym.sym;
				if (key == SDLK_q || key == SDLK_ESCAPE) {
					quit = true;
				} else {
					std::cout << "key: " <<  key << std::endl ;
				}
			}
		}

		if (quit) {
			break;
		}
		engine.doFrame();
	}
}
