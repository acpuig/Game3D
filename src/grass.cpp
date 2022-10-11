#include "grass.h"

Grass::Grass()
{
	quantity = 400;
}

void Grass::render()
{
    Camera* camera = Camera::current;
    Matrix44 model = this->model;
    shader->enable();
    for (int i = 0; i < quantity; i+=2) {
        for (int j = 0; j < quantity; j+=2) {
            
           model.setTranslation(i, 0.0f, j);
           Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
           if (!camera->testSphereInFrustum(current_pos_world,this->mesh->radius)) continue;
           // shader->setUniform("u_color", Vector4(1, 1, 1, 1));
            shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
            shader->setUniform("u_texture", texture, 0);
            shader->setUniform("u_model", model);
           // shader->setUniform("u_time", time);


            //render the mesh using the shader
            mesh->render(GL_TRIANGLES);
        }
    }
    
    for (int i = 0; i < quantity; i += 2) {
        for (int j = 0; j < quantity; j += 2) {

            model.setTranslation(-i, 0.0f, j);
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
    }
    for (int i = 0; i < quantity; i += 2) {
        for (int j = 0; j < quantity; j += 2) {

            model.setTranslation(i, 0.0f, -j);
            Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
            if(!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;

            shader->setUniform("u_color", Vector4(1, 1, 1, 1));
            shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
            shader->setUniform("u_texture", texture, 0);
            shader->setUniform("u_model", model);
            // shader->setUniform("u_time", time);

            //model.setTranslation(i, 0.0f, -j);
            //render the mesh using the shader
            mesh->render(GL_TRIANGLES);
        }
    }
    for (int i = 0; i < quantity; i += 2) {
        for (int j = 0; j < quantity; j += 2) {

            model.setTranslation(-i, 0.0f, -j);
            Vector3 current_pos_world = model * Vector3(0.0f, 0.0f, 0.0f);
            if (!camera->testSphereInFrustum(current_pos_world, this->mesh->radius)) continue;

            shader->setUniform("u_color", Vector4(1, 1, 1, 1));
            shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
            shader->setUniform("u_texture", texture, 0);
            shader->setUniform("u_model", model);
            // shader->setUniform("u_time", time);

           // model.setTranslation(-i, 0.0f, -j);
            //render the mesh using the shader
            mesh->render(GL_TRIANGLES);
        }
    }
    
    //disable the shader after finishing rendering
    shader->disable();
}
