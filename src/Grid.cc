#include "Grid.h"

Grid::Grid(int x, int y, int num)
	: x(x), y(y), num(num)
{
}

int Grid::GetX()
{
	return x;
}

int Grid::GetY()
{
	return y;
}

int Grid::GetNum()
{
	return num;
}
