#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <Scene.hpp>

class Game
{
public:
	Game();
	~Game();

	void MainLoop();

private:
	void update(float deltaTime);
	void draw();
	

	sf::RenderWindow* window;
	sf::Clock clock;
	sf::Time time;

	std::vector<Scene*> scenes;
	int currentScene;
};

#endif