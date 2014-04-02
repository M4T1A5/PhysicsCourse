#include <Game.hpp>
#include <Scenes.hpp>

Game::Game()
	: currentScene(0)
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Dem Physeeks");
	window->setVerticalSyncEnabled(true);

	initScenes();
}

Game::~Game()
{
	delete window;
	for(auto it = scenes.begin(); it != scenes.end(); ++it)
		delete *it;
	scenes.clear();
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

	scenes.push_back(new BallDropScene());
	scenes.push_back(new BallThrowScene());
	scenes.push_back(new BallBounceScene());
	scenes.push_back(new BallCollisionScene());
}

void Game::resetScene()
{
	scenes.at(currentScene)->deinit();
	scenes.at(currentScene)->init();
}

void Game::changeScene(unsigned int scene)
{
	currentScene = scene;

	resetScene();
}

// Public
void Game::MainLoop()
{
	while (window->isOpen())
    {
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
				// Handle keyboard input
				switch(event.key.code)
				{
				case sf::Keyboard::Num1:
				case sf::Keyboard::Numpad1:
					changeScene(0);
					break;
				case sf::Keyboard::Num2:
				case sf::Keyboard::Numpad2:
					changeScene(1);
					break;
				case sf::Keyboard::Num3:
				case sf::Keyboard::Numpad3:
					changeScene(2);
					break;
				case sf::Keyboard::Num4:
				case sf::Keyboard::Numpad4:
					changeScene(3);
					break;
				case sf::Keyboard::R:
					resetScene();
					break;
				default:
					printf("Use keys 1-4 to change scenes\nUse R to reset scene\n");
					break;
				}
			}
        }

        window->clear(sf::Color::White);
		update(clock.restart().asSeconds()); // Update with deltatime
		draw();
        window->display();
    }
}