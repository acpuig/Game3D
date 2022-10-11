#ifndef FLOOR
#define FLOOR

#include "entitymesh.h"

class Floor : public EntityMesh {
public:
	Floor() {};
	void render();
	void update(double seconds_elapsed) {};

};

#endif