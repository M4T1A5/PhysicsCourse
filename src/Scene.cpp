#include <Scene.hpp>

void Scene::draw(sf::RenderWindow* window)
{
	for(int i = 0; i < balls.size(); ++i)
		window->draw(*balls.at(i));
}