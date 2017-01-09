#pragma once
#include "cell.h"

class wall_cell : public cell
{
public:
	wall_cell(int x, int y);
	int get_type();
};