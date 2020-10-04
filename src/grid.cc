#include "grid.h"

grid::grid(int x, int y)
	: x(x), y(y)
{
}

int grid::get_x()
{
	return x;
}

int grid::get_y()
{
	return y;
}

std::string grid::to_string()
{
	std::ostringstream ostr;
	ostr << "x=" << x << ", y=" << y;
	return ostr.str();
}
