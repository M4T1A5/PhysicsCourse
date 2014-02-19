#include <BallBounceScene.hpp>

BallBounceScene::BallBounceScene()
	: ball(nullptr)
{
	init();
}

BallBounceScene::~BallBounceScene()
{

}


// Public

void BallBounceScene::init()
{
	sceneName.setString("Pallon pomputtelu");
	GRAVITY = 100.f;
	FRICTION = 0.8f;

	ball = new Ball(sf::Vector2f(0, windowSize.y/2), 50);
	balls.push_back(ball);

	ball->velocity = sf::Vector2f(300, 0);
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
	ball->velocity.y += GRAVITY;

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
		ball->velocity.y -= GRAVITY;
		ball->velocity.y *= -FRICTION;
		ball->velocity.x *= FRICTION;
	}

}