#ifndef	GUI
#define GUI

#include "texture.h";

class Gui {
public:
	//Gui();
	void renderButton(int x, int y, int w, int h, Texture* tex, Vector4 range);
	bool renderMouseButton(int x, int y, int w, int h, Texture* tex, Vector4 range);
	void renderMinimap();
	//void update(double seconds_elapsed);
	//Vector3 getPosition();
	//float yaw = 0.0f;

private:
	//Vector3 pos, targetpos;

};
#endif