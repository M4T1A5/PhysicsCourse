#include <BallDropScene.hpp>

BallDropScene::BallDropScene()
	: ball(nullptr)
{
	init();
}

BallDropScene::~BallDropScene()
{
	deinit();
}

void BallDropScene::init()
{
	font.loadFromFile("arial.ttf");
	sceneName.setString("Pallon putoaminen");

	GRAVITY = 500.f;


	ball = new Ball(sf::Vector2f(windowSize.x/2, 100), 50);
	balls.push_back(ball);
}

void BallDropScene::deinit()
{
	if (ball != nullptr)
		delete ball;
	balls.clear();
}

void BallDropScene::update(float dt)
{
	ball->update(dt);
	ball->velocity.y += GRAVITY * dt;

	if (ball->getPosition().y + ball->getRadius() > windowSize.y)
	{
		ball->setPosition(ball->getPosition().x, windowSize.y - ball->getRadius());
		ball->velocity.y = 0;
	}
}