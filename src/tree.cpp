#include "tree.h"

Tree::Tree()
{
    quantity = 200;
}

void Tree::render()
{
    Camera* camera = Camera::current;
    Matrix44 model = this->model;
    shader->enable();
     int  result = rand() % 10;
    if (result < 2) {
        for (int i = 0; i < quantity; i += 2) {
            for (int j = 0; j < quantity; j += 2) {
              // int  result = rand() % 10;
               //    if (result < 2) {
                    model.setTranslation(i - 350, 0.0f, j - 350);
                    Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
                    if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;
                           // shader->setUniform("u_color", Vector4(1, 1, 1, 1));
                    shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
                    shader->setUniform("u_texture", texture, 0);
                    shader->setUniform("u_model", model);
                    // shader->setUniform("u_time", time);
                            //render the mesh using the shader
                    mesh->render(GL_TRIANGLES);
             
            }
        }
    }

    //disable the shader after finishing rendering
    shader->disable();
}
