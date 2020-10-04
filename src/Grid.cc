#include "Grid.h"

Grid::Grid(int x, int y)
	: x(x), y(y)
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

std::string Grid::ToString()
{
	std::ostringstream ostr;
	ostr << "x=" << x << ", y=" << y;
	return ostr.str();
}
