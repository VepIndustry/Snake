#pragma once
#include <list>
#include "field.h"

class snake
{
private:
	std::list<snake_cell *> c_snake = std::list<snake_cell *>();

public:
	bool move(dirs dir) {
		field & f = field::getInstance();
		snake_cell * end = c_snake.back();		
		
		pair pos = pair(0,0);
		switch (dir) {
		case LEFT:
			pos += pair(-1, 0);
			break;
		case DOWN:
			pos += pair(0, -1);
			break;
		case RIGHT:
			pos += pair(1, 0);
			break;
		case UP:
			pos += pair(0, 1);
			break;
		}

		cell * second = c_snake.front();
		pair new_coor = second->getPos() + pos;
		
		if (f.get_type(new_coor.getA(), new_coor.getB()) != 0 && f.get_type(new_coor.getA(), new_coor.getB()) != 4) return false;

		if (f.get_type(new_coor.getA(), new_coor.getB()) == 4) {
			field::getInstance().push_cell(new food_cell(0, 0));
		}
		
		else if (f.get_type(new_coor.getA(), new_coor.getB()) != 4) {
			c_snake.pop_back();
			f.replace(end->getPos().getA(), end->getPos().getB(), new empty_cell(end->getPos().getA(), end->getPos().getB()));
			delete end;
		}
		
		f.replace(new_coor.getA(), new_coor.getB(), new snake_cell(new_coor.getA(), new_coor.getB()));
		c_snake.push_front(new snake_cell(new_coor.getA(), new_coor.getB()));
		return true;
	}

	void start(pair from, pair to) {
		field & f = field::getInstance();

		for (int i = from.getA(); i < to.getA() + 1; i++) {
			for (int j = from.getB(); j < to.getB() + 1; j++) {
				c_snake.push_back(new snake_cell(i, j));
				f.replace(i , j, new snake_cell(i, j));
			}
		}
	}

	~snake() {
		for (cell * x : c_snake) {
			delete x;
		}
	}
};