#ifndef SKYBOX
#define SKYBOX

#include "entitymesh.h"

class SkyBox : public EntityMesh {
public:
	SkyBox() {};
	void render();
	void update(double seconds_elapsed) {};
};

#endif