#include <Ball.hpp>
#include <iostream>
#include <cmath>

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

bool Ball::collidesTo(Ball* other)
{
	sf::Vector2f distance = other->getPosition() - getPosition();

	float distanceLenght = sqrt(pow(distance.x, 2) + pow(distance.y, 2));

	if(distanceLenght < getRadius() + other->getRadius())
		return true;

	return false;
}

// Private

void Ball::defaults()
{
	setFillColor(sf::Color::Blue);
}