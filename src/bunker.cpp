#include "bunker.h"
#include "world.h"

Bunker::Bunker(int x,int y)
{
    pos.set(x, 0.0f, y);
    this->model.translate(x, 0.0f, y);
    life = 100;
   
}

void Bunker::update(double seconds_elapsed)
{
    World* world;
    world = World::getInstance();
    initial_time += seconds_elapsed;
    if (initial_time > 0.5) {
        world->createBullet(1, pos);
        initial_time = 0.0;
    }
}

void Bunker::render()
{

    Camera* camera = Camera::current;
    Matrix44 modelo = this->model;
   
    shader->enable();
        

        Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
        if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) return;
        shader->setUniform("u_color", Vector4(1, 1, 1, 1));
        shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
        shader->setUniform("u_texture", texture, 0);
        shader->setUniform("u_model", modelo);
        shader->setUniform("u_time", time);

         //render the mesh using the shader
        mesh->render(GL_TRIANGLES);


    shader->disable();
}

Vector3 Bunker::getPosition()
{
    return pos;
}



