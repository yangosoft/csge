#include "core/node.h"


using namespace CSGE;

Node::Node()
{

}

Node::Node(const Node& other)
{

}



Node& Node::operator=(const Node& other)
{
    
}

bool Node::operator==(const Node& other) const
{
    return id == other.id;
}

bool Node::operator!=(const Node& other) const
{
    return id != other.id;
}

void Node::addChild(Node& child)
{
    childs.push_back( &child );
}

void Node::update(double deltaMs)
{
    
}
    
uint32_t Node::getId() const
{
    return id;
}

void Node::setId(uint32_t id)
{
    this->id = id;
}
    
std::string Node::getName() const
{
    return name;
}
    
void Node::setName(const std::string& name)
{
    this->name = name;
}

void Node::show()
{
    
}
    
void Node::hide()
{
    
}

