#include "empty_cell.h"

empty_cell::empty_cell(int x, int y)
{
	psX = x;
	psY = y;
	set_color(WHITE);
}

int empty_cell::get_type()
{
	return 0;
}
