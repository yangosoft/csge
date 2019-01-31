#ifndef NODE_H
#define NODE_H


#include <cstdint>
#include <string>
#include <vector>

#include "nodelist.h"

namespace CSGE {

class Node
{
    
    
    
public:
    /**
     * Default constructor
     */
    Node();

    

       

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator==(const Node& other) const;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!=(const Node& other) const;
    
    
    void addChild(Node& child);
    
    virtual void update(double deltaMs);
    
    uint32_t getId() const;
    
    void setId(uint32_t id);
    
    
    std::string getName() const;
    
    void setName(const std::string& name);

    virtual void show();
    
    virtual void hide();
    
    virtual ~Node() = default;
    
    

protected:
    NodeList childs;
    uint32_t id;
    std::string name;

    /**
     * Assignment operator
     *
     * @param other TODO
     * @return TODO
     */
    Node& operator=(const Node& other);
    
    /**
     * Copy constructor
     *
     * @param other TODO
     */
    Node(const Node& other);
    
};
}
#endif // NODE_H
