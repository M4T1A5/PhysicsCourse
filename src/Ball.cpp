#include <Ball.hpp>
#include <iostream>

Ball::Ball()
	: CircleShape(0)
{
	defaults();
}

Ball::Ball(sf::Vector2f position, float radius)
	: CircleShape(radius)
{
	defaults();
	setPosition(position);
}

Ball::~Ball()
{

}

// Public

void Ball::update(float dt)
{
	//std::cout << getPosition().x << " " <<  getPosition().y << std::endl;
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
}