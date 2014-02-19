#ifndef BALLBOUNCESCENE_H
#define BALLBOUNCESCENE_H

#include <Scene.hpp>

class BallBounceScene : public Scene
{
public:
	BallBounceScene();
	~BallBounceScene();

	void init();
	void deinit();
	void update(float deltaTime);

private:
	Ball* ball;
	float GRAVITY;
	float FRICTION;
};

#endif