#include "Panel.h"

Panel::Panel(Grid grid)
	: grid(grid)
{
}

Grid Panel::GetGrid()
{
	return grid;
}

bool Panel::IsHidden()
{
	return grid.GetNum() == 1 ? true : false;
}
