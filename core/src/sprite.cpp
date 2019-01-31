#include <stdio.h>
#include "core/sprite.h"

using namespace CSGE;

Sprite::Sprite(const Quad &q): quad(q) {
	position = {0.0f, 0.0f};
	scale = {1.0f, 1.0f};
	rotation = 0.0f;
}

