#ifndef BULLET
#define BULLET

#include "entitymesh.h"

class Bullet : public EntityMesh {
public:
	Bullet(int x, int y,int type);
	void update(double seconds_elapsed);
	void render();
	bool colisionasteWEY = false;
private:
	Vector3 pos, targetpos;
	Matrix44 bullRot;
	float angle = 0.0;
	int type; 
	
};

#endif