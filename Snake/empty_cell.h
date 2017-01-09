#pragma once
#include "cell.h"

class empty_cell : public cell
{
public:
	empty_cell(int x, int y);

	int get_type();
};
