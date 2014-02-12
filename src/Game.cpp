#include <Game.hpp>
#include <Scenes.hpp>

Game::Game()
	: currentScene(0)
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Dem PhysX");
	window->setVerticalSyncEnabled(true);

	Scene::windowSize = window->getSize();

	initScenes();
}

Game::~Game()
{
	delete window;
}

// Private
void Game::update(float dt)
{
	scenes.at(currentScene)->update(dt);
}

void Game::draw()
{
	scenes.at(currentScene)->draw(window);
}


void Game::initScenes()
{
	scenes.push_back(new BallDropScene());
}

// Public
void Game::MainLoop()
{
	while (window->isOpen())
    {
		time = clock.restart();
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window->close();
				return; // exit mainloop
			}
        }

        window->clear(sf::Color::White);
		update(time.asSeconds());
		draw();
        window->display();
    }
}