#include "world.h"


World* World::instance = NULL;
Camera* camera = Camera::current;

World::World()
{
	createWall();

	dynamic_entities.push_back(tank);

	static_entities.push_back(bunker);
	static_entities.push_back(bunker1);
	static_entities.push_back(bunker2);
	static_entities.push_back(bunker3);
	static_entities.push_back(bunker4);
	static_entities.push_back(bunker5);
	static_entities.push_back(bunker6);
	static_entities.push_back(bunker7);
	static_entities.push_back(bunker8);
	static_entities.push_back(bunker9);
	static_entities.push_back(bunker10);
	static_entities.push_back(bunker11);
	static_entities.push_back(bunker12);
	static_entities.push_back(bunker13);
	static_entities.push_back(bunker14);
	static_entities.push_back(bunker15);

	static_entities.push_back(building);
	static_entities.push_back(building1);
	static_entities.push_back(building2);
	static_entities.push_back(building3);
	static_entities.push_back(building4);
	static_entities.push_back(building5);
	static_entities.push_back(building6);
	static_entities.push_back(building7);
	static_entities.push_back(building8);
	static_entities.push_back(building9);
	static_entities.push_back(building10);
	static_entities.push_back(building11);
	static_entities.push_back(building12);
	static_entities.push_back(building13);
	static_entities.push_back(building14);
	static_entities.push_back(building15);
	static_entities.push_back(building16);
	static_entities.push_back(building17);
	static_entities.push_back(building18);
	static_entities.push_back(building19);
	static_entities.push_back(building20);
	static_entities.push_back(building21);
	static_entities.push_back(building22);
	static_entities.push_back(building23);
	static_entities.push_back(building24);
	static_entities.push_back(building25);
	static_entities.push_back(building26);
	static_entities.push_back(building27);
	static_entities.push_back(building28);
	static_entities.push_back(building29);
	static_entities.push_back(building30);
	static_entities.push_back(building31);
	static_entities.push_back(building32);
	static_entities.push_back(building33);
	static_entities.push_back(building34);
	static_entities.push_back(building35);
	static_entities.push_back(building36);
	static_entities.push_back(building37);
	static_entities.push_back(building38);
	static_entities.push_back(building39);
	static_entities.push_back(building40);
	static_entities.push_back(building41);
	static_entities.push_back(building42);
	static_entities.push_back(building43);
	static_entities.push_back(building44);
	static_entities.push_back(building45);
	static_entities.push_back(building46);
	static_entities.push_back(building47);
	static_entities.push_back(building48);
	static_entities.push_back(building49);
	static_entities.push_back(building50);
	static_entities.push_back(building51);
	static_entities.push_back(building52);
	static_entities.push_back(building53);
	static_entities.push_back(building54);
	static_entities.push_back(building55);
	static_entities.push_back(building56);
	static_entities.push_back(building57);
	static_entities.push_back(building58);
	static_entities.push_back(building59);
	static_entities.push_back(building60);
	static_entities.push_back(building61);
	static_entities.push_back(building62);
	static_entities.push_back(building63);
	static_entities.push_back(building64);
	static_entities.push_back(building65);
	static_entities.push_back(building66);
	static_entities.push_back(building67);
	static_entities.push_back(building68);
	static_entities.push_back(building69);
	static_entities.push_back(building70);
	static_entities.push_back(building71);
	static_entities.push_back(building72);
	static_entities.push_back(building73);
	static_entities.push_back(building74);
	static_entities.push_back(building75);
	static_entities.push_back(building76);
	static_entities.push_back(building77);
	static_entities.push_back(building78);
	static_entities.push_back(building79);
	static_entities.push_back(building80);
	static_entities.push_back(building81);
	static_entities.push_back(building82);
	static_entities.push_back(building83);
	static_entities.push_back(building84);
	static_entities.push_back(building85);
	static_entities.push_back(building86);
	static_entities.push_back(building87);
	static_entities.push_back(building88);
	static_entities.push_back(building89);
	static_entities.push_back(building90);
	static_entities.push_back(building91);
	static_entities.push_back(building92);
	static_entities.push_back(building93);
	static_entities.push_back(building94);
	static_entities.push_back(building95);

	static_entities.push_back(industry1);
	static_entities.push_back(industry2);
	static_entities.push_back(industry3);

	static_entities.push_back(enemy1);
	static_entities.push_back(enemy2);
	static_entities.push_back(enemy3);
	static_entities.push_back(enemy4);
	static_entities.push_back(enemy5);
	static_entities.push_back(enemy6);
	static_entities.push_back(enemy7);
	static_entities.push_back(enemy8);
	static_entities.push_back(enemy9);
	static_entities.push_back(enemy10);
	static_entities.push_back(enemy11);
	static_entities.push_back(enemy12);
	static_entities.push_back(enemy13);
	static_entities.push_back(enemy14);
	static_entities.push_back(enemy15);

	static_entities.push_back(enemy16);
	static_entities.push_back(enemy17);
	static_entities.push_back(enemy18);
	static_entities.push_back(enemy19);
	static_entities.push_back(enemy20);
	static_entities.push_back(enemy21);
	static_entities.push_back(enemy22);
	static_entities.push_back(enemy23);
	static_entities.push_back(enemy24);
	static_entities.push_back(enemy25);
	static_entities.push_back(enemy26);
	static_entities.push_back(enemy27);
	static_entities.push_back(enemy28);
	static_entities.push_back(enemy29);
	static_entities.push_back(enemy30);

	bunkers.push_back(bunker);
	bunkers.push_back(bunker1);
	bunkers.push_back(bunker2);
	bunkers.push_back(bunker3);
	bunkers.push_back(bunker4);
	bunkers.push_back(bunker5);
	bunkers.push_back(bunker6);
	bunkers.push_back(bunker7);
	bunkers.push_back(bunker8);
	bunkers.push_back(bunker9);
	bunkers.push_back(bunker10);
	bunkers.push_back(bunker11);
	bunkers.push_back(bunker12);
	bunkers.push_back(bunker13);
	bunkers.push_back(bunker14);
	bunkers.push_back(bunker15);

	industry.push_back(industry1);
	industry.push_back(industry2);
	industry.push_back(industry3);

	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);
	enemies.push_back(enemy5);
	enemies.push_back(enemy6);
	enemies.push_back(enemy7);
	enemies.push_back(enemy8);
	enemies.push_back(enemy9);
	enemies.push_back(enemy10);
	enemies.push_back(enemy11);
	enemies.push_back(enemy12);
	enemies.push_back(enemy13);
	enemies.push_back(enemy14);
	enemies.push_back(enemy15);

	enemies.push_back(enemy16);
	enemies.push_back(enemy17);
	enemies.push_back(enemy18);
	enemies.push_back(enemy19);
	enemies.push_back(enemy20);
	enemies.push_back(enemy21);
	enemies.push_back(enemy22);
	enemies.push_back(enemy23);
	enemies.push_back(enemy24);
	enemies.push_back(enemy25);
	enemies.push_back(enemy26);
	enemies.push_back(enemy27);
	enemies.push_back(enemy28);
	enemies.push_back(enemy29);
	enemies.push_back(enemy30);


	for (int i = 0; i < walls.size(); ++i) {
		static_entities.push_back(walls[i]);
	}
	//static_entities.push_back(floor);
}

void World::renderEverything() 
{
	for (int i = 0; i < static_entities.size(); ++i) {
		if (static_cast<EntityMesh*>(static_entities[i])->isDead())
		{
			delete(static_entities[i]);
			static_entities.erase(static_entities.begin() + i);
		}
		static_entities[i]->render();
	}

	for (int i = 0; i < dynamic_entities.size(); ++i) {
		dynamic_entities[i]->render();
	}

	for (int i = 0; i < bullets.size(); ++i) {
		bullets[i]->render();
	}
	floor->render();
	asphalt->render();
	skybox->render();

}

void World::update(double seconds_elapsed) {

	tank->update(seconds_elapsed);
	if (enemies.size() != 0) {
		for (int i = 0; i < enemies.size(); ++i) {
			if (enemies[i]->isDead())
			{
				enemies.erase(enemies.begin() + i);
				continue;
			}
			Vector3 enemies_position = enemies[i]->getPosition();
			Vector3 tank_position = tank->getPosition();
			if (enemies_position.x < tank_position.x + 100 && enemies_position.z < tank_position.z + 100) enemies[i]->update(seconds_elapsed);
		}
	}
	if (bunkers.size() != 0) {
		for (int i = 0; i < bunkers.size(); ++i) {

			if (bunkers[i]->isDead())
			{
				bunkers.erase(bunkers.begin() + i);
				continue;
			}
			Vector3 bunker_position = bunkers[i]->getPosition();
			Vector3 tank_position = tank->getPosition();
			if (bunker_position.x < tank_position.x + 100 && bunker_position.z < tank_position.z + 100) bunkers[i]->update(seconds_elapsed);

		}
	}
	
	
	for (int i = 0; i < bullets.size(); ++i) {
		bullets[i]->update(seconds_elapsed);
		if (bullets[i]->colisionasteWEY)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}


void World::createBullet(int type,Vector3 pos)
{
	Bullet* bullet = new Bullet(pos.x, pos.z, type);

	bullet->mesh = Mesh::Get("data/bullet.obj");
	bullet->texture = Texture::Get("data/color-atlas-new.png");
	bullet->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	bullets.push_back(bullet);
}


void World::createWall() {
	int quantity = 797;
	for (int i = 0; i < quantity; i += 3) {
		Wall* wall = new Wall(i - 395, 395, 180);
		walls.push_back(wall);
	}
	for (int i = 0; i < quantity; i += 3) {
		Wall* wall = new Wall( -395,i - 395,270);
		walls.push_back(wall);
	}
	for (int i = 0; i < quantity; i += 3) {
		Wall* wall = new Wall(395, i - 395,90);
		walls.push_back(wall);
	}
	for (int i = 0; i < quantity; i += 3) {
		Wall* wall = new Wall(i-395,  -395,0);
		walls.push_back(wall);
	}
}


void World::RenderMeshLow(Mesh* mesh, Matrix44 model, Camera* cam, Texture*	texture, int primitive , float tiling )
{

	BoundingBox box = transformBoundingBox(model, mesh->box);
	if (!cam->testBoxInFrustum(box.center, box.halfsize)) return;
	Shader* shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	 if (shader) {
		 shader->enable();

		 shader->setUniform("u_color", Vector4(1,1,1,1));
		 shader->setUniform("u_viewprojection", cam->viewprojection_matrix);
		if(texture != NULL) shader->setUniform("u_texture", texture, 0);
		shader->setUniform("u_model", model);
		shader->setUniform("u_time", time);
		shader->setUniform("u_texture_tiling", tiling);

		//render the mesh using the shader
		mesh->render(primitive);
		shader->disable();
		}
	
}

void World::resetEverything()
{
	tank->life = 200;
	tank->pos.set(300.0f, 1.0f, -330.0f);
	for (int i = 0; i < static_entities.size(); i++) {
		static_cast<EntityMesh*>(static_entities[i])->life = 100;
	}

	for (int i = 0; i < bunkers.size(); i++) {
		static_cast<EntityMesh*>(bunkers[i])->life = 200;
	}
	bullets.clear();
}
