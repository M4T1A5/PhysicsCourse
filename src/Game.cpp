#include <Game.hpp>
#include <Scenes.hpp>

Game::Game()
	: currentScene(2)
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Dem PhysX");
	window->setVerticalSyncEnabled(true);

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
	Scene::windowSize = window->getSize();
	Scene::font.loadFromFile("arial.ttf");

	scenes.push_back(new BallDropScene());
	scenes.push_back(new BallThrowScene());
	scenes.push_back(new BallBounceScene());
}

void Game::resetScene()
{
	scenes.at(currentScene)->deinit();
	scenes.at(currentScene)->init();
}

void Game::changeScene()
{
	scenes.at(currentScene)->deinit();
	if (currentScene >= scenes.size() - 1)
		currentScene = 0;
	else
		currentScene++;	

	resetScene();
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
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					changeScene();
				}

				if (event.key.code == sf::Keyboard::R)
				{
					resetScene();
				}
			}
        }

        window->clear(sf::Color::White);
		update(time.asSeconds());
		draw();
        window->display();
    }
}