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


	void init();
	field() : f_cells(std::vector<cell *>()){
		srand(time(NULL));
		init();
	}
	field(const field&);
	field& operator=(field&);

public:

	void push_cell(cell * new_cell);

	void add_cell(cell * new_cell) {
		f_cells.push_back(new_cell);
	}

	static field& getInstance() {
		static field instance;
		return instance;
	}

	int get_type(int i, int j);

	cell* operator[](const int index) {
		return f_cells.at(index);
	}

	int get_size() const {
		return f_cells.size();
	}

	void replace(int i, int j, cell * new_cell);

	~field() {
		for (cell * x : f_cells) {
			delete x;
		}
	}
};