#include "stage.h"
#include "utils.h"
#include "game.h"
#include "gui.h"
#include "input.h"
#include "audio.h"



enum eControls 
{
	CONTROLS,
	GAME,
	W,A,S,D,
	MOUSE,
	ARROW,
	START
};

Vector4 controlsRange[]
{
	{Vector4(0.6,0.68, 0.7, 0.33)},//CONTROLS
	{Vector4(0.6, 0.34, 0.7, 0.33)},//GAME
	{Vector4(0, 0.35,  0.17, 0.33)}, //W
	{Vector4(0, 0, 0.17, 0.35)},//A
	{Vector4(0.17, 0, 0.17, 0.35)},//S
	{Vector4(0.17, 0.35, 0.17, 0.33)},//D
	{Vector4(0.35, 0, 0.17, 0.4)},//MOUSE
	{Vector4(0.4, 0.45, 0.2, 0.3)},//ARROW
	{Vector4(0,0.7, 0.4, 0.4)},//START


};


enum eHealth
{
	H_10,
	H_9,
	H_8,
	H_7,
	H_6,
	H_5,
	H_4,
	H_3,
	H_2,
	H_1,
};

Vector4 healthRange[]
{
	{Vector4(0.02,0.92, 0.95, 0.05)},  //10
	{Vector4(0.02,0.83, 0.95, 0.05)},  //9
	{Vector4(0.02,0.73, 0.95, 0.05)},  //8
	{Vector4(0.025,0.64, 0.95, 0.04)}, //7
	{Vector4(0.025,0.53, 0.95, 0.05)}, //6
	{Vector4(0.025,0.43, 0.95, 0.05)}, //5
	{Vector4(0.022,0.33, 0.95, 0.05)}, //4
	{Vector4(0.022,0.23, 0.95, 0.05)}, //3
	{Vector4(0.022,0.12, 0.95, 0.05)}, //2
	{Vector4(0.03,0.03, 0.95, 0.04)},  //1

};

void TitleStage::render()
{
	gui->renderMouseButton(175, 300, 400, 150, title, Vector4(0.1, 0.7, 0.7, 0.2));
	gui->renderButton(600, 300, 500, 500, title, Vector4(0, 0, 1, 0.7));
}
void TitleStage::update(double seconds_elapsed)
{
}

void IntroStage::once() {
	if (BASS_Init(-1, 44100, 0, 0, NULL) == false) //-1 significa usar el por defecto del sistema operativo	
	{
		std::cout << "Error abriendo la tarjeta de sonido" << std::endl;
	}
}

void IntroStage::render()
{
	if (gui->renderMouseButton(500, 200, 550, 150, controls, controlsRange[CONTROLS])) Game::instance->ChangeStage(Game::instance->TUTORIAL); /* FER CHANGE STAGE A TUTORIAL */;
	if (gui->renderMouseButton(500, 400, 550, 150, controls, controlsRange[GAME])) {

		Audio::Stop(dSample);
		Game::instance->ChangeStage(Game::instance->PLAY);
	}

	//Game::ChangeStage(TUTORIAL);
	Input::wasMouseButtonDown = false;
}

void IntroStage::update(double seconds_elapsed)
{
	if (!llamada)
	{
		once();
		llamada = true;
	}

	if (!vegada) {
		dSample = Audio::Play("data/introSound.wav");
		vegada = true;
	}
}


void TutorialStage::render()
{

	if (gui->renderMouseButton(100, 75, 75, 75, controls, controlsRange[ARROW])) Game::instance->ChangeStage(Game::instance->INTRO); /*FER CHANGE STAGE A INTRO*/;
	gui->renderButton(200, 200, 100, 100, controls, controlsRange[W]);
	gui->renderButton(100, 300, 100, 100, controls, controlsRange[A]);
	gui->renderButton(200, 300, 100, 100, controls, controlsRange[S]);
	gui->renderButton(300, 300, 100, 100, controls, controlsRange[D]);
	gui->renderButton(200, 450, 150, 200, controls, controlsRange[MOUSE]);
	gui->renderButton(600, 250, 450, 150, tutorial_title, Vector4(0.1, 0.6, 0.8, 0.3));
	gui->renderButton(500, 450, 450, 150, tutorial_title, Vector4(0.1, 0.1, 0.7, 0.3)); ///shoot
	Input::wasMouseButtonDown = false;



}

void TutorialStage::update(double seconds_elapsed)
{

	
}


void PlayStage::update(double seconds_elapsed) 
{
	world->update(seconds_elapsed);
	if(world->tank->isDead()) Game::instance->ChangeStage(Game::instance->END);

	if (world->industry2->isDead()) {
		world->win = true;
		Game::instance->ChangeStage(Game::instance->END);

	}

	initial_time += seconds_elapsed;

	if (world->tank->getColl()) {
		std::cout << "Colisiona" << std::endl;
	
		if ( initial_time > 1.0) {
			ddSample = Audio::Play("data/Car_Crash.wav");
			Audio::Stop(ddSample);
			initial_time = 0.0;
		}

	}
}


void PlayStage::render()
{
	world->renderEverything();
	Camera* camera = new Camera();
	camera = Camera::current;

	 
	//Barra de vida
	for (int i = 0; i < world->bunkers.size(); ++i) {
		Vector3 projected_pos = camera->project(world->bunkers[i]->model * Vector3(), Game::instance->window_width, Game::instance->window_height);
		Vector3 tank_position = world->tank->getPosition();
		if (!world->bunkers[i]->isDead()) {
			if ( projected_pos.x < tank_position.x + 20.0f) {
				if (projected_pos.z < 1.0f) {
					if (world->bunkers[i]->life == 100) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_10]);
					else if (90 < world->bunkers[i]->life < 100) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_9]);
					else if (80 < world->bunkers[i]->life < 89) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_8]);
					else if (70 < world->bunkers[i]->life < 79) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_7]);
					else if (60 < world->bunkers[i]->life < 69) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_6]);
					else if (50 < world->bunkers[i]->life < 59) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_5]);
					else if (40 < world->bunkers[i]->life < 49) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_4]);
					else if (30 < world->bunkers[i]->life < 39) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_3]);
					else if (20 < world->bunkers[i]->life < 29) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_2]);
					else if (10 < world->bunkers[i]->life < 19) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_bunker, healthRange[H_1]);
					//{
					//	DWORD dSample = Audio::Play("data/introSound.wav");
					//	Audio::Stop(dSample); 
					//}
				}
			}
		}
	}
	for (int i = 0; i < world->industry.size(); ++i) {
		Vector3 projected_pos = camera->project(world->industry[i]->model * Vector3(), Game::instance->window_width, Game::instance->window_height);
		Vector3 tank_position = world->tank->getPosition();
		if (!world->industry[i]->isDead()) {
			if (projected_pos.x < tank_position.x + 20.0f) {
				if (projected_pos.z < 1.0f) {
					if (world->industry[i]->life == 100) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_10]);
					else if (900 < world->industry[i]->life < 1000) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_9]);
					else if (800 < world->industry[i]->life < 890) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_8]);
					else if (700 < world->industry[i]->life < 790) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_7]);
					else if (600 < world->industry[i]->life < 690) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_6]);
					else if (500 < world->industry[i]->life < 590) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_5]);
					else if (400 < world->industry[i]->life < 490) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_4]);
					else if (300 < world->industry[i]->life < 390) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_3]);
					else if (200 < world->industry[i]->life < 290) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_2]);
					else if (10 < world->industry[i]->life < 19) gui->renderButton(projected_pos.x, Game::instance->window_height - projected_pos.y, 100, 25, health_industry, healthRange[H_1]);
					//else if (world->industry[i]->life < 5)
					//{
					//	DWORD dSample = Audio::Play("data/introSound.wav");
					//	Audio::Stop(dSample);
					//}
				}
			}
		}
	}

};


void EndStage::render()
{
	/*
	if (BASS_Init(-1, 44100, 0, 0, NULL) == false) //-1 significa usar el por defecto del sistema operativo
	{
	std::cout << "Error abriendo la tarjeta de sonido" << std::endl;
	}
	*/
	if (!vegada) {
		if (world->win) {
			//MUSICA ALEGRE
		}
		else {
			dSample = Audio::Play("data/finalSound.wav");
			Audio::Stop(dSample);
			vegada = true;
		}
	}

	
	if (gui->renderMouseButton(400, 300, 400, 200, controls, controlsRange[START]))
	{
		world->resetEverything();
		Game::instance->ChangeStage(Game::instance->INTRO);  /* FER CHANGE STAGE A INTRO */;
	}
	

}

void EndStage::update(double seconds_elapsed)
{

}
