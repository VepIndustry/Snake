#include "game.h"
#include <iostream>

void game::run() {
	pair size = pair(1300, 650);

	sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	sf::Event event;
	window = new sf::RenderWindow(sf::VideoMode(size.getA(), size.getB()), "Mario", sf::Style::Default);

	field & fl = field::getInstance();
	snake sn = snake();
	fl.init_items();

	sn.start(pair(1, 1), pair(1, 3));

	view viewer = view();
	dirs dir = STAY;

	clock_t time = clock();

	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = dir + LEFT == 0 ? dir : LEFT;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = dir + DOWN == 0 ? dir : DOWN;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = dir + RIGHT == 0 ? dir : RIGHT;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = dir + UP == 0 ? dir : UP;

		if (dir != STAY && clock() - time > 200) {
			if (!sn.move(dir)) return;
			time = clock();
		}
		
		viewer.draw(fl, window);
	}
}

game::~game()
{
	delete window;
}
