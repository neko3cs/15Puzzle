#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Grid
{
private:
	int x;
	int y;
	int num;

public:
	Grid(int x, int y, int num);
	int GetX();
	int GetY();
	int GetNum();
	std::string ToString();
};
