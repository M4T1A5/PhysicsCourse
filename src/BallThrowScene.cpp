#include <BallThrowScene.hpp>

BallThrowScene::BallThrowScene()
	: ball(nullptr)
{
	init();
}

BallThrowScene::~BallThrowScene()
{
	deinit();
}

void BallThrowScene::init()
{
	sceneName.setString("Pallon heitto");

	ball = new Ball(sf::Vector2f(0, windowSize.y - 100), 50);
	balls.push_back(ball);

	GRAVITY = 400;

	// Throw velocity
	ball->velocity = sf::Vector2f(300, -500);
}

void BallThrowScene::deinit()
{
	if (ball != nullptr)
		delete ball;
	balls.clear();
}

void BallThrowScene::update(float dt)
{
	ball->update(dt);

	ball->velocity.y += GRAVITY * dt;

	if (ball->getPosition().y + ball->getSize().height >= windowSize.y)
	{
		ball->velocity.y = 0;
		ball->setPosition(ball->getPosition().x, windowSize.y - ball->getSize().height);
	}

	if (ball->getPosition().x > windowSize.x)
	{
		deinit();
		init();
	}
}