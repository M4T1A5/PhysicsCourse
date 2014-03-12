#ifndef BALL_H
#define BALL_H

const double PI = 3.14159265359;

#include <SFML\Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball();
	Ball(sf::Vector2f position, float radius);
	~Ball();

	void update(float deltaTime);

	sf::FloatRect getSize();

	bool collidesTo(Ball* other);
	bool collidesTo(Ball* other, sf::Vector2f* collisionOutput);

	sf::Vector2f velocity;

private:
	void defaults();
};

#endif