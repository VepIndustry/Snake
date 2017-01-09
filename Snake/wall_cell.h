#pragma once
#include "cell.h"

class wall_cell : public cell
{
public:
	wall_cell(int x, int y) {
		psX = x;
		psY = y;
	}
	int get_type() {
		return 2;
	}
};