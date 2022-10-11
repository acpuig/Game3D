#ifndef BUILDING
#define BUILDING

#include "entitymesh.h"

class Building : public EntityMesh {
public:
	Building(int x, int y, int degr);
	void render();
	void update(double seconds_elapsed) {};
private:
	int x, y;
};

#endif