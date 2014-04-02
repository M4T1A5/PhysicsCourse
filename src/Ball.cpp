#include <Ball.hpp>
#include <iostream>
#include <cmath>

Ball::Ball(float mass)
	: CircleShape(0),
	  mass(mass)
{
	defaults();
}

Ball::Ball(sf::Vector2f position, float radius, float mass)
	: CircleShape(radius),
	  mass(mass)
{
	defaults();
	setPosition(position);
}

Ball::~Ball()
{ }

// Public

void Ball::update(float dt)
{
	move(velocity * dt);

	// Move the text to the center of the ball
	ballMassText.setPosition(getPosition());
}

void Ball::draw(sf::RenderWindow* window)
{
	window->draw(*this);

	// Draw the mass of the ball on the ball
	if(drawMass)
		window->draw(ballMassText);
}

bool Ball::collidesTo(Ball* other)
{
	// Vector between the 2 balls
	sf::Vector2f distance = other->getPosition() - getPosition();
	// sfml vectors don't seeem to have many features
	float distanceLenghtSquared = pow(distance.x, 2) + pow(distance.y, 2);
	float combinedRadius = getRadius() + other->getRadius();

	// Dont do pointless squre root
	if(distanceLenghtSquared < pow(combinedRadius, 2))
		return true;

	return false;
}

bool Ball::collidesTo(Ball* other, sf::Vector2f* collisionNormal, float* collisionLength)
{
	sf::Vector2f distance = other->getPosition() - getPosition();
	float combinedRadius = getRadius() + other->getRadius();
	float distanceLenghtSquared = pow(distance.x, 2) + pow(distance.y, 2);

	if(distanceLenghtSquared >= pow(combinedRadius, 2))
		return false;


	float distanceLenght = sqrt(distanceLenghtSquared);
	*collisionLength = combinedRadius - distanceLenght;

	distance /= distanceLenght;
	*collisionNormal = distance;

	return true;
}


// Private

void Ball::defaults()
{
	drawMass = false;

	setFillColor(sf::Color::Blue);

	// Calculate center of the ball
	sf::Vector2f newOrigin(getRadius(), getRadius());
	// Change the origin to the center of the ball
	setOrigin(newOrigin);


	// Put the mass of the ball in a text
	font.loadFromFile("arial.ttf");
	ballMassText.setFont(font);
	ballMassText.setCharacterSize(20);
	ballMassText.setColor(sf::Color::Black);

	std::string text;
	text.resize(3);
	sprintf(&*text.begin(), "%.2f", mass);
	
	ballMassText.setString(text);
	newOrigin.x = ballMassText.getGlobalBounds().width/2;
	newOrigin.y = ballMassText.getGlobalBounds().height/2;
	ballMassText.setOrigin(newOrigin);
}