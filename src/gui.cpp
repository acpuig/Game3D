#include "gui.h";
#include "game.h"
#include "input.h"
#include "texture.h"



void Gui::renderButton(int x, int y ,int w , int h, Texture* tex, Vector4 range)
{
	Camera camera2D;
	camera2D.setOrthographic(0, Game::instance->window_width, Game::instance->window_height,0, -1, 1);
	camera2D.enable();

	Mesh quad;
	quad.createQuad(x, y, w, h, false);  

	Shader* shader = Shader::Get("data/shaders/basic.vs", "data/shaders/gui.fs");
	shader->enable();
	shader->setUniform("u_color", Vector4(1, 1, 1, 1));
	shader->setUniform("u_tex_range", range);
	shader->setUniform("u_viewprojection", camera2D.viewprojection_matrix);
	shader->setUniform("u_texture", tex, 0);
	Matrix44 quadModel;
	//quadModel.setTranslation(sin(Game::instance->time) * 50, 0, 0);
	shader->setUniform("u_model", quadModel);
	shader->setUniform("u_texture_tiling", 1.0f);
	quad.render(GL_TRIANGLES);
	shader->disable();

}


bool Gui::renderMouseButton(int x, int y, int w, int h, Texture* tex, Vector4 range)
{
	Camera camera2D;
	camera2D.setOrthographic(0, Game::instance->window_width,  Game::instance->window_height,0, -1, 1);
	camera2D.enable();

	Mesh quad;
	quad.createQuad(x, y, w, h, false);

	Vector2 mouse = Input::mouse_position;
	float halfWight = w * 0.5;
	float halfHeight = h * 0.5;
	float min_x = x - halfWight;
	float min_y = y - halfHeight;
	float max_x = x + halfWight;
	float max_y = y + halfHeight;

	bool hover = mouse.x > min_x && mouse.y > min_y && mouse.x < max_x && mouse.y < max_y;
	bool pressed = Input::wasMouseButtonDown;

	Vector4 normalColor = Vector4(1, 1, 1, 0.6);
	Vector4 hoverColor = Vector4(1, 1, 1,1);

	Shader* shader = Shader::Get("data/shaders/basic.vs", "data/shaders/gui.fs");
	shader->enable();
	shader->setUniform("u_color", hover ? hoverColor : normalColor);
	shader->setUniform("u_tex_range", range);
	shader->setUniform("u_viewprojection", camera2D.viewprojection_matrix);
	shader->setUniform("u_texture", tex, 0);
	Matrix44 quadModel;
	shader->setUniform("u_model", quadModel);
	shader->setUniform("u_texture_tiling", 1.0f);
	quad.render(GL_TRIANGLES);
	shader->disable();

	return hover && pressed;
}


void Gui::renderMinimap()
{
	glViewport(Game::instance->window_width - 300, Game::instance->window_height - 300, 200, 200);
	
	Camera minimapCam;
	minimapCam.setPerspective(60, 1, 0, 1000);
	
	World* world = World::getInstance();
	Matrix44 model = world->tank->model;

	Vector3 pos = model.getTranslation();
	Vector3 forward = model.rotateVector(Vector3(0,0,-1));
	minimapCam.lookAt(pos + Vector3(0, 100, 0), pos, forward);
	minimapCam.enable();

	Mesh floor;
	floor.createPlane(100);
	world->RenderMeshLow(&floor, Matrix44(), &minimapCam, Texture::Get("data/control.png"), 3 ,1.0f);
	//(Mesh* mesh, Matrix44 model, Camera* cam, Texture*	texture = NULL, int primitive =3, float tiling = 1.0f)

	glViewport(0,0, Game::instance->window_width, Game::instance->window_height);

}

