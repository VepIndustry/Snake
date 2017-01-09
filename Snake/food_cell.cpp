#include "food_cell.h"

food_cell::food_cell(int x, int y)
{
	psX = x;
	psY = y;
	set_color(Green);
}

int food_cell::get_type()
{
	return 4;
}
