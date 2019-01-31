#ifndef GLFX_SCENE_HPP
#define GLFX_SCENE_HPP

#include <memory>
#include <stdint>

#include <glm/vec2.hpp>

#include "quadbatch.h"
#include "nodelist.h"

namespace CSGE {

class Scene {
public:
    Scene(const Program &program, const Texture &texture);
    ~Scene();
    QuadBatch quadBatch;
    glm::vec2 viewport = {1.0f, 1.0f};
    std::shared_ptr<CSGE::Sprite> createSprite(const Quad& quad);
    void render();
    
    void addNode(Node &node);
    
    
    void removeNode(Node &node);
    
    void removeNode(uint32_t id);
    
private:
    NodeList nodeList;
    
};

}

#endif
