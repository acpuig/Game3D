#ifndef WALL
#define WALL

#include "entitymesh.h"

class Wall : public EntityMesh {
public:
	Wall(int x, int y, int degr);
	void render();
	void update(double seconds_elapsed) {};

private:
	int x, y;
	
};

#endif