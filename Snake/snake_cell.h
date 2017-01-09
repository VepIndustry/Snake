#pragma once
#include "cell.h"

class snake_cell : public cell{
public:
	snake_cell(int x, int y);
	int get_type() {
		return 1;
	}
};