#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Grid
{
	int x;
	int y;

public:
	Grid(int x, int y);
	int GetX();
	int GetY();
	std::string ToString();
};
