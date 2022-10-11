#ifndef BUNKER
#define BUNKER

#include "entitymesh.h"

class Bunker : public EntityMesh {
public:
	Bunker(int x, int y);
	void render();
	void update(double seconds_elapsed);
	Vector3 getPosition();


private:
	Vector3 pos;
	int type = 1;
	double initial_time = 0.0;

};

#endif