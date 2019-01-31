#ifndef GLFX_SPRITE_HPP
#define GLFX_SPRITE_HPP

#include "glm/vec2.hpp"

#include "node.h"
#include "quad.h"

namespace CSGE {

class Sprite : public Node {
public:
	Sprite(const Quad& quad);
	~Sprite() = default;
	const Quad& quad;
	glm::vec2 position;
	glm::vec2 scale;
	float rotation;
};

}

#endif
