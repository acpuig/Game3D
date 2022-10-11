#ifndef ASPHALT
#define ASPHALT

#include "entitymesh.h"

class Asphalt : public EntityMesh {
public:
	Asphalt();
	void render();
	void update(double seconds_elapsed) {};
};

#endif