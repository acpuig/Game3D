#ifndef WORLD
#define WORLD

#include "framework.h"
#include "tank.h"
#include "asphalt.h"
#include "bunker.h"
#include "entity.h"
#include "building.h"
#include "industry.h"
#include "tree.h"
#include "wall.h"
#include "skybox.h"
#include "floor.h"
#include "bullet.h"
#include "enemy.h"


class World {
public:
	static World* getInstance() {
		if (instance == NULL) instance = new World();
		return instance;
	}

			///Creating objects
		//Vehicles
	//Tank
	Tank* tank = new Tank();

		//Grounds
	//Asphalt
	Asphalt* asphalt = new Asphalt();

		//Bunkers
	//1rst MainAvenue Vertical Esquerra
	Bunker* bunker = new Bunker(325,-200);
	Bunker* bunker1 = new Bunker(325, 100);
	//1rst MainAvenue Vertical Dreta
	Bunker* bunker2= new Bunker(275,0);
	Bunker* bunker3 = new Bunker(275,-100);
	
	//2nd MainAvenue Vertical Esquerra
	Bunker* bunker4 = new Bunker(175, -100);
	Bunker* bunker5 = new Bunker(175, 100);
	//2nd MainAvenue Vertical Dreta
	Bunker* bunker6 = new Bunker(125, 50);
	Bunker* bunker7 = new Bunker(125, -175);

	//3ra Vertical Avnenue Dreta -x= 325
	Bunker* bunker8 = new Bunker(-325, 0);
	Bunker* bunker9 = new Bunker(-325, 200);
	//3ra MainAvenue Vertical Esquerra x= 275
	Bunker* bunker10 = new Bunker(275, -200);
	Bunker* bunker11 = new Bunker(275, 100);

	//4rt Vertical Avnenue Dreta 
	Bunker* bunker12 = new Bunker(-125, 0);
	Bunker* bunker13 = new Bunker(-125, -100);
	//4rt MainAvenue Vertical Esquerra 
	Bunker* bunker14 = new Bunker(-75, -25);
	Bunker* bunker15 = new Bunker(-75, -125);


		//Building 
	Building* building = new Building(300, -350,180);
	//1rst Vertical Avenue
		//1rst MainAvenue Vertical Esquerra
	Building* building1 = new Building(325, -250,90);
	Building* building2 = new Building(325, -150, 90);
	Building* building3 = new Building(325, -50, 90);
	Building* building4 = new Building(325, 50, 90);
	Building* building5 = new Building(325, 150, 90);
	Building* building6 = new Building(325, 250, 90);
	Building* building7 = new Building(325, 325, 90);
		//1rst MainAvenue Vertical Dreta
	Building* building8 = new Building(250, -250,0);
	Building* building9 = new Building(275, -150, 270);
	Building* building10 = new Building(275, -50, 270);
	Building* building11 = new Building(275, 75, 270);
	Building* building12 = new Building(275, 150, 270);
	Building* building13 = new Building(275, 200, 270);
	Building* building14 = new Building(275, 350, 270);
	Building* building15 = new Building(275, 250, 270);
		//Semaforos
	Building* building49 = new Building( 285,- 250,0);
	Building* building50 = new Building(285, -200,0);
	Building* building51 = new Building(285, 250,0);
	Building* building52 = new Building(320, 250,0);
	

	//2nd Vertical Avenue
		//2nd MainAvenue Vertical Esquerra
	Building* building17 = new Building(175, -250, 0);
	Building* building18 = new Building(175, -150, 90);
	Building* building19 = new Building(175, -50, 90);
	Building* building20 = new Building(175, 50, 90);
	Building* building21 = new Building(175, 150, 90);
	Building* building22 = new Building(175, 250, 90);
	Building* building23 = new Building(175, 325, 180);
	Building* building31 = new Building(175, 0, 90); 


		//2nd MainAvenue Vertical Dreta
	Building* building24 = new Building(125, -250, 0);
	Building* building25 = new Building(125, -150, 270);
	Building* building30 = new Building(125, -100, 270); 
	Building* building26 = new Building(125, -50, 270);
	Building* building27 = new Building(125, 50, 270);
	Building* building28 = new Building(125, 150, 270);
	Building* building32 = new Building(125, 200, 270);
	Building* building29 = new Building(125, 250, 270);
		//Semaforos

	//3ra Vertical Avenue
		//3ra Vertical Avnenue Dreta x= -325
	Building* building33 = new Building(-325, -250, 270);
	Building* building34 = new Building(-325, -150, 270);
	Building* building35 = new Building(-325, -50, 270);
	Building* building36 = new Building(-325, 50, 270);
	Building* building37 = new Building(-325, 150, 270);
	Building* building38 = new Building(-325, 250, 270);
	Building* building39 = new Building(-300, -325,0);
	   //3ra MainAvenue Vertical Esquerra x= 275
	Building* building40 = new Building(-275, -250, 90);
	Building* building41 = new Building(-275, -150, 90);
	Building* building42 = new Building(-275, -50, 90);
	Building* building43 = new Building(-275, -100, 90);
	Building* building44 = new Building(-275, 0, 90);
	Building* building45 = new Building(-275, 250, 90);
	Building* building46 = new Building(-200, 325, 90);
	Building* building47 = new Building(-275, 150, 90); 
	Building* building48 = new Building(-275, 200, 90); 


	//4rt Vertical Avenue
		//4rt Vertical Avnenue Dreta -x= -125
	Building* building88 = new Building(-125, -150, 270);
	Building* building89 = new Building(-125, -50, 270);
	Building* building90 = new Building(-125, 50, 270);

		//4rt MainAvenue Vertical Esquerra -x= -75
	Building* building91 = new Building(-75, -150, 90);
	Building* building92 = new Building(-75, -50, 90);
	Building* building93 = new Building(-75, -100, 90);
	Building* building94 = new Building(-75, 0, 90);
	Building* building95 = new Building(-75, 50, 90);

	//1rst Horiz Avenue
		//1rst Horiz Avenue UP
	Building* building54 = new Building(-100, -250,0); 
	Building* building55 = new Building(50, -250,0); 
	Building* building56 = new Building(-150, -250,0);
	Building* building57 = new Building(-50, -250,0); 
		//1rst Horiz Avenue DOWN
	Building* building59 = new Building(-50, -200,180);
	Building* building60 = new Building(0, -200,180);
	Building* building61= new Building(50, -200, 180);
	Building* building62 = new Building(-150, -200, 180);
	Building* building63 = new Building(-200, -200, 180);

	//2na Horiz Avenue
		//2na Horiz Avenue DOWN y= 325
	Building* building16 = new Building(200, 325, 180); 
	Building* building75 = new Building(100, 325, 180);
	Building* building76 = new Building(50, 325, 180);
	Building* building77 = new Building(0, 325, 180);
	Building* building78 = new Building(-50, 325, 180);
	Building* building79 = new Building(-100, 325, 180);
	Building* building80 = new Building(-150, 325, 180);

		//2na Horiz Avenue UP y=275
	Building* building81 = new Building(-200, 275, 0); 
	Building* building82 = new Building(50, 275, 0);
	Building* building83 = new Building(0, 275, 0);
	Building* building84 = new Building(-50, 275, 0);
	Building* building85 = new Building(-100, 275, 0);
	Building* building86 = new Building(-150, 275, 0);
	Building* building87 = new Building(-250, 275, 0); 
	
	//3ra Horiz Avenue
		//3ra Horiz Avenue UP
	Building* building53 = new Building(-50, 75,0);
	Building* building58 = new Building(-150, 75,0);
	Building* building64 = new Building(50, 75,0);
	Building* building65 = new Building(0, 75,0);
	Building* building66 = new Building(-200, 75,0);
	Building* building67 = new Building(-250, 75,0);

		//3ra Horiz Avenue DOWN
	Building* building68 = new Building(-250, 125, 180);
	Building* building69 = new Building(50, 125, 180);
	Building* building70 = new Building(0, 125, 180);
	Building* building71 = new Building(-50, 125, 180);
	Building* building72 = new Building(-100, 125, 180);
	Building* building73 = new Building(-150, 125, 180);
	Building* building74 = new Building(-200, 125, 180);


	//Industry 
	Industry* industry1 = new Industry(-325,300);
	Industry* industry2 = new Industry(-310, 350);
	Industry* industry3 = new Industry(-275, 350);

	//skybox
	SkyBox* skybox = new SkyBox();

	//floor
	Floor* floor = new Floor();

	//Enemies
	Enemy* enemy1 = new Enemy(300,100);
	Enemy* enemy2 = new Enemy(300,200);
	Enemy* enemy3 = new Enemy(300,20);
	Enemy* enemy4 = new Enemy(250,300);
	Enemy* enemy5 = new Enemy(200,300);
	Enemy* enemy6 = new Enemy(150,300);
	Enemy* enemy7 = new Enemy(110,300);
	Enemy* enemy8 = new Enemy(-275,320);
	Enemy* enemy9 = new Enemy(-275,300);
	Enemy* enemy10 = new Enemy(-280,300);
	Enemy* enemy11 = new Enemy(-10,300);
	Enemy* enemy12 = new Enemy(-200,300);
	Enemy* enemy13 = new Enemy(-275,300);
	Enemy* enemy14 = new Enemy(-300,300);
	Enemy* enemy15 = new Enemy(-290,300);

	Enemy* enemy16 = new Enemy(300,-225);
	Enemy* enemy17 = new Enemy(270,-225);
	Enemy* enemy18 = new Enemy(200,-200);
	Enemy* enemy19 = new Enemy(160,-210);
	Enemy* enemy20 = new Enemy(120,-225);
	Enemy* enemy21 = new Enemy(50,-225);
	Enemy* enemy22 = new Enemy(-30,-225);
	Enemy* enemy23 = new Enemy(-90,-225);
	Enemy* enemy24 = new Enemy(-130,-220);
	Enemy* enemy25 = new Enemy(-160,-230);
	Enemy* enemy26 = new Enemy(-200,-225);
	Enemy* enemy27 = new Enemy(-230,-220);
	Enemy* enemy28 = new Enemy(-240,-230);
	Enemy* enemy29 = new Enemy(-270,-225);
	Enemy* enemy30 = new Enemy(-290,-225);
	



		//Others
//	Building* building97 = new Building(0, 0, 0);
//	Building* building98 = new Building(0, 0, 0);
//	Building* building99= new Building(0, 0, 0);
//	Building* building100 = new Building(-0, 0, 90); 
//	Building* building101 = new Building(-0, 0, 90); 
//	Building* building102 = new Building(-0, 0, 90); 
//	Building* building103 = new Building(0, 0, 90);

	std::vector<Wall*> walls;
	std::vector<Bullet*> bullets;
	std::vector<Entity*> dynamic_entities;
	std::vector<Entity*> static_entities;
	std::vector<Enemy*> enemies;
	std::vector<Bunker*> bunkers;
	std::vector<Industry*> industry;

	void renderEverything();
	void createBullet(int type,Vector3 posº);
	void update(double seconds_elapsed);
	void RenderMeshLow(Mesh* mesh, Matrix44 model, Camera* cam, Texture* texture = NULL, int primitive = 3, float tiling = 1.0f);

	void resetEverything();

	bool win = false;

private:
	static World* instance;
	World();
	void createWall();


};
#endif
