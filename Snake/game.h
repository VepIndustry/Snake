#pragma once
#include "field.h"
#include "view.h"
#include "snake.h"
#include <Windows.h>

class game {
public:
	void run() {
		sf::RenderWindow *window;
		pair size = pair(1300, 650);

		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::Event event;
		window = new sf::RenderWindow(sf::VideoMode(size.getA(), size.getB()), "Mario", sf::Style::Default, settings);

		field & fl = field::getInstance();
		snake sn = snake();

		sn.start(pair(1, 1), pair(1, 3));

		view viewer = view();

		while (window->isOpen()) {
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window->close();
			}

			dirs dir = Stay;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = Left;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = Down;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = Right;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = Up;

			if (dir != Stay) {
				if (!sn.move(dir)) return;
				Sleep(100);
			}
			viewer.draw(fl, window);

		}
	}
};