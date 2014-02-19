#include <BallBounceScene.hpp>

BallBounceScene::BallBounceScene()
	: ball(nullptr)
{
	init();
}

BallBounceScene::~BallBounceScene()
{
	deinit();
}


// Public

void BallBounceScene::init()
{
	font.loadFromFile("arial.ttf");
	sceneName.setString("Pallon pomputtelu");
	GRAVITY = 400.f;
	FRICTION = 0.9f;

	ball = new Ball(sf::Vector2f(0, windowSize.y/2), 50);
	balls.push_back(ball);

	ball->velocity = sf::Vector2f(600, 0);
}

void BallBounceScene::deinit()
{
	if (ball != nullptr)
		delete ball;
	balls.clear();
}

void BallBounceScene::update(float dt)
{
	ball->update(dt);

	if(ball->getPosition().x < 0)
	{
		ball->setPosition(0, ball->getPosition().y);
		ball->velocity.x *= -FRICTION;
	}
	else if(ball->getPosition().x > windowSize.x - ball->getSize().width)
	{
		ball->setPosition(windowSize.x - ball->getSize().width, ball->getPosition().y);
		ball->velocity.x *= -FRICTION;
	}

	if(ball->getPosition().y < 0)
	{
		ball->setPosition(ball->getPosition().y, 0);
		ball->velocity.y *= -FRICTION;
	}
	else if(ball->getPosition().y > windowSize.y - ball->getSize().height)
	{
		ball->setPosition(ball->getPosition().x, windowSize.y - ball->getSize().height);
		ball->velocity.y *= -FRICTION;
		ball->velocity.x *= FRICTION;
	}

	ball->velocity.y += GRAVITY * dt;
}