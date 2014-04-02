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
	float FRICTION; // Multiplier applied to collisions so ball will stop
};

#endif