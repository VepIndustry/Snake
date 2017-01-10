#pragma once
#include "SFML\Graphics.hpp"
#include "field.h"

class view {
private:
	const pair size_cell = pair(10, 10);
public:
	void draw(field & fl, sf::RenderWindow * win) {
		win->clear();
		int size = fl.get_size();

		for (int i = 0; i < size; i++) {
			sf::RectangleShape rec;
			cell* pos = fl[i];
			rec.setSize(sf::Vector2f(size_cell.getA(), size_cell.getB()));
			rec.setPosition(sf::Vector2f((1 + pos->getPos().getA()) * size_cell.getA(), win->getSize().y - (2+pos->getPos().getB()) * size_cell.getB()));
			
			switch (pos->get_color())
			{
			case GREEN:
				rec.setFillColor(sf::Color::Green);
				break;
			case YELLOW:
				rec.setFillColor(sf::Color::Yellow);
				break;
			case BLUE:
				rec.setFillColor(sf::Color::Blue);
				break;
			case WHITE:
				rec.setFillColor(sf::Color::White);
				break;
			case RED:
				rec.setFillColor(sf::Color::Red);
				break;
			}
			win->draw(rec);

		}
		win->display();
	}
};