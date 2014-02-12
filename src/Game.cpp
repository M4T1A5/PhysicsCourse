#include <Game.hpp>

Game::Game()
	: currentScene(0)
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Dem PhysX");
	window->setVerticalSyncEnabled(true);
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

        window->clear();
		update(time.asSeconds());
		draw();
        window->display();
    }
}