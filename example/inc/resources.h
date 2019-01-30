#ifndef APP_RESOURCES_HPP
#define APP_RESOURCES_HPP

#include <string>
#include <GL/glew.h>
#include "core/quad.h"
#include "core/texture.h"
#include "core/program.h"

class Resources {
public:
	Resources(std::string path);
	~Resources();
	CSGE::Texture texture;
	CSGE::Program program;
	CSGE::Quad unitQuad;
};

#endif
