#pragma once
#include "pair.h"

enum colors { GREEN, YELLOW, BLUE, WHITE, RED };

enum dirs { UP, DOWN, LEFT, RIGHT, STAY };

class cell
{
protected:
	
	int psX = 0, psY = 0;
	
	void set_color(colors c);

	colors color;
public:
	colors get_color() { return color; }

	pair getPos() {
		return pair(psX, psY);
	}

	void setPos(pair new_pos) {
		psX = new_pos.getA();
		psY = new_pos.getB();
	}

	virtual int get_type() = 0;
};