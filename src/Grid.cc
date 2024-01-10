#include "Grid.h"

Grid::Grid(int x, int y, int num)
		: x(x), y(y), num(num)
{
}

int Grid::GetX()
{
	return x;
}

void Grid::SetX(int x)
{
	this->x = x;
}

int Grid::GetY()
{
	return y;
}

void Grid::SetY(int y)
{
	this->y = y;
}

int Grid::GetNum()
{
	return num;
}
