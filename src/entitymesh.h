#ifndef ENTITYMESH
#define ENTITYMESH

#include "entity.h"

class EntityMesh : public Entity {
public:
    //Attributes of this class 
    Mesh* mesh;
    Texture* texture;
    Shader* shader = NULL;
    Vector4 color;
    int quantity;
    int life = 100;
    
    //methods overwritten 
    virtual void render() = 0;
    virtual void update(double seconds_elapsed) = 0;

    //check if is dead
    bool isDead();
};

#endif
