#pragma once
#include "field.h"
#include "view.h"
#include "snake.h"
#include <Windows.h>

class game {
	sf::RenderWindow *window;
public:
	void run();

	~game();
};