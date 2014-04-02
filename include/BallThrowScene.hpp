#ifndef BALLTHROWSCENE_H
#define BALLTHROWSCENE_H

#include <Scene.hpp>

class BallThrowScene : public Scene
{
public:
	BallThrowScene();
	~BallThrowScene();

	void init();
	void deinit();
	void update(float deltaTime);

private:
	Ball* ball;
};

#endif