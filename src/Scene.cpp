#include <Scene.hpp>

sf::Vector2u Scene::windowSize = sf::Vector2u();

void Scene::draw(sf::RenderWindow* window)
{
	// Probably should do this elsewhere
	windowSize = window->getSize();

	for(int i = 0; i < balls.size(); ++i)
		window->draw(*balls.at(i));
}