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
	// Initialize scenes
	void initScenes();
	// Reset current scene
	void resetScene();
	// Go to next scene
	void changeScene(unsigned int scene);
	void update(float deltaTime);
	void draw();
	

	sf::RenderWindow* window;
	sf::Clock clock;

	// Scene management
	std::vector<Scene*> scenes;
	unsigned int currentScene;
};

#endif