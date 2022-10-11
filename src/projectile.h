#ifndef PROJECTILE
#define PROJECTILE

#include "entitymesh.h"

class Projectile : public EntityMesh {
public:
	Projectile();
	//void render(Matrix44 model);
	void update();
private:
	int x, y;


};

#endif