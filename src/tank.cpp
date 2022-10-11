#include "tank.h"
#include "input.h"
#include "world.h"



Tank::Tank()
{
	pos.set(300.0f, 1.0f, -330.0f);
	this->model.translate(pos.x,pos.y,pos.z);
	life = 200;
	
}
void Tank::render()
{
	    //get the last camera that was activated
	Camera* camera = Camera::current;
    
	Vector3 eye = this->model * Vector3(0.0f, 5.0f, -8.0f);
	Vector3 center = this->model * Vector3(0.0f, 3.5f, 0.0f);
	Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
	camera->lookAt(eye, center, up);

	World* world;
	world = World::getInstance();

    //enable shader and pass uniforms
    shader->enable();
    shader->setUniform("u_color", Vector4(1, 1, 1, 1));
    shader->setUniform("u_viewprojection", camera->viewprojection_matrix);
    shader->setUniform("u_texture", texture, 0);
    shader->setUniform("u_model", model);
    shader->setUniform("u_time", time);
    
    //render the mesh using the shader
    mesh->render(GL_TRIANGLES);
    //disable the shader after finishing rendering
    shader->disable();
}




void Tank::update(double seconds_elapsed) {

	World* world;
	//float mouse_speed = 300.0f;
	//float speed = seconds_elapsed * mouse_speed; 

	float initial = 1.0f;
	float speed = seconds_elapsed * 10.0f + initial;
	float rotspeed = 120 * seconds_elapsed;
	//float characterRadius = 0.5f;
	Matrix44 playerRot;

	world = World::getInstance();
	
	playerRot.setRotation(yaw * DEG2RAD, Vector3(0, 1, 0));

	Vector3 playerFront = playerRot.rotateVector(Vector3(0.0f, 0.0f, -1.0f));
	Vector3 playerRight = playerRot.rotateVector(Vector3(1.0f, 0.0f, 0.0f));
	
	Vector3 tankSpeed;
	if (Input::isKeyPressed(SDL_SCANCODE_W)) tankSpeed = tankSpeed + (playerFront * -speed);
	if (Input::isKeyPressed(SDL_SCANCODE_S)) tankSpeed = tankSpeed + (playerFront * speed);
	if (Input::isKeyPressed(SDL_SCANCODE_D)) yaw += rotspeed;
	if (Input::isKeyPressed(SDL_SCANCODE_A)) yaw -= rotspeed;

	targetpos = pos + tankSpeed;

	Vector3 characterTargetCenter = targetpos + Vector3(0.0f, 1.0f, 0.0f);
	bcoll = false;
	for (int i = 0; i < world->static_entities.size(); i++) 
	{
		
		EntityMesh* current = static_cast<EntityMesh*>(world->static_entities[i]);
		Vector3 coll;
		Vector3 collnorm;
		if (!current->mesh->testSphereCollision(current->model, characterTargetCenter, 5.f, coll, collnorm)) {
			
			continue;
		}
		bcoll = true;
		Vector3 push_away = normalize(coll - characterTargetCenter) * seconds_elapsed;
		targetpos = pos - push_away;
		targetpos.y = pos.y;
		

	}
	pos = targetpos;
	Matrix44 newmodel;
	newmodel.translate(targetpos.x,1.0f,targetpos.z);
	newmodel.rotate(yaw* DEG2RAD, Vector3(0.0f, 1.0f, 0.0f));
	this->model = newmodel;
	

}

Vector3 Tank::getPosition()
{
	return pos;
}

bool Tank::getColl()
{
	return bcoll;
}

