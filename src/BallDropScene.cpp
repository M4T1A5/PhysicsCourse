#include <BallDropScene.hpp>

BallDropScene::BallDropScene()
{
	init();
}

BallDropScene::~BallDropScene()
{
	deinit();
}

void BallDropScene::init()
{
	ball = new Ball(sf::Vector2f(windowSize.x/2-50, 100), 50);
	balls.push_back(ball);
	ball->velocity.y = 200; // Gravity
}

void BallDropScene::deinit()
{
	delete ball;
	balls.empty();
}

void BallDropScene::update(float dt)
{
	ball->update(dt);

	if (ball->getPosition().y + ball->getSize().height > windowSize.y)
	{
		ball->setPosition(ball->getPosition().x, windowSize.y - ball->getRadius() * 2);
		ball->velocity.y = 0;
	}
}