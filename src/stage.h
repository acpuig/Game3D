#ifndef STAGE
#define STAGE


#include "world.h"
#include "gui.h"


class Stage {

public:
	virtual void render() = 0;
	virtual void update(double seconds_elapsed) = 0;
	World* world = World::getInstance();
	Gui* gui;
	Texture* controls = Texture::Get("data/control.png");
	Texture* title = Texture::Get("data/title.png");
	Texture* tutorial_title = Texture::Get("data/tutorial_title.png");

	Texture* health_bunker = Texture::Get("data/health_bunker.png");
	Texture* health_industry = Texture::Get("data/health_industry.png");

	DWORD dSample{};
	DWORD ddSample{};
	bool vegada = false;


};

class TitleStage : public Stage {
public:

	virtual void render();
	virtual void update(double seconds_elapsed);

};
class IntroStage : public Stage {
public:

	virtual void render();
	virtual void update(double seconds_elapsed);
	void once();
	bool llamada = false;

};
class TutorialStage : public Stage {
public:
	virtual void render() ;
	virtual void update(double seconds_elapsed);
};
class PlayStage : public Stage {
public:
	virtual void render() ;
	virtual void update(double seconds_elapsed) ;
private:
	double initial_time = 0.0;

};

class EndStage : public Stage {
public:
	bool vegada = false;
	virtual void render() ;
	virtual void update(double seconds_elapsed) ;
};

#endif