#include <Scene.hpp>

sf::Vector2u Scene::windowSize = sf::Vector2u();

Scene::Scene()
{
	sceneName.setFont(font);
	sceneName.setColor(sf::Color::Red);
	sceneName.setCharacterSize(50);
}

void Scene::draw(sf::RenderWindow* window)
{
	for(int i = 0; i < balls.size(); ++i)
		balls.at(i)->draw(window);

	window->draw(sceneName);
}