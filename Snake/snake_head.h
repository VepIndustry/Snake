#pragma once
#include "snake_cell.h"

class snake_head : public snake_cell
{
public:
	snake_head(int x, int y) : snake_cell(x, y) {
		set_color(RED);
	}
};