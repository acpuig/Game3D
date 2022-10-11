#include "skybox.h"

void SkyBox::render()
{
    Camera* camera = Camera::current;
    Matrix44 skybox_model;
    skybox_model.translate(camera->eye.x, camera->eye.y, camera->eye.z);

    shader->enable();


    shader->setUniform("u_color", Vector4(1, 1, 1, 1));
    shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
    shader->setUniform("u_texture", texture, 0);
    shader->setUniform("u_model", skybox_model);
    shader->setUniform("u_time", time);

     //render the mesh using the shader
    mesh->render(GL_TRIANGLES);


    shader->disable();
}
