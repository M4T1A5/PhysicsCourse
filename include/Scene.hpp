#ifndef SCENE_H
#define SCENE_H

#include <Ball.hpp>

class Scene
{
public:
	virtual ~Scene(){};

	virtual void init() = 0;
	virtual void deinit() = 0;
	virtual void update(float deltaTime) = 0;
	void draw(sf::RenderWindow* window);

	static sf::Vector2u windowSize;

protected:
	std::vector<Ball*> balls;
};

#endif