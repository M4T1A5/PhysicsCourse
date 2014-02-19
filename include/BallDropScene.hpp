#ifndef BALLDROPSCENE_H
#define BALLDROPSCENE_H

#include <Scene.hpp>

class BallDropScene : public Scene
{
public:
	BallDropScene();
	~BallDropScene();

	void init();
	void deinit();
	void update(float deltaTime);

private:
	Ball* ball;
	float GRAVITY;
};

#endif