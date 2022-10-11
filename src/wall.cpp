#include "wall.h"

Wall::Wall(int x, int y,int degr)
{
    this->x = x;
    this->y = y;
    this->model.translate(x, 0.0f, y);
    this->model.rotate(degr * DEG2RAD, Vector3(0.0f, 1.0f, 0.0f));
    life = 10000000000;

}

void Wall::render()
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
