#include "bullet.h"
#include "world.h"

Bullet::Bullet(int x, int y, int type)
{
    this->type = type;

    pos.set(x, y, 3.0f);
    this->model.translate(pos.x, 3.0f, pos.y + 3.5f);
    pos.set(x, 3.0f, y);
    World* world;
    world = World::getInstance();
    if (this->type == 0) {
        angle = world->tank->yaw;
        bullRot.setRotation(angle * DEG2RAD, Vector3(0, 1, 0));
    }
    if (this->type == 1) {
        angle = world->tank->yaw;
        bullRot.setRotation(angle * DEG2RAD, Vector3(0, 1, 0));
    }

}

void Bullet::update(double seconds_elapsed)
{

    //Vector3 bulletFront = Vector3(0.0f, 0.0f, 1.0f);
    float speed = 1.f;
    // Vector3 bulletSpeed = bulletSpeed + (playerFront * -speed);

    World* world;
    world = World::getInstance();

    if (type == 0) {
        speed = 3.f;
        Vector3 bullFront = bullRot.rotateVector(Vector3(0.0f, 0.0f, -1.0f));
        targetpos = pos + bullFront * (speed * Vector3(-1.0f, 0.0f, -1.0f));
        Vector3 characterTargetCenter = targetpos + Vector3(0.0f, 1.0f, 0.0f);

        for (int i = 0; i < world->static_entities.size(); i++)
        {
            EntityMesh* current = static_cast<EntityMesh*>(world->static_entities[i]);
            Vector3 coll;
            Vector3 collnorm;
            if (!current->mesh->testSphereCollision(current->model, characterTargetCenter, 4.0f, coll, collnorm)) continue;

            colisionasteWEY = true;
            current->life -= 25;
        }
        for (int i = 0; i < world->walls.size(); i++)
        {
            EntityMesh* current = static_cast<EntityMesh*>(world->walls[i]);
            Vector3 coll;
            Vector3 collnorm;
            if (!current->mesh->testSphereCollision(current->model, characterTargetCenter, 4.0f, coll, collnorm)) continue;

            colisionasteWEY = true;
        }

    }
    if (type == 1)
    {
        Vector3 bullFront = bullRot.rotateVector(Vector3(0.0f, 0.0f, 1.0f));
        targetpos = pos + bullFront * (speed * Vector3(-1.0f, 0.0f, -1.0f));

        Vector3 characterTargetCenter = targetpos + Vector3(0.0f, 1.0f, 0.0f);

        for (int i = 0; i < world->walls.size(); i++)
        {
            EntityMesh* current = static_cast<EntityMesh*>(world->walls[i]);
            Vector3 coll;
            Vector3 collnorm;
            if (!current->mesh->testSphereCollision(current->model, characterTargetCenter, 4.0f, coll, collnorm)) continue;

            colisionasteWEY = true;
        }
        Vector3 coll;
        Vector3 collnorm;
        if (world->tank->mesh->testSphereCollision(world->tank->model, characterTargetCenter, 1.5f, coll, collnorm))
        {
            world->tank->life -= 10;
            colisionasteWEY = true;
        }
        
    }
   

  
    pos = targetpos;
    Matrix44 newmodel;
    newmodel.translate(targetpos.x, 3.0f, targetpos.z);
    newmodel.rotate(angle * DEG2RAD, Vector3(0.0f, 1.0f, 0.0f));
    this->model = newmodel;
    
    
}

void Bullet::render()
{
    Camera* camera = Camera::current;
    Matrix44 modelo = this->model;
    //modelo = modelo * tankModel;
    World* world;
    world = World::getInstance();

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
