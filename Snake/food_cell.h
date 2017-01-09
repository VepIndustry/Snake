#pragma once
#include "cell.h"

class food_cell : public cell {
public:
	food_cell(int x, int y);
	int get_type();
};