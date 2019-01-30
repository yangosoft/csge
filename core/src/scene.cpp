#include "core/scene.h"

using namespace std;
using namespace CSGE;

Scene::Scene(const Program &p, const Texture &t): quadBatch(p, t) {}

Scene::~Scene() {}

shared_ptr<CSGE::Sprite> Scene::createSprite (const Quad& quad) {
	return shared_ptr<Sprite>(new Sprite(quad));
}

void Scene::render() {
	quadBatch.render(viewport);
}
