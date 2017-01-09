#pragma once
#include "empty_cell.h"
#include "wall_cell.h"
#include "snake_cell.h"
#include "food_cell.h"
#include <vector>
#include <random>
#include <ctime>

class field
{
private:
	std::vector<cell *> f_cells;

	const pair size = pair(10, 10);

	field() {
		srand(time(NULL));
		f_cells = std::vector<cell *>();
	}
	field(const field&);
	field& operator=(field&);

public:

	void push_cell(cell * new_cell) {
		int i, j;
		do {
			i = rand() % (int)size.getA();
			j = rand() % (int)size.getB();
		} while (get_type(i, j) != 0);
		replace(i, j, new_cell);
	}

	void add_cell(cell * new_cell) {
		f_cells.push_back(new_cell);
	}

	static field& getInstance() {
		static field instance;
		return instance;
	}

	void init() {
		for (int i = 0; i < size.getA(); i++) {
			for (int j = 0; j < size.getB(); j++) {
					f_cells.push_back(new empty_cell(i, j));
			}
		}
		push_cell(new food_cell(0, 0));
		push_cell(new wall_cell(0, 0));
	}

	int get_type(int i, int j) {
		const pair acc = pair(i, j);
		for (cell * x : f_cells) {
			if (x->getPos() == acc) return x->get_type();
		}
	}

	cell* operator[](const int index) {
		return f_cells.at(index);
	}

	int get_size() const {
		return f_cells.size();
	}

	void replace(int i, int j, cell * new_cell) {
		const pair acc = pair(i, j);
		for (int i = 0; i < f_cells.size(); i++) {
			if (f_cells.at(i)->getPos() == acc) {
				new_cell->setPos(acc);
				f_cells.at(i) = new_cell;
			}
		}
	}
};