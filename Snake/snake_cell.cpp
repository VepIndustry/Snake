#include "snake_cell.h"



snake_cell::snake_cell(int x, int y)
{
	psX = x;
	psY = y;
	set_color(YELLOW);
}

int snake_cell::get_type()
{
	return 1;
}
