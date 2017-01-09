#include "field.h"

void field::init()
{
	for (int i = 0; i < size.getA(); i++) {
		for (int j = 0; j < size.getB(); j++) {
			f_cells.push_back(new empty_cell(i, j));
		}
	}
	
}

void field::push_cell(cell * new_cell)
{
	int i, j;
	do {
		i = rand() % (int)size.getA();
		j = rand() % (int)size.getB();
	} while (get_type(i, j) != 0);
	replace(i, j, new_cell);
}

int field::get_type(int i, int j)
{
	const pair acc = pair(i, j);
	for (cell * x : f_cells) {
		if (x->getPos() == acc) return x->get_type();
	}
	return -1;
}

void field::replace(int i, int j, cell * new_cell)
{
	const pair acc = pair(i, j);
	for (int i = 0; i < f_cells.size(); i++) {
		if (f_cells.at(i)->getPos() == acc) {
			new_cell->setPos(acc);
			delete f_cells.at(i);
			f_cells.at(i) = new_cell;
		}
	}
}
