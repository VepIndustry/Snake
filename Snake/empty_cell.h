#pragma once
#include "cell.h"

class empty_cell : public cell
{
public:
	empty_cell(int x, int y);
	pair getPos();

	int get_type() {
		return 0;
	}
};
