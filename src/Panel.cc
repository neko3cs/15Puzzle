#include "Panel.h"

Panel::Panel(Grid grid)
	: grid(grid)
{
}

std::string Panel::ToString()
{
	// TODO: いずれは画像を返す
	return this->IsHidden() ? "■" : std::to_string(grid.GetNum());
}

bool Panel::IsHidden()
{
	return grid.GetNum() == 1 ? true : false;
}
