#include "Panel.h"

Panel::Panel(Grid grid)
	: grid(grid)
{
}

Grid Panel::GetGrid()
{
	return grid;
}
