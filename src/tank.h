#ifndef TANK
#define TANK

#include "entitymesh.h"

class Tank : public EntityMesh {
public:
	Tank();
	void render();
	void update(double seconds_elapsed);
	Vector3 getPosition();
	float yaw = 0.0f;
	Vector3 pos;
	bool getColl();

private:
	Vector3 targetpos;
	bool bcoll = false;

};

#endif