#ifndef ENTITY
#define ENTITY

#include <iostream>

#include "framework.h"
#include "mesh.h"
#include "shader.h"
#include "camera.h"
#include "texture.h"

class Entity {
public:
    Entity() {}; //constructor
    virtual ~Entity() {}; //destructor

    //some attributes 
    std::string name;
    Matrix44 model;
    //methods overwritten by derived classes 
    virtual void render() = 0;
    virtual void update(double seconds_elapsed) = 0;

    //some useful methods...
    Vector3 getPosition();

};

#endif