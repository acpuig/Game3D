#include "projectile.h"

Projectile::Projectile()
{
  //  this->model.translate;
}

//void Projectile::render(Matrix44 model)
//{
//    
//    Camera* camera = Camera::current;
//    Matrix44 modelo = this->model;
//
//    shader->enable();
//
//
//    Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
//    if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) return;
//    shader->setUniform("u_color", Vector4(1, 1, 1, 1));
//    shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
//    shader->setUniform("u_texture", texture, 0);
//    shader->setUniform("u_model", modelo);
//    shader->setUniform("u_time", time);
//
//    //render the mesh using the shader
//    mesh->render(GL_TRIANGLES);
//
//
//    shader->disable();
//}



