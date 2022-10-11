#ifndef ENEMY
#define ENEMY

#include "entitymesh.h"
#include "pathfinders.h"

class Enemy : public EntityMesh {
public:
	Enemy(int x, int y);
	void render();
	void update(double seconds_elapsed);
	Vector3 getPosition();

private:
	Vector3 pos;
	int type = 1;

	double initial_time = 0.0;
	

};

#endif