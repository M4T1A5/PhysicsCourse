#include <BallCollisionScene.hpp>
#include <random>


BallCollisionScene::BallCollisionScene()
{
	init();
}


BallCollisionScene::~BallCollisionScene()
{
	deinit();
}

void BallCollisionScene::init()
{
	srand(time(NULL));

	font.loadFromFile("arial.ttf");
	sceneName.setString("Pallojen törmäily");
	BALL_AMMOUNT = 2;
	GRAVITY = 400.f;
	FRICTION = 0.9f;

	for(int i = 0; i < BALL_AMMOUNT; ++i)
	{
		Ball* ball = new Ball(sf::Vector2f(i * 50, windowSize.y * 0.5f), 50);
		balls.push_back(ball);

		float x = ((float)rand() / RAND_MAX) * 100 + 500; // Something between 500 and 600
		float y = ((float)rand() / RAND_MAX) * 100 + 400; // Something between 400 and 500

		ball->velocity = sf::Vector2f(x, -y);
	}
}

void BallCollisionScene::deinit()
{
	for(auto i = balls.begin(); i != balls.end(); ++i)
	{
		Ball* ball = (*i);

		if (ball != nullptr)
			delete ball;

	}

	balls.clear();
}

void BallCollisionScene::update(float dt)
{
	// Wall collisions
	///////////////////////////////////////////////////////

	for(auto i = balls.begin(); i != balls.end(); ++i)
	{
		Ball* ball = (*i);

		ball->update(dt);

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

	// Ball collision
	/////////////////////////////////////
	for(int i = 0; i < balls.size(); ++i)
	{
		for(int j = i + 1; j < balls.size(); ++j)
		{
			Ball* ball1 = balls.at(i);
			Ball* ball2 = balls.at(j);

			sf::Vector2f collision;

			if(ball1->collidesTo(ball2, &collision));
		}
	}
}