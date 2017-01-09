#pragma once
#include "SFML\Graphics.hpp"
#include "field.h"

class view {
private:
	const pair size_cell = pair(50, 50);
public:
	void draw(field & fl, sf::RenderWindow * win) {
		win->clear();
		int size = fl.get_size();

		for (int i = 0; i < size; i++) {
			sf::RectangleShape rec;
			cell* pos = fl[i];
			rec.setSize(sf::Vector2f(size_cell.getA(), size_cell.getB()));
			rec.setPosition(sf::Vector2f(pos->getPos().getA() * size_cell.getA(), pos->getPos().getB() * size_cell.getB()));
			
			switch (pos->get_type())
			{
			case 0:
				rec.setFillColor(sf::Color::Green);
				break;
			case 1:
				rec.setFillColor(sf::Color::Yellow);
				break;
			case 2:
				rec.setFillColor(sf::Color::Blue);
				break;
			}
			win->draw(rec);

		}
		win->display();
	}
};