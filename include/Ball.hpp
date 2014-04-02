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

	// Update the ball
	void update(float deltaTime);
	// Draw the ball
	void draw(sf::RenderWindow* window);

	// Check collison between 2 balls
	bool collidesTo(Ball* other);
	// Also return the collison normal and the lenght of penetration
	bool collidesTo(Ball* other, sf::Vector2f* collisionNormal, float* collisionLength);

	// Velocity of the ball (in pixels/s)
	sf::Vector2f velocity;
	// Mass of the ball (in kg i guess)
	float mass;
	bool drawMass;

private:
	// Initialize some defaults
	void defaults();

	sf::Font font;
	sf::Text ballMassText;
};

#endif