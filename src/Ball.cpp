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

bool Ball::collidesTo(Ball* other, sf::Vector2f* collisionOutput)
{
	sf::Vector2f distance = other->getPosition() - getPosition();
	float distanceLenght = sqrt(pow(distance.x, 2) + pow(distance.y, 2));

	float combinedRadius = getRadius() + other->getRadius();

	if(distanceLenght >= combinedRadius)
		return false;


	float collisionLength = combinedRadius - distanceLenght;

	distance /= distanceLenght;

	*collisionOutput = distance * collisionLength;

	return true;
}


// Private

void Ball::defaults()
{
	setFillColor(sf::Color::Blue);
	setPointCount(2*PI*getRadius());

	// Magic
	sf::Vector2f origin(getRadius(), getRadius());

	// Also works if original vector is (0.5, 0.5) but is same as above
	//origin.x *= getRadius() * 2;
	//origin.y *= getRadius() * 2;

	setOrigin(origin);
}