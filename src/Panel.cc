#include "Panel.h"

Panel::Panel(Grid grid)
	: grid(grid)
{
}

std::string Panel::ToString()
{
	// TODO: いずれは画像を返す
	return IsHidden() ? "■ " : std::to_string(grid.GetNum());
}

Grid Panel::GetGrid()
{
	return grid;
}

bool Panel::IsHidden()
{
	return grid.GetNum() == HIDDEN_NUM ? true : false;
}
