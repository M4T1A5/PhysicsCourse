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
	GRAVITY = 500.f;
	FRICTION = 0.9f; // Seems pretty good

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

	// Check collisions againts walls
	if(ball->getPosition().x - ball->getRadius() < 0)
	{
		ball->setPosition(0 + ball->getRadius(), ball->getPosition().y);
		ball->velocity.x *= -FRICTION;
	}
	else if(ball->getPosition().x > windowSize.x - ball->getRadius())
	{
		ball->setPosition(windowSize.x - ball->getRadius(), ball->getPosition().y);
		ball->velocity.x *= -FRICTION;
	}

	if(ball->getPosition().y - ball->getRadius() < 0)
	{
		ball->setPosition(ball->getPosition().x, 0 + ball->getRadius());
		ball->velocity.y *= -FRICTION;
	}
	else if(ball->getPosition().y > windowSize.y - ball->getRadius())
	{
		ball->setPosition(ball->getPosition().x, windowSize.y - ball->getRadius());
		ball->velocity.y *= -FRICTION;
		ball->velocity.x *= FRICTION;
	}

	ball->velocity.y += GRAVITY * dt;
}