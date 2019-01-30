#include "resources.h"
#include "core/texture.h"
#include "core/shader.h"
#include "core/program.h"
#include "shaders.h"

using namespace std;
using namespace CSGE;

Resources::Resources (string path):
	program(
		Shader::create(GL_VERTEX_SHADER, Shaders::tex_vert),
		Shader::create(GL_FRAGMENT_SHADER, Shaders::tex_frag),
		{"aPosition", "aUv"}, {"uTexture", "uViewport"}
	),
	texture(Texture((path + "/tex/ship.png").c_str()))
{
	printf("Initialized resources\n");
}

Resources::~Resources() {}
