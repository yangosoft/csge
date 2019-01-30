#ifndef GLFX_SCENE_HPP
#define GLFX_SCENE_HPP

#include <memory>

#include <glm/vec2.hpp>

#include "quadbatch.h"

namespace CSGE {

class Scene {
public:
    Scene(const Program &program, const Texture &texture);
    ~Scene();
	QuadBatch quadBatch;
    glm::vec2 viewport = {1.0f, 1.0f};
	std::shared_ptr<CSGE::Sprite> createSprite(const Quad& quad);
	void render();
};

}

#endif
