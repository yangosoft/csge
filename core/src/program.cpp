#include <iostream>
#include <stdexcept>

#include "core/program.h"

using namespace std;
using namespace CSGE;

Program::Program(
	GLuint vert, GLuint frag,
	const vector<const char*> attribs, const vector<const char*> uniforms
): id{glCreateProgram()} {
	if (id == 0) {
		throw runtime_error("Failed to create program");
	}
	glAttachShader(id, vert);
	glAttachShader(id, frag);

	glLinkProgram(id);

	GLint linked;
	glGetProgramiv(id, GL_LINK_STATUS, &linked);
	if (!linked) {
		GLint infoLen = 0;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLen);
		string message = "Error linking program";
		if (infoLen > 1) {
			auto infoLog = new char[infoLen + 4];
			glGetProgramInfoLog(id, infoLen, nullptr, infoLog);
			message += string(":\n") + infoLog;
			delete[] infoLog;
		}
		glDeleteProgram(id);
		throw runtime_error(message);
	}

	// Collect attrib locations
	for (auto aname: attribs) {
		auto a = glGetAttribLocation(id, aname);
		if (a == -1) {
			throw runtime_error(string("Failed to get attrib location for: ") + aname);
		}
		attribLocations[aname] = a;
		std::cout << "Got attrib " << aname << " location " << a << std::endl;
		glEnableVertexAttribArray(a);
	}
	for (auto uname: uniforms) {
		auto u = glGetUniformLocation(id, uname);
		if (u == -1) {
			throw runtime_error(string("Failed to get uniform location for: ") + uname);
		}
		uniformLocations[uname] = u;
		std::cout << "Got uniform " << uname << " location "<< u << std::endl;
	}
}

Program::~Program() {
	glDeleteProgram(id);
}
