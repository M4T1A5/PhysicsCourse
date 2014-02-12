#include <Ball.hpp>

Ball::Ball()
	: CircleShape(0)
{
	defaults();
}

Ball::Ball(float radius)
	: CircleShape(radius)
{
	defaults();
}

Ball::~Ball()
{

}

// Public

void Ball::update(float dt)
{
	move(velocity * dt);
}

sf::FloatRect Ball::getSize()
{
	return getGlobalBounds();
}


// Private

void Ball::defaults()
{
	setFillColor(sf::Color::Black);
	//setPointCount(getRadius() * 2 * PI);
}