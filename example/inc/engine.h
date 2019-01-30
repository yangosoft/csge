#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <vector>
#include "core/window.h"
#include "core/sprite.h"
#include "core/scene.h"
#include "resources.h"

class Engine {
public:
	Engine(CSGE::Window& window, Resources& resources);
	~Engine();
	void doFrame();
protected:
	CSGE::Window& window;
	CSGE::Scene scene;
	Uint32 prevT = 0;
	Resources& resources;
	std::vector<std::shared_ptr<CSGE::Sprite>> sprites;
	void update(Uint32 dt);
	void render();
};

#endif
