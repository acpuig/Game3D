#include "game.h"
#include "utils.h"
#include "mesh.h"
#include "texture.h"
#include "fbo.h"
#include "shader.h"
#include "input.h"
#include "animation.h"
#include <cmath>

//some globals
Animation* anim = NULL;
float angle = 0;
float mouse_speed = 100.0f;
FBO* fbo = NULL;



World* world;
Game* Game::instance = NULL;

Game::Game(int window_width, int window_height, SDL_Window* window)
{
	this->window_width = window_width;
	this->window_height = window_height;
	this->window = window;
	instance = this;
	must_exit = false;

	fps = 0;
	frame = 0;
	time = 0.0f;
	elapsed_time = 0.0f;
	mouse_locked = false;

	//OpenGL flags
	glEnable( GL_CULL_FACE ); //render both sides of every triangle
	glEnable( GL_DEPTH_TEST ); //check the occlusions using the Z buffer

	//create our camera
	camera = new Camera();
	camera->lookAt(Vector3(0.f,100.f, 100.f),Vector3(0.f,0.f,0.f), Vector3(0.f,1.f,0.f)); //position the camera and point to 0,0,0
	camera->setPerspective(70.f,window_width/(float)window_height,0.1f,1000.f); //set the projection, we want to be perspective

	//get world instance
	world = World::getInstance();
	//stages

	TitleStage* title_stage = new TitleStage();
	IntroStage* intro_stage = new IntroStage();
	TutorialStage* tutorial_stage = new TutorialStage();
	PlayStage* play_stage = new PlayStage();
	EndStage* end_stage = new EndStage();

	stages.push_back(title_stage);
	stages.push_back(intro_stage);
	stages.push_back(tutorial_stage);
	stages.push_back(play_stage);
	stages.push_back(end_stage);

	//load meshes
	play_stage->world->tank->mesh = Mesh::Get("data/tiger.obj");
	//getCurrentStage()->world->grass->mesh = Mesh::Get("data/tile-grass.obj");
	play_stage->world->asphalt->mesh = Mesh::Get("data/tile-plain_asphalt_5.obj");
	//getCurrentStage()->world->water->mesh = Mesh::Get("data/tile-water_10.obj");
	play_stage->world->bunker->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker1->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker2->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker3->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker4->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker5->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker6->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker7->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker8->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker9->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker10->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker11->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker12->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker13->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker14->mesh = Mesh::Get("data/bunker.obj");
	play_stage->world->bunker15->mesh = Mesh::Get("data/bunker.obj");

	play_stage->world->building->mesh = Mesh::Get("data/cafe.obj");
	play_stage->world->building1->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building2->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building3->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building4->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building5->mesh = Mesh::Get("data/office_3.obj");
	play_stage->world->building6->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building7->mesh = Mesh::Get("data/restaurant_2.obj");
	play_stage->world->building8->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building9->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building10->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building11->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building12->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building13->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building14->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building15->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building16->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building17->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building18->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building19->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building20->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building21->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building22->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building23->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building24->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building25->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building26->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building27->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building28->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building29->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building30->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building31->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building32->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building33->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building34->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building35->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building36->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building37->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building38->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building39->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building40->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building41->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building42->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building43->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building44->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building45->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building46->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building47->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building48->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building49->mesh = Mesh::Get("data/traffic-lights_14.obj");
	play_stage->world->building50->mesh = Mesh::Get("data/traffic-lights_14.obj");
	play_stage->world->building51->mesh = Mesh::Get("data/traffic-lights_14.obj");
	play_stage->world->building52->mesh = Mesh::Get("data/traffic-lights_14.obj");
	play_stage->world->building53->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building54->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building55->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building56->mesh = Mesh::Get("data/restaurant_2.obj");
	play_stage->world->building57->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building58->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building59->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building60->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building61->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building62->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building63->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building64->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building65->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building66->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building67->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building68->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building69->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building70->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building71->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building72->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building73->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building74->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building75->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building76->mesh = Mesh::Get("data/restaurant_2.obj");
	play_stage->world->building77->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building78->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building79->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building80->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building81->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building82->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building83->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building84->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building85->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building86->mesh = Mesh::Get("data/restaurant.obj");
	play_stage->world->building87->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building88->mesh = Mesh::Get("data/cinema.obj");
	play_stage->world->building89->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building90->mesh = Mesh::Get("data/office_2.obj");
	play_stage->world->building91->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building92->mesh = Mesh::Get("data/hotel.obj");
	play_stage->world->building93->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building94->mesh = Mesh::Get("data/office.obj");
	play_stage->world->building95->mesh = Mesh::Get("data/hotel.obj");
	//play_stage->world->building96->mesh = Mesh::Get("data/restaurant_2.obj");
	//play_stage->world->building97->mesh = Mesh::Get("data/office_2.obj");
	//play_stage->world->building98->mesh = Mesh::Get("data/cinema.obj");
	//play_stage->world->building99->mesh = Mesh::Get("data/office.obj");
	//play_stage->world->building100->mesh = Mesh::Get("data/restaurant.obj");
	//play_stage->world->building101->mesh = Mesh::Get("data/hotel.obj");
	//play_stage->world->building102->mesh = Mesh::Get("data/office_2.obj");
	//play_stage->world->building103->mesh = Mesh::Get("data/cinema.obj");

	play_stage->world->industry1->mesh = Mesh::Get("data/industry_factory.obj");
	play_stage->world->industry2->mesh = Mesh::Get("data/industry_tower.obj");
	play_stage->world->industry3->mesh = Mesh::Get("data/industry_factory.obj");

	//enemies
	play_stage->world->enemy1->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy2->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy3->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy4->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy5->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy6->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy7->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy8->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy9->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy10->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy11->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy12->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy13->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy14->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy15->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy16->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy17->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy18->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy19->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy20->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy21->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy22->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy23->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy24->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy25->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy26->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy27->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy28->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy29->mesh = Mesh::Get("data/sherman.obj");
	play_stage->world->enemy30->mesh = Mesh::Get("data/sherman.obj");

	//wall
	for (int i = 0; i < world->walls.size(); ++i) {
		play_stage->world->walls[i]->mesh = Mesh::Get("data/wall-medieval-stone.obj");}

	//sky
	play_stage->world->skybox->mesh = Mesh::Get("data/cielo.ASE");

	//floor
	Mesh* ground = new Mesh();
	ground->createPlane(600);
	play_stage->world->floor->mesh = ground;


	//load textures
	play_stage->world->tank->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->grass->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->asphalt->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->water->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker1->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker2->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker3->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker4->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker5->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker6->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker7->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker8->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker9->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker10->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker11->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker12->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker13->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker14->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->bunker15->texture = Texture::Get("data/color-atlas-new.png");

	play_stage->world->building->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building1->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building2->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building3->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building4->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building5->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building6->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building7->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building8->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building9->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building10->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building11->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building12->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building13->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building14->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building15->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building16->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building17->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building18->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building19->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building20->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building21->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building22->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building23->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building24->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building25->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building26->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building27->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building28->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building29->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building30->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building31->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building32->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building33->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building34->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building35->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building36->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building37->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building38->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building39->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building40->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building41->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building42->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building43->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building44->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building45->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building46->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building47->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building48->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building49->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building50->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building51->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building52->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building53->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building54->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building55->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building56->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building57->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building58->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building59->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building60->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building61->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building62->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building63->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building64->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building65->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building66->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building67->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building68->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building69->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building70->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building71->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building72->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building73->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building74->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building75->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building76->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building77->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building78->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building79->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building80->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building81->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building82->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building83->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building84->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building85->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building86->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building87->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building88->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building89->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building90->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building91->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building92->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building93->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building94->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->building95->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building96->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building97->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building98->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building99->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building100->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building101->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building102->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->building103->texture = Texture::Get("data/color-atlas-new.png");
	

	//enemies
	play_stage->world->enemy1->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy2->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy3->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy4->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy5->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy6->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy7->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy8->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy9->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy10->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy11->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy12->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy13->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy14->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy15->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy16->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy17->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy18->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy19->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy20->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy21->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy22->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy23->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy24->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy25->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy26->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy27->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy28->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy29->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->enemy30->texture = Texture::Get("data/color-atlas-new.png");


	play_stage->world->skybox->texture = Texture::Get("data/cielo.tga");

	//wall
	for (int i = 0; i < world->walls.size(); ++i) {
		play_stage->world->walls[i]->texture = Texture::Get("data/color-atlas-new.png");
	}

	play_stage->world->industry1->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->industry2->texture = Texture::Get("data/color-atlas-new.png");
	play_stage->world->industry3->texture = Texture::Get("data/color-atlas-new.png");

	play_stage->world->floor->texture = Texture::Get("data/floorTexture.tga");

	//play_stage->world->trench->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->tree->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->tree1->texture = Texture::Get("data/color-atlas-new.png");
	//play_stage->world->tree2->texture = Texture::Get("data/color-atlas-new.png");



	// loading shaders per object
	play_stage->world->tank->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->asphalt->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker1->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker2->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker3->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker4->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker5->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker6->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker7->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker8->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker9->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker10->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker11->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker12->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker13->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker14->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->bunker15->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	play_stage->world->building->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building1->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building2->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building3->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building4->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building5->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building6->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building7->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building8->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building9->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building10->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building11->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building12->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building13->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building14->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building15->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building16->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building17->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building18->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building19->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building20->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building21->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building22->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building23->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building24->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building25->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building26->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building27->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building28->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building29->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building30->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building31->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building32->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building33->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building34->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building35->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building36->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building37->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building38->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building39->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building40->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building41->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building42->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building43->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building44->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building45->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building46->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building47->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building48->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building49->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building50->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building51->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building52->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building53->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building54->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building55->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building56->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building57->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building58->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building59->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building60->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building61->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building62->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building63->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building64->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building65->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building66->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building67->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building68->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building69->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building70->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building71->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building72->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building73->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building74->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building75->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building76->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building77->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building78->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building79->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building80->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building81->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building82->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building83->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building84->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building85->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building86->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building87->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building88->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building89->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building90->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building91->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building92->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building93->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building94->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->building95->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	
	//enemies
	play_stage->world->enemy1->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy2->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy3->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy4->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy5->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy6->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy7->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy8->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy9->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy10->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy11->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy12->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy13->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy14->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy15->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy16->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy17->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy18->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy19->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy20->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy21->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy22->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy23->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy24->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy25->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy26->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy27->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy28->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy29->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->enemy30->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");



	//skybox
	play_stage->world->skybox->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	//wall
	for (int i = 0; i < world->walls.size(); ++i) {
		play_stage->world->walls[i]->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");}

	play_stage->world->industry1->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->industry2->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");
	play_stage->world->industry3->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	play_stage->world->floor->shader = Shader::Get("data/shaders/basic.vs", "data/shaders/texture.fs");

	currentStage = TITLE;

	//hide the cursor
	SDL_ShowCursor(!mouse_locked); //hide or show the mouse

	
}

//what to do when the image has to be draw
void Game::render(void)
{

	//set the clear color (the background color)
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Clear the window and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set the camera as default
	camera->enable();

	//set flags
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);


	getCurrentStage()->render();


	//drawing tank stats
	if (currentStage == PLAY) {
		std::string hola = "Your life is: " + std::to_string(world->tank->life);
		drawText(4, 4, hola, Vector3(1, 1, 1), 2);
	}


	//swap between front buffer and back buffer
	SDL_GL_SwapWindow(this->window);
	
	
}

void Game::update(double seconds_elapsed)
{
	
	getCurrentStage()->update(seconds_elapsed);

	//to navigate with the mouse fixed in the middle
	if (mouse_locked)
		Input::centerMouse();
}

//Keyboard event handler (sync input)
void Game::onKeyDown( SDL_KeyboardEvent event )
{
	switch(event.keysym.sym)
	{
		
	case SDLK_SPACE:
		if (currentStage == TITLE)
		{
			ChangeStage(INTRO);
		}
		break;
		
	case SDLK_ESCAPE: must_exit = true; break; //ESC key, kill the app
	case SDLK_k: 
		if (currentStage == TUTORIAL)
		{
			
		}
		break; //ESC key, kill the app
	case SDLK_F1: Shader::ReloadAll(); break; 
		
	}

}

void Game::onKeyUp(SDL_KeyboardEvent event)
{
}

void Game::onGamepadButtonDown(SDL_JoyButtonEvent event)
{

}

void Game::onGamepadButtonUp(SDL_JoyButtonEvent event)
{

}

void Game::onMouseButtonDown( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_MIDDLE) //middle mouse
	{
		mouse_locked = !mouse_locked;
		SDL_ShowCursor(!mouse_locked);
	}
	
	if (event.button == SDL_BUTTON_LEFT)
	{
		if (currentStage == INTRO  || currentStage == TUTORIAL || currentStage == END) Input::wasMouseButtonDown = true;
		if(currentStage == PLAY) getCurrentStage()->world->createBullet(0,world->tank->getPosition());
	}
	
}

void Game::onMouseButtonUp(SDL_MouseButtonEvent event)
{
}

void Game::onMouseWheel(SDL_MouseWheelEvent event)
{
	mouse_speed *= event.y > 0 ? 1.1 : 0.9;
}

void Game::onResize(int width, int height)
{
    std::cout << "window resized: " << width << "," << height << std::endl;
	glViewport( 0,0, width, height );
	camera->aspect =  width / (float)height;
	window_width = width;
	window_height = height;
}

