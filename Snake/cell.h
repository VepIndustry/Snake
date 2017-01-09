#pragma once
#include "pair.h"

class cell
{
protected:
	int psX = 0, psY = 0;
public:
	pair getPos() {
		return pair(psX, psY);
	}

	void setPos(pair new_pos) {
		psX = new_pos.getA();
		psY = new_pos.getB();
	}

	virtual int get_type() = 0;
};