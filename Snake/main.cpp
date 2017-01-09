#include "field.h"
#include "view.h"
#include "snake.h"
#include <Windows.h>

int main(void) {
	sf::RenderWindow *window;
	pair size = pair(1300, 650);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::Event event;
	window = new sf::RenderWindow(sf::VideoMode(size.getA(), size.getB()), "Mario", sf::Style::Default, settings);

	field & fl = field::getInstance();
	snake sn = snake();
	fl.init();
	sn.start(pair(1, 1), pair(1, 3));

	view viewer = view();

	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}

		int dir = -1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = 1;
		
		

		if (dir != -1) {
			if (!sn.move(dir)) return 1;
			Sleep(100);
		}
		viewer.draw(fl, window);

	}
	return 0;
}