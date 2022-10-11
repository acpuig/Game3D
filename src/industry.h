#ifndef INDUSTRY
#define INDUSTRY

#include "entitymesh.h"

class Industry : public EntityMesh {
public:
	Industry(int x, int y);
	void render();
	void update(double seconds_elapsed) {};
private:
	int x, y;


};

#endif