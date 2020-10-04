#pragma once
#include <iostream>
#include <string>
#include <sstream>

class grid
{
	int x;
	int y;

public:
	grid(int x, int y);
	int get_x();
	int get_y();
	std::string to_string();
};
