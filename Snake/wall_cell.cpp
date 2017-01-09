#include "wall_cell.h"

wall_cell::wall_cell(int x, int y)
{
	psX = x;
	psY = y;
	set_color(Blue);
}

int wall_cell::get_type()
{
	return 2;
}
