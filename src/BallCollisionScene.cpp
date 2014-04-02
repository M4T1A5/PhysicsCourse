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
	BALL_AMMOUNT = 10;
	GRAVITY = 400.f;
	FRICTION = 0.8f;

	for(int i = 0; i < BALL_AMMOUNT; ++i)
	{
		// Random properties
		float radius = (float)rand() / RAND_MAX * 25 + 25; // r between 25 and 50
		float mass = (float)rand() / RAND_MAX * 4  + 1; // mass between 1 and 5

		// Random start position
		float x = ((float)rand() / RAND_MAX) * windowSize.x;
		float y = ((float)rand() / RAND_MAX) * windowSize.y;

		Ball* ball = new Ball(sf::Vector2f(x, y), radius , mass);
		ball->drawMass = true;

		// Random color
		float r = ((float)rand() / RAND_MAX) * 255;
		float g = ((float)rand() / RAND_MAX) * 255;
		float b = ((float)rand() / RAND_MAX) * 255;
		ball->setFillColor(sf::Color(r,g,b));

		// Random velocity
		float vx = ((float)rand() / RAND_MAX) * 100 + 500; // Something between 500 and 600
		float vy = ((float)rand() / RAND_MAX) * 100 + 400; // Something between 400 and 500
		ball->velocity = sf::Vector2f(vx, -vy);

		balls.push_back(ball);

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
	// Ball to ball collision
	/////////////////////////////////////
	for(int i = 0; i < balls.size(); ++i)
	{
		for(int j = i + 1; j < balls.size(); ++j)
		{
			Ball* ball1 = balls.at(i);
			Ball* ball2 = balls.at(j);

			// Collision normal
			sf::Vector2f normal;
			float collisionLength;

			if(ball1->collidesTo(ball2, &normal, &collisionLength))
			{
				// Tangent of the collision
				sf::Vector2f tangent(-normal.y, normal.x);

				// Calculate before collision velocities along normal and tangent axes
				float v1n = normal.x * ball1->velocity.x + normal.y * ball1->velocity.y;
				float v1t = tangent.x * ball1->velocity.x + tangent.y * ball1->velocity.y;
				float v2n = normal.x * ball2->velocity.x + normal.y * ball2->velocity.y;
				float v2t = tangent.x * ball2->velocity.x + tangent.y * ball2->velocity.y;

				float m1 = ball1->mass;
				float m2 = ball2->mass;

				// Calculate after collision velocities along the normal axis
				float v1nEnd = (v1n*(m1-m2)+2*m2*v2n)/(m1+m2);
				float v2nEnd = (v2n*(m2-m1)+2*m1*v1n)/(m1+m2);

				// Get the after collision velocities as vectors
				sf::Vector2f v1nEndVector = normal * v1nEnd;
				sf::Vector2f v2nEndVector = normal * v2nEnd;
				// After and before tangent velocities are the same(apparently)
				sf::Vector2f v1tEndVector = v1t * tangent;
				sf::Vector2f v2tEndVector = v2t * tangent;

				// The final velocity vector after collision
				sf::Vector2f v1End = v1nEndVector + v1tEndVector;
				sf::Vector2f v2End = v2nEndVector + v2tEndVector;

				// Set the correct velocity
				ball1->velocity = v1End;
				ball2->velocity = v2End;

				// Calculate the vector of the penetration
				sf::Vector2f collisionDepth = normal * collisionLength;

				// Move the balls so they are not inside each other
				ball1->move(-collisionDepth);
				ball2->move(collisionDepth);
			}
		}
	}

	// Ball to wall collisions
	///////////////////////////////////////////////////////

	for(auto i = balls.begin(); i != balls.end(); ++i)
	{
		Ball* ball = (*i);

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

		ball->update(dt);
	}
}