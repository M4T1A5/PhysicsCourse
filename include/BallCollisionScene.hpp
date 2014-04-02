#ifndef BALL_COLLISION_SCENE_H
#define BALL_COLLISION_SCENE_H
#include <Scene.hpp>
class BallCollisionScene :
	public Scene
{
public:
	BallCollisionScene();
	~BallCollisionScene();

	void init();
	void deinit();
	void update(float deltaTime);

private:
	float FRICTION;
	float BALL_AMMOUNT;
};

#endif