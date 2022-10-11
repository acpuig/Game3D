#include "entitymesh.h"

bool EntityMesh::isDead()
{
	if (life <= 0) {
		return true;
	}
	return false;
}
