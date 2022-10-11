#include "asphalt.h"

Asphalt::Asphalt()
{
    quantity =  600;
}

void Asphalt::render()
{
    Camera* camera = Camera::current;
    Matrix44 model = this->model;
    shader->enable();
    int main_avenue = 600;
    int perp_avenue = 600;

    //1rst Vertical Avnenue
    for (int j = 0; j < main_avenue; j += 2) {

            model.setTranslation(300.0f, 1.0f, j - 300.0f);
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
    

    //2nd Vertical Avnenue
    for (int j = 0; j < main_avenue; j += 2) {

        model.setTranslation(150.0f, 1.0f, j - 300.0f);
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

    //3ra Vertical Avenue
    for (int j = 0; j < main_avenue; j += 2) {

        model.setTranslation(-300.0f, 1.0f, j - 300.0f);
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

    //4rst Vertical Avnenue
    for (int j = 0; j < 325; j += 2) {

        model.setTranslation(-100.0f, 1.0f, j - 225.0f);
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



    //1r carrer perpendicular
    for (int i = 0; i < perp_avenue; i += 3) {

        model.setTranslation(300.0f - i, 1.0f, -225.0f);
        Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
        if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;

        shader->setUniform("u_color", Vector4(1, 1, 1, 1));
        shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
        shader->setUniform("u_texture", texture, 0);
        shader->setUniform("u_model", model);
        // shader->setUniform("u_time", time);
       // model.setTranslation(-i, 0.0f, j);
        //render the mesh using the shader
        mesh->render(GL_TRIANGLES);
    }

    //2n carrer perpendicular
    for (int i = 0; i < perp_avenue; i += 2) {

        model.setTranslation(300.0f - i, 1.0f, 300.0f);
        Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
        if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;

        shader->setUniform("u_color", Vector4(1, 1, 1, 1));
        shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
        shader->setUniform("u_texture", texture, 0);
        shader->setUniform("u_model", model);
        // shader->setUniform("u_time", time);
       // model.setTranslation(-i, 0.0f, j);
        //render the mesh using the shader
        mesh->render(GL_TRIANGLES);
    }

    //3n carrer perpendicular
    for (int i = 0; i < 450; i += 2) {

        model.setTranslation(150.0f - i, 1.0f, 100.0f);
        Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
        if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;

        shader->setUniform("u_color", Vector4(1, 1, 1, 1));
        shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
        shader->setUniform("u_texture", texture, 0);
        shader->setUniform("u_model", model);
        // shader->setUniform("u_time", time);
       // model.setTranslation(-i, 0.0f, j);
        //render the mesh using the shader
        mesh->render(GL_TRIANGLES);
    }

    //disable the shader after finishing rendering
    shader->disable();
}
