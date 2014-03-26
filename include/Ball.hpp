#ifndef BALL_H
#define BALL_H

const double PI = 3.14159265359;

#include <SFML\Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(float mass = 1.0f);
	Ball(sf::Vector2f position, float radius, float mass = 1.0f);
	~Ball();

	void update(float deltaTime);

	sf::FloatRect getSize();

	bool collidesTo(Ball* other);
	bool collidesTo(Ball* other, sf::Vector2f* collisionNormal, float* collisionLength);

	sf::Vector2f velocity;
	float mass;

private:
	void defaults();
};

#endif