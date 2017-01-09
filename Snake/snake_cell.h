#pragma once
#include "cell.h"

class snake_cell : public cell{
protected:
	
public:
	snake_cell(int x, int y);
	int get_type();
};